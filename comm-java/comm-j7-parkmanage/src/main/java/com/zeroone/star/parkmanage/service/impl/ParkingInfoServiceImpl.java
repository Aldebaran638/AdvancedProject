package com.zeroone.star.parkmanage.service.impl;

import cn.hutool.core.bean.BeanUtil;
import cn.hutool.core.util.ObjectUtil;
import com.baomidou.mybatisplus.core.conditions.query.QueryWrapper;
import com.baomidou.mybatisplus.extension.plugins.pagination.Page;
import com.baomidou.mybatisplus.extension.service.impl.ServiceImpl;
import com.zeroone.star.parkmanage.entity.ParkingArea;
import com.zeroone.star.parkmanage.entity.ParkingSpace;
import com.zeroone.star.parkmanage.mapper.ParkingLotManageMapper;
import com.zeroone.star.parkmanage.mapper.ParkingSpaceMapper;
import com.zeroone.star.parkmanage.service.IParkingInfoService;
import com.zeroone.star.project.components.user.UserHolder;
import com.zeroone.star.project.dto.PageDTO;
import com.zeroone.star.project.dto.j7.parkmanage.parkinginfo.BatchAddParkingSpacesDTO;
import com.zeroone.star.project.dto.j7.parkmanage.parkinginfo.GetParkingSpaceDTO;
import com.zeroone.star.project.dto.j7.parkmanage.parkinginfo.ParkingSpaceDTO;
import com.zeroone.star.project.dto.j7.parkmanage.parkinglotmanage.GetParkingLotDTO;
import com.zeroone.star.project.query.j7.parkmanage.parkinginfo.ParkingInfoQuery;
import lombok.RequiredArgsConstructor;
import lombok.extern.slf4j.Slf4j;
import org.springframework.stereotype.Service;
import org.springframework.util.StringUtils;

import javax.annotation.Resource;
import java.math.BigDecimal;
import java.util.ArrayList;
import java.util.List;

/**
 * 车位服务层实现
 * @author LiZhiHan
 * @date 2025.05.25
 */
@Service
@RequiredArgsConstructor
@Slf4j
public class ParkingInfoServiceImpl extends ServiceImpl<ParkingSpaceMapper, ParkingSpace> implements IParkingInfoService {

    private final ParkingSpaceMapper parkingSpaceMapper;

    private final MsParkingSpaceMapper msParkingSpaceMapper;

    private final ParkingLotManageMapper parkingLotManageMapper;

    /**
     * 保存车位信息
     *
     * @param parkingSpaceDTO 车位信息传输对象
     */
    @Override
    public void save(ParkingSpaceDTO parkingSpaceDTO) {
        if (ObjectUtil.isNull(parkingSpaceDTO)) {
            log.error("车位信息不能为空");
            throw new RuntimeException("车位信息不能为空");
        }
        log.info("保存车位信息：{}", parkingSpaceDTO);
        // 防止透传
        parkingSpaceDTO.setPsId(null);
        ParkingSpace saveDo = BeanUtil.copyProperties(parkingSpaceDTO, ParkingSpace.class);
        // 默认车位状态为空闲
        saveDo.setState("F");
        if (parkingSpaceMapper.insert(saveDo) < 1) {
            log.error("保存车位失败: {}", parkingSpaceDTO);
            throw new RuntimeException("保存车位失败");
        }
    }

    /**
     * 更新车位信息
     *
     * @param parkingSpaceDTO 车位信息传输对象
     */
    @Override
    public void update(ParkingSpaceDTO parkingSpaceDTO) {
        if (ObjectUtil.isNull(parkingSpaceDTO)) {
            log.error("车位信息不能为空");
            throw new RuntimeException("车位信息不能为空");
        }
        log.info("修改车位信息: {}", parkingSpaceDTO);
        // 判断存不存在
        ParkingSpace parkingSpace = parkingSpaceMapper.selectById(parkingSpaceDTO.getPsId());
        if (ObjectUtil.isNull(parkingSpace)) {
            log.error("车位信息不存在, 修改失败: {}", parkingSpaceDTO);
            throw new RuntimeException("车位信息不存在, 修改失败");
        }

        if (parkingSpaceMapper.updateById(getParkingSpaceDo(parkingSpaceDTO)) < 1) {
            log.error("修改车位信息失败: {}", parkingSpaceDTO);
            throw new RuntimeException("修改车位信息失败");
        }
    }

    private static ParkingSpace getParkingSpaceDo(ParkingSpaceDTO parkingSpaceDTO) {
        // 车位编码和车位类型不能修改
        parkingSpaceDTO.setNum(null);
        parkingSpaceDTO.setParkingType(null);
        return BeanUtil.copyProperties(parkingSpaceDTO, ParkingSpace.class);
    }

    /**
     * 删除车位信息
     *
     * @param psId 停车位信息ID
     */
    @Override
    public void remove(Long psId) {
        // 判断存不存在
        ParkingSpace parkingSpace = parkingSpaceMapper.selectById(psId);
        if (ObjectUtil.isNull(parkingSpace)) {
            log.info("车位信息不存在, 没有进行删除操作, 直接返回: {}", psId);
            return;
        }
        if (parkingSpaceMapper.deleteById(psId) < 1) {
            log.error("删除车位信息失败: {}", psId);
        }
    }

    /**
     * 分页查询车位信息
     * @param query 查询参数
     * @return 车位信息
     */
    @Override
    public PageDTO<GetParkingSpaceDTO> listParkingSpace(ParkingInfoQuery query) {

        // 构建分页查询对象
        Page<ParkingSpace> page = new Page<>(query.getPageIndex(), query.getPageSize());
        // 构建查询条件
        //TODO 获取停车场编号
        QueryWrapper<ParkingSpace> wrapper = new QueryWrapper<>();
        wrapper.eq(!StringUtils.isEmpty(query.getPaId()),"pa_id",query.getPaId());
        wrapper.like(!StringUtils.isEmpty(query.getNum()),"num",query.getNum());
        wrapper.eq(!StringUtils.isEmpty(query.getState()),"state",query.getState());
        wrapper.eq(!StringUtils.isEmpty(query.getPsId()),"ps_id",query.getPsId());
        wrapper.eq("status_cd","0");
        wrapper.orderBy(true,false,"create_time");
        wrapper.orderBy(true,false,"ps_id");
        // 查询数据

        Page<ParkingSpace> pageResult = parkingSpaceMapper.selectPage(page, wrapper);
        List<ParkingSpace> records = pageResult.getRecords();
        List<GetParkingSpaceDTO> getParkingSpaceDTOList = new ArrayList<>();

        for (ParkingSpace parkingSpace : records) {
            // 获取停车场名称
            ParkingArea parkingArea = parkingLotManageMapper.selectById(parkingSpace.getPaId());
            if(ObjectUtil.isNull(parkingArea)){
                log.error("停车场信息不存在, 直接返回");
                continue;
            }
            String name = parkingArea.getNum();

            GetParkingSpaceDTO getParkingSpaceDTO = msParkingSpaceMapper.GetParkingSpaceToDTO(parkingSpace);
            getParkingSpaceDTO.setPaNum(name);

            getParkingSpaceDTOList.add(getParkingSpaceDTO);
        }


        PageDTO<GetParkingSpaceDTO> pageDTO=new PageDTO<>();
        pageDTO.setPageIndex(page.getCurrent());
        pageDTO.setPageSize(page.getSize());
        pageDTO.setPages(page.getPages());
        pageDTO.setTotal(page.getTotal());
        pageDTO.setRows(getParkingSpaceDTOList);
        return pageDTO;
    }

    /**
     * 批量添加车位信息
     * @param batchAddParkingSpacesDTO
     */
    @Override
    public String saveBatch(BatchAddParkingSpacesDTO batchAddParkingSpacesDTO) {
        if(ObjectUtil.isNull(baseMapper.selectById(batchAddParkingSpacesDTO.getPaId()))){
            log.error("停车场信息不存在, 没有进行添加操作, 直接返回");
            return "停车场信息不存在";
        }
        Integer begin = batchAddParkingSpacesDTO.getStartNumber();
        Integer end = batchAddParkingSpacesDTO.getEndNumber();
        String str = "";
        if(batchAddParkingSpacesDTO.getNumberPrefix() != null){
            str=batchAddParkingSpacesDTO.getNumberPrefix();
        }

        List <ParkingSpace> list = new ArrayList<>();
        for (int i = begin; i <=end ; i++) {
            ParkingSpace parkingSpace = new ParkingSpace();

            parkingSpace.setNum(str+i);
            parkingSpace.setPaId(batchAddParkingSpacesDTO.getPaId());
            parkingSpace.setParkingType(batchAddParkingSpacesDTO.getParkingType());
            // TODO 默认设置小区ID
            parkingSpace.setCommunityId("");
            parkingSpace.setState("F");
            parkingSpace.setRemark("");
            parkingSpace.setArea(BigDecimal.valueOf(1.00));
            list.add(0,parkingSpace);

        }
        // 批量保存
        saveBatch(list);

        return "添加成功";
    }
}