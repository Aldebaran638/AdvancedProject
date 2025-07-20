package com.zeroone.star.systemmanage.service.impl;

import com.baomidou.mybatisplus.core.conditions.query.QueryWrapper;
import com.baomidou.mybatisplus.extension.plugins.pagination.Page;
import com.baomidou.mybatisplus.extension.service.impl.ServiceImpl;
import com.zeroone.star.project.components.user.UserHolder;
import com.zeroone.star.project.dto.PageDTO;
import com.zeroone.star.project.dto.j3.systemmanage.initcommunity.InitializedCommunityDTO;
import com.zeroone.star.project.query.j3.systemmanage.initcommunity.InitializedCommunityPageQuery;
import com.zeroone.star.project.vo.JsonVO;
import com.zeroone.star.systemmanage.entity.*;
import com.zeroone.star.systemmanage.mapper.*;
import com.zeroone.star.systemmanage.service.IInitCommunityService;
import lombok.SneakyThrows;
import org.apache.commons.codec.digest.DigestUtils;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.data.redis.core.StringRedisTemplate;
import org.springframework.stereotype.Service;
import org.springframework.transaction.annotation.Transactional;
import org.springframework.util.StringUtils;

import java.util.ArrayList;
import java.util.List;
import java.util.concurrent.TimeUnit;

@Service
public class IInitCommunityServiceImpl extends ServiceImpl<InitCommunityMapper, SCommunityDO> implements IInitCommunityService {

    @Autowired
    InitCommunityMapper mapper;

    @Autowired
    UserMapper userMapper;
    @Autowired
    FloorMapper floorMapper;
    @Autowired
    BuildingUnitMapper buildingUnitMapper;
    @Autowired
    BuildingRoomMapper buildingRoomMapper;
    @Autowired
    BuildingOwnerRoomRelMapper buildingOwnerRoomRelMapper;
    @Autowired
    BuildingOwnerMapper buildingOwnerMapper;
    @Autowired
    OwnerAppUserMapper ownerAppUserMapper;
    @Autowired
    AccountMapper accountMapper;
    @Autowired
    PayFeeMapper payFeeMapper;
    @Autowired
    ReportOweFeeMapper reportOweFeeMapper;
    @Autowired
    PayFeeDetailMapper payFeeDetailMapper;
    @Autowired
    PayFeeDetailMonthMapper payFeeDetailMonthMapper;
    @Autowired
    ParkingAreaMapper parkingAreaMapper;
    @Autowired
    ParkingSpaceMapper parkingSpaceMapper;
    @Autowired
    OwnerCarMapper ownerCarMapper;
    @Autowired
    private StringRedisTemplate stringRedisTemplate;

    //用于获取用户id
    @Autowired
    UserHolder userHolder;

    //md5加盐秘钥
    public final static String PASSWD_SALT = "hc@java110";

    //@Resource
    //MsSCommunityMapper ms;

    /**
     * 查询所有小区数据
     *
     * @param query
     * @return
     */
    @SneakyThrows
    public JsonVO<PageDTO<InitializedCommunityDTO>> listAll(InitializedCommunityPageQuery query) {
        Page<SCommunityDO> page = new Page(query.getPageIndex(), query.getPageSize());

        //设置查询条件
        QueryWrapper<SCommunityDO> wrapper = new QueryWrapper<>();
        wrapper.eq(!StringUtils.isEmpty(query.getCommunityId()), "community_id", query.getCommunityId());
        wrapper.like(!StringUtils.isEmpty(query.getName()), "name", query.getName());

        //得到pageList,并转换为需要响应的pageDTO
        Page<SCommunityDO> pageList = baseMapper.selectPage(page, wrapper);

        //查询不到数据时报错
        if (pageList == null || pageList.getTotal() == 0) {
            return JsonVO.create(null,9999,"查询不到数据");
        }
        //Page<SCommunity> pageList = mapper.queryList(query);
        //List<SCommunity> list = mapper.queryList(query);
        PageDTO<InitializedCommunityDTO> pageDTO = new PageDTO<>();
        //BeanUtils.copyProperties(pageDTO, pageList);
        //Long count = mapper.selectCount(wrapper);
        //pageDTO.setTotal(count);
        //long pages = count / page.getSize() == 0 ? count / page.getSize() : count / page.getSize() + 1;
        //pageDTO.setPages(pages);
        List<InitializedCommunityDTO> rows = new ArrayList<>();
        for (SCommunityDO record : pageList.getRecords()) {
            InitializedCommunityDTO dto = new InitializedCommunityDTO();
            dto.setCommunityId(record.getCommunityId());
            dto.setName(record.getName());
            dto.setCityCode(record.getCityCode());
            String state = record.getState();
            dto.setState(state);
            dto.setNearbyLandmarks(record.getNearbyLandmarks());
            dto.setStateText(state.equals("1100") ? InitializedCommunityDTO.REVIEW_COMPLETED :
                    state.equals("1000") ? InitializedCommunityDTO.AWAITING_REVIEW : InitializedCommunityDTO.REVIEW_REJECTED);
            rows.add(dto);
        }
        pageDTO.setRows(rows);
        pageDTO.setPageIndex(query.getPageIndex());
        pageDTO.setPageSize(query.getPageSize());
        pageDTO.setPages(pageList.getPages());
        pageDTO.setTotal(pageList.getTotal());
        //return PageDTO.create(pageList, src -> ms.SCommunityToDto(src));
        //判断请求页码是否超过总页数
        System.out.println(pageDTO.getPageIndex()+"==========="+pageDTO.getPages());
        if (pageDTO.getPageIndex() < 1 || pageDTO.getPages() < pageDTO.getPageIndex()) {
            return JsonVO.create(null,9999,"请求页码错误");
        }

        return JsonVO.success(pageDTO);
    }

    /**
     * 格式化小区数据
     *
     * @param communityId
     * @param password
     * @return
     */
    //@SneakyThrows
    @SneakyThrows
    @Transactional(rollbackFor = Exception.class)
    public JsonVO<String> removeData(String communityId, String password) {
        //通过userHolder获取当前用户id
        //String userId = userHolder.getCurrentUser().getId();
        String userId = String.valueOf(userHolder.getCurrentUser().getId());

        //判断缓存中是否有userId
        String pwd = stringRedisTemplate.opsForValue().get(userId+PASSWD_SALT);
        if (StringUtils.isEmpty(pwd) || !pwd.equals(password)) {
            //根据传入uID和pwd判断是否格式化
            QueryWrapper<User> userQueryWrapper = new QueryWrapper<>();
            userQueryWrapper.eq("user_id", userId);
            User user = userMapper.selectOne(userQueryWrapper);
            //进行两次md5加密
            String md5Pwd = DigestUtils.md5Hex(DigestUtils.md5Hex((password + PASSWD_SALT).getBytes("UTF-8")));
            if (user == null) {
                return JsonVO.fail("没有查到用户信息，初始化失败！");
            } else if (!user.getPassword().equals(md5Pwd)) {
                return JsonVO.fail("初始化时输入的密码不正确，初始化失败！");
            } else {
                //设置30分钟过期
                stringRedisTemplate.opsForValue().set(userId+PASSWD_SALT, password,60 * 30, TimeUnit.SECONDS);
            }
            System.out.println("========未通过缓存==========");
        } else {
            System.out.println("========通过缓存==========");
        }

        //stringBuffer来存放格式化提示字符串
        StringBuffer message = new StringBuffer();

        //判断community_id是否存在
        SCommunityDO sCommunityDO = mapper.selectById(communityId);
        if (sCommunityDO == null) {
            message.append("community_id不存在");
            return JsonVO.fail(message.toString());
        }

        //根据CID查询f_floor表的floor_id
        QueryWrapper<FloorDO> floorQueryWrapper = new QueryWrapper<FloorDO>().eq("community_id", communityId);
        List<FloorDO> floorDOList = floorMapper.selectList(floorQueryWrapper);
        List<String> floorIds = new ArrayList<>();
        for (FloorDO floorDO : floorDOList) {
            floorIds.add(floorDO.getFloorId());
            //System.out.println(floor.getFloorId());
        }

        //根据floor_id(集合),在building_unit表中删除对应数据
        int communitys = 0;
        if (floorIds.size() > 0) {
            QueryWrapper<BuildingUnitDO> buildingUnitQueryWrapper = new QueryWrapper<>();
            buildingUnitQueryWrapper.in("floor_id", floorIds);
            //List<BuildingUnit> buildingUnitList = buildingUnitMapper.selectList(buildingUnitQueryWrapper);
            //buildingUnitList.forEach(buildingUnit -> {
            //    System.out.println(buildingUnit);
            //});
            message.append("开始格式化小区数据：");
            communitys = buildingUnitMapper.delete(buildingUnitQueryWrapper);
        }
        message.append("单元初始化完成，清理数据【" + communitys + "】条！");

        //跟据communityId直接删除f_floor中的数据
        int deleteFlag = floorMapper.delete(floorQueryWrapper);
        message.append("楼栋初始化完成，清理数据【" + deleteFlag + "】条！");

        //根据Cid从building_room表中查出room_id
        QueryWrapper<BuildingRoomDO> buildingRoomQueryWrapper = new QueryWrapper<>();
        buildingRoomQueryWrapper.eq("community_id", communityId);
        List<BuildingRoomDO> buildingRoomDOList = buildingRoomMapper.selectList(buildingRoomQueryWrapper);
        ArrayList<String> roomIds = new ArrayList<>();
        for (BuildingRoomDO buildingRoomDO : buildingRoomDOList) {
            roomIds.add(buildingRoomDO.getRoomId());
            System.out.println(buildingRoomDO.getRoomId());
        }

        //根据roomIds删除building_owner_room_rel表中对应数据
        if (roomIds.size() > 0) {
            QueryWrapper<BuildingOwnerRoomRelDO> buildingOwnerRoomRelQueryWrapper =
                    new QueryWrapper<BuildingOwnerRoomRelDO>().in("room_id", roomIds);
            buildingOwnerRoomRelMapper.delete(buildingOwnerRoomRelQueryWrapper);
        }

        //根据Cid删除building_room表中的数据，并加入message
        int deleteFlagRoot = buildingRoomMapper.delete(buildingRoomQueryWrapper);
        message.append("房屋初始化完成，清理数据【" + deleteFlagRoot + "】条！");

        //根据CID删除building_owner对应表数据
        QueryWrapper<BuildingOwnerDO> buildingOwnerQueryWrapper = new QueryWrapper<>();
        buildingOwnerQueryWrapper.eq("community_id", communityId);
        int deleteFlagOwner = buildingOwnerMapper.delete(buildingOwnerQueryWrapper);

        //根据CID查询ownerAppUser得到UIDs
        QueryWrapper<OwnerAppUserDO> ownerAppUserQueryWrapper = new QueryWrapper<OwnerAppUserDO>();
        ownerAppUserQueryWrapper.eq("community_id", communityId);
        List<OwnerAppUserDO> ownerAppUserDOS = ownerAppUserMapper.selectList(ownerAppUserQueryWrapper);
        ArrayList<String> userIds = new ArrayList<>();
        for (OwnerAppUserDO ownerAppUserDO : ownerAppUserDOS) {
            userIds.add(ownerAppUserDO.getUserId());
        }

        //根据UID删除user表对应数据
        if (userIds.size() > 0) {
            QueryWrapper userQueryWrapper = new QueryWrapper<User>().in("user_id", userIds);
            userMapper.delete(userQueryWrapper);
        }

        //根据CID删除ownerAppUser，和Account表对应数据
        ownerAppUserMapper.delete(ownerAppUserQueryWrapper);
        QueryWrapper<AccountDO> accountQueryWrapper = new QueryWrapper<>();
        accountQueryWrapper.eq("part_id", communityId);
        accountMapper.delete(accountQueryWrapper);

        //加入信息到message
        message.append("业主初始化完成，清理数据【" + deleteFlagOwner + "】条！");

        //根据CID删除PayFee，PayFeeDetail，ReportOweFee，PayFeeDetailMonth
        QueryWrapper<PayFeeDO> payFeeQueryWrapper = new QueryWrapper<>();
        QueryWrapper<ReportOweFeeDO> reportOweFeeQueryWrapper = new QueryWrapper<>();
        QueryWrapper<PayFeeDetailDO> payFeeDetailQueryWrapper = new QueryWrapper<>();
        QueryWrapper<PayFeeDetailMonthDO> payFeeDetailMonthQueryWrapper = new QueryWrapper<>();
        payFeeQueryWrapper.eq("community_id", communityId);
        reportOweFeeQueryWrapper.eq("community_id", communityId);
        payFeeDetailQueryWrapper.eq("community_id", communityId);
        payFeeDetailMonthQueryWrapper.eq("community_id", communityId);
        int deleteFlagFee = payFeeMapper.delete(payFeeQueryWrapper);
        reportOweFeeMapper.delete(reportOweFeeQueryWrapper);
        payFeeDetailMapper.delete(payFeeDetailQueryWrapper);
        payFeeDetailMonthMapper.delete(payFeeDetailMonthQueryWrapper);

        //添加信息到message
        message.append("费用初始化完成，清理数据【" + deleteFlagFee + "】条！");

        //ParkingArea,ParkingSpace,OwnerCar格式化
        QueryWrapper<ParkingAreaDO> parkingAreaQueryWrapper = new QueryWrapper<>();
        parkingAreaQueryWrapper.eq("community_id", communityId);
        int deleteFlagArea = parkingAreaMapper.delete(parkingAreaQueryWrapper);
        message.append("停车场初始化完成，清理数据【" + deleteFlagArea + "】条！");
        QueryWrapper<ParkingSpaceDO> parkingSpaceQueryWrapper = new QueryWrapper<>();
        parkingSpaceQueryWrapper.eq("community_id", communityId);
        int deleteFlagSpace = parkingSpaceMapper.delete(parkingSpaceQueryWrapper);
        message.append("停车位初始化完成，清理数据【" + deleteFlagSpace + "】条！");
        QueryWrapper<OwnerCarDO> ownerCarQueryWrapper = new QueryWrapper<>();
        ownerCarQueryWrapper.eq("community_id", communityId);
        int deleteFlagCar = ownerCarMapper.delete(ownerCarQueryWrapper);
        message.append("车辆初始化完成，清理数据【" + deleteFlagCar + "】条！");


        return JsonVO.success(message.toString());
    }
}

