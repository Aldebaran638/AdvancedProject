package com.zeroone.star.orgmanager.service.impl;

import com.baomidou.mybatisplus.core.conditions.query.QueryWrapper;
import com.baomidou.mybatisplus.core.toolkit.StringUtils;
import com.baomidou.mybatisplus.extension.plugins.pagination.Page;
import com.zeroone.star.orgmanager.entity.SCommunity;
import com.zeroone.star.orgmanager.mapper.SCommunityMapper;
import com.zeroone.star.project.components.user.UserDTO;
import com.zeroone.star.project.components.user.UserHolder;
import com.zeroone.star.project.dto.PageDTO;
import com.zeroone.star.orgmanager.entity.URoleCommunity;
import com.zeroone.star.orgmanager.mapper.URoleCommunityMapper;
import com.zeroone.star.orgmanager.service.IURoleCommunityService;
import com.baomidou.mybatisplus.extension.service.impl.ServiceImpl;
import com.zeroone.star.project.query.j2.orgmanager.rolePermission.GetAssociatedRoleCommunitiesQuery;
import com.zeroone.star.project.dto.j2.orgmanager.rolePermission.AssociatedRoleCommunityDTO;
import com.zeroone.star.project.dto.j2.orgmanager.rolePermission.UnassociatedRoleCommunityDTO;
import com.zeroone.star.project.query.j2.orgmanager.rolePermission.GetUnassociatedRoleCommunitiesQuery;
import com.zeroone.star.project.query.j2.orgmanager.rolePermission.PostRoleCommunityQuery;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Service;

import javax.annotation.Resource;
import java.util.List;
import java.util.Map;
import java.util.function.Function;
import java.util.stream.Collectors;

/**
 * <p>
 *  服务实现类
 * </p>
 *
 * @author youndry
 * @since 2025-05-30
 */
@Service
public class URoleCommunityServiceImpl extends ServiceImpl<URoleCommunityMapper, URoleCommunity> implements IURoleCommunityService {

    @Resource
    MsRoleCommunityMapper ms;

    @Resource
    private UserHolder userHolder;

    @Resource
    private SCommunityMapper sCommunityMapper;

    @Override
    public boolean addRoleCommunity(PostRoleCommunityQuery query) {
        try {
            UserDTO userDTO = userHolder.getCurrentUser();
            String storeId = userDTO.getStoreIds().get(0);
//            String storeId = "400000000000000001";
            // 1. 先批量查询所有需要的小区信息
            List<String> communityIds = query.getCommunityIds();
            List<SCommunity> communities = sCommunityMapper.selectBatchIds(communityIds);

            // 2. 将查询结果转换为Map方便快速查找 (community_id -> SCommunity)
            Map<String, SCommunity> communityMap = communities.stream()
                    .collect(Collectors.toMap(SCommunity::getCommunityId, Function.identity()));

            // 3. 构建实体列表
            List<URoleCommunity> entities = communityIds.stream()
                    .map(community_id -> {
                        URoleCommunity entity = new URoleCommunity();
                        entity.setRoleId(query.getRoleId());
                        entity.setStoreId(storeId);
                        entity.setCommunityId(community_id);
                        entity.setStatusCd("0");

                        // 从Map中获取小区信息
                        SCommunity community = communityMap.get(community_id);
                        if (community == null) {
                            throw new RuntimeException("未找到对应的小区信息，community_id: " + community_id);
                        }
                        entity.setCommunityName(community.getName());

                        return entity;
                    })
                    .collect(Collectors.toList());
            return saveBatch(entities);
        } catch (Exception e) {
            e.printStackTrace();
            throw new RuntimeException("新增关联失败: " + e.getMessage());
        }
    }

    @Override
    public PageDTO<AssociatedRoleCommunityDTO> listRoleCommunity(GetAssociatedRoleCommunitiesQuery rcQuery) {
        try {
            // 构建分页查询对象
            Page<URoleCommunity> page = new Page<>(rcQuery.getPageIndex(), rcQuery.getPageSize());
            // 构建查询条件
            UserDTO userDTO = userHolder.getCurrentUser();
            String storeId = userDTO.getStoreIds().get(0);
            QueryWrapper<URoleCommunity> wrapper = new QueryWrapper<>();
            wrapper.eq("store_id", storeId);
            wrapper.like(!rcQuery.getRoleId().isEmpty(), "role_id", rcQuery.getRoleId());
            wrapper.eq("status_cd", "0");
            wrapper.orderByDesc("create_time");
            // 查询数据
            Page<URoleCommunity> resultPage = baseMapper.selectPage(page, wrapper);
            return PageDTO.create(resultPage, src -> ms.URoleCommunitytoAssociatedRoleCommunityDTO(src));
        } catch (Exception e) {
            e.printStackTrace();
            throw new RuntimeException("查询已关联小区列表失败: " + e.getMessage());
        }
    }

    @Override
    public PageDTO<UnassociatedRoleCommunityDTO> listOrgNoCommunity(GetUnassociatedRoleCommunitiesQuery rcQuery) {
        try {
            UserDTO userDTO = userHolder.getCurrentUser();
            String storeId = userDTO.getStoreIds().get(0);
            // 先查询已关联的小区ID列表
            QueryWrapper<URoleCommunity> existWrapper = new QueryWrapper<>();
            existWrapper.eq("store_id", storeId);
            if (!StringUtils.isEmpty(rcQuery.getRoleId())) {
                existWrapper.eq("role_id", rcQuery.getRoleId());
            }
            existWrapper.eq("status_cd", "0");
            List<String> associatedCommunityIds = baseMapper.selectList(existWrapper)
                    .stream()
                    .map(URoleCommunity::getCommunityId)
                    .collect(Collectors.toList());
            // 构建分页查询对象
            Page<SCommunity> page = new Page<>(rcQuery.getPageIndex(), rcQuery.getPageSize());
            // 构建查询条件
            QueryWrapper<SCommunity> wrapper = new QueryWrapper<>();
            wrapper.eq("status_cd", "0");
            if (!associatedCommunityIds.isEmpty()) {
                wrapper.notIn("community_id", associatedCommunityIds);
            }
            // 搜索关键词条件
            if (!StringUtils.isEmpty(rcQuery.getSearchKeyword())) {
                wrapper.like("name", rcQuery.getSearchKeyword());
            }
            wrapper.orderByDesc("create_time");
            // 查询数据
            Page<SCommunity> resultPage = sCommunityMapper.selectPage(page, wrapper);
            return PageDTO.create(resultPage, src -> ms.SCommunitytoAssociatedRoleCommunityDTO(src));
        } catch (Exception e) {
            e.printStackTrace();
            throw new RuntimeException("查询可关联小区列表失败: " + e.getMessage());
        }
    }

}
