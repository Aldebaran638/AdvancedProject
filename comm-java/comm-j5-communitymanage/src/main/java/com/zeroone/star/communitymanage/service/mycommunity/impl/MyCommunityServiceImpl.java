package com.zeroone.star.communitymanage.service.mycommunity.impl;


import com.baomidou.mybatisplus.core.conditions.query.LambdaQueryWrapper;
import com.baomidou.mybatisplus.core.metadata.IPage;
import com.baomidou.mybatisplus.extension.plugins.pagination.Page;
import com.baomidou.mybatisplus.extension.service.impl.ServiceImpl;

import com.zeroone.star.communitymanage.entity.mycommunity.SCommunity;
import com.zeroone.star.communitymanage.entity.mycommunity.SStore;
import com.zeroone.star.communitymanage.entity.mycommunity.User;
import com.zeroone.star.communitymanage.mapper.mycommunity.hc.MyCommunityMapper;
import com.zeroone.star.communitymanage.mapper.mycommunity.tt.SStoreMapper;
import com.zeroone.star.communitymanage.mapper.mycommunity.tt.UserMapper;
import com.zeroone.star.communitymanage.service.mycommunity.MyCommunityService;
import com.zeroone.star.project.components.user.UserDTO;
import com.zeroone.star.project.components.user.UserHolder;
import com.zeroone.star.project.dto.PageDTO;
import com.zeroone.star.project.dto.j5.community.mycommunity.MyCommunityDTO;
import com.zeroone.star.project.query.j5.community.mycommunity.AllMyCommunityQuery;
import com.zeroone.star.project.query.j5.community.mycommunity.MyCommunityQuery;
import com.zeroone.star.project.vo.j5.community.mycommunity.AllMyCommunityVO;
import com.zeroone.star.project.vo.j5.community.mycommunity.MyCommunityVO;
import lombok.RequiredArgsConstructor;
import org.springframework.beans.BeanUtils;
import org.springframework.stereotype.Service;

import java.util.List;
import java.util.stream.Collectors;

@Service
@RequiredArgsConstructor
public class MyCommunityServiceImpl extends ServiceImpl<MyCommunityMapper, SCommunity> implements MyCommunityService {
    private final MyCommunityMapper myCommunityMapper;
    private final SStoreMapper sStoreMapper;
    private final UserHolder userHolder;
    private final UserMapper userMapper;

    /**
     * 根据小区id查询我的小区信息
     * @param query 查询条件
     * @return 我的小区数据展示模型
     */
    @Override
    public PageDTO<MyCommunityVO> getMyCommunity(MyCommunityQuery query) {
        //根据当前登录用户获取该用户所有的商户id
        List<String> storeIds = listStroeIdsByUserId();
        if(storeIds == null || storeIds.isEmpty()){
            throw new RuntimeException("该用户的商户数据为空");
        }
        //设置分页参数
        Page<MyCommunityVO> page = new Page<>(query.getPageIndex(), query.getPageSize());
        //根据商户id和小区id从hc_community数据库中查找vo数据
        IPage<MyCommunityVO> myCommunityPage = myCommunityMapper.selectMyCommunity(page,query.getCommunityId(), storeIds);

        return PageDTO.create((Page<MyCommunityVO>) myCommunityPage);
    }

    /**
     * 修改入驻小区
     * @param myCommunityDTO 修改我的小区数据模型
     * @return 修改结果
     */
    @Override
    public boolean updateMyCommunity(MyCommunityDTO myCommunityDTO) {
        SCommunity sCommunity = new SCommunity();
        BeanUtils.copyProperties(myCommunityDTO,sCommunity);
        return updateById(sCommunity);
    }

    /**
     * 根据当前登录用户查询所有我的小区信息
     * @param query 查询我的所有小区信息的参数
     * @return 我的所有小区数据展示模型
     */
    @Override
    public PageDTO<AllMyCommunityVO> listMyCommunity(AllMyCommunityQuery query){
        //根据当前登录用户获取该用户所有的商户id
        List<String> storeIds = listStroeIdsByUserId();
        if(storeIds == null || storeIds.isEmpty()){
            throw new RuntimeException("该用户的商户数据为空");
        }
        //设置分页参数
        Page<AllMyCommunityVO> page = new Page<>(query.getPageIndex(), query.getPageSize());
        //根据商户id从hc_community数据库中查找vo数据
        IPage<AllMyCommunityVO> allMyCommunityPage = myCommunityMapper.selectAllMyCommunity(page,query.getName(),storeIds);
        return PageDTO.create((Page<AllMyCommunityVO>) allMyCommunityPage);
    }

    /**
     * 根据当前登录用户获取该用户所有的商户id
     * @return
     */
    private List<String> listStroeIdsByUserId(){
        //获取当前登录用户的用户id
        String userId = null;
        try {
            UserDTO currentUser = userHolder.getCurrentUser();
            if(currentUser == null){
                throw new IllegalArgumentException("为获取到当前登录用户信息");
            }
            //根据主键id从tt数据库中的u_user表查询用户id
            User user = userMapper.selectById(currentUser.getId());
            userId = user.getUserId();
        } catch (Exception e) {
            throw new RuntimeException(e);
        }

        //从tt数据库中的s_store表中根据用户id查询商户id,暂时写死
        LambdaQueryWrapper<SStore> wrapper = new LambdaQueryWrapper<SStore>()
                .eq(SStore::getUserId, userId);
        List<SStore> sStores = sStoreMapper.selectList(wrapper);
        List<String> storeIds = sStores.stream().map(SStore::getStoreId).collect(Collectors.toList());

        return storeIds;
    }

}
