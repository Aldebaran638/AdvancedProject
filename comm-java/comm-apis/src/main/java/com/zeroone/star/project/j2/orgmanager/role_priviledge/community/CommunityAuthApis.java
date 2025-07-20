package com.zeroone.star.project.j2.orgmanager.role_priviledge.community;

import com.zeroone.star.project.dto.PageDTO;
import com.zeroone.star.project.query.j2.orgmanager.rolePermission.GetAssociatedRoleCommunitiesQuery;
import com.zeroone.star.project.query.j2.orgmanager.rolePermission.GetUnassociatedRoleCommunitiesQuery;
import com.zeroone.star.project.query.j2.orgmanager.rolePermission.PostRoleCommunityQuery;
import com.zeroone.star.project.vo.JsonVO;
import com.zeroone.star.project.dto.j2.orgmanager.rolePermission.AssociatedRoleCommunityDTO;
import com.zeroone.star.project.dto.j2.orgmanager.rolePermission.UnassociatedRoleCommunityDTO;

/**
 * 小区授权接口
 */

public interface CommunityAuthApis {

    /**
     * 添加小区授权
     */
    JsonVO<String> addRoleCommunity(PostRoleCommunityQuery addRoleCommunityQuery);

    /**
     * 删除小区授权
     */
    JsonVO<String> deleteRoleCommunity(String rcId);

    /**
     * 获取已关联小区列表
     */
    JsonVO<PageDTO<AssociatedRoleCommunityDTO>> listRoleCommunity(GetAssociatedRoleCommunitiesQuery getAssociatedRoleCommunitiesQuery);

    /**
     * 获取可关联小区列表
     */
    JsonVO<PageDTO<UnassociatedRoleCommunityDTO>> listOrgNoCommunity(GetUnassociatedRoleCommunitiesQuery getUnassociatedRoleCommunitiesQuery);
}
