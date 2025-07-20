package com.zeroone.star.orgmanager.service;

import com.zeroone.star.project.dto.PageDTO;
import com.zeroone.star.orgmanager.entity.URoleCommunity;
import com.baomidou.mybatisplus.extension.service.IService;
import com.zeroone.star.project.query.j2.orgmanager.rolePermission.GetAssociatedRoleCommunitiesQuery;
import com.zeroone.star.project.dto.j2.orgmanager.rolePermission.AssociatedRoleCommunityDTO;
import com.zeroone.star.project.dto.j2.orgmanager.rolePermission.UnassociatedRoleCommunityDTO;
import com.zeroone.star.project.query.j2.orgmanager.rolePermission.GetUnassociatedRoleCommunitiesQuery;
import com.zeroone.star.project.query.j2.orgmanager.rolePermission.PostRoleCommunityQuery;

/**
 * <p>
 *  服务类
 * </p>
 *
 * @author youndry
 * @since 2025-05-30
 */
public interface IURoleCommunityService extends IService<URoleCommunity> {

    boolean addRoleCommunity(PostRoleCommunityQuery addRoleCommunityQuery);

    PageDTO<AssociatedRoleCommunityDTO> listRoleCommunity(GetAssociatedRoleCommunitiesQuery rcQuery);

    PageDTO<UnassociatedRoleCommunityDTO> listOrgNoCommunity(GetUnassociatedRoleCommunitiesQuery rcQuery);
}
