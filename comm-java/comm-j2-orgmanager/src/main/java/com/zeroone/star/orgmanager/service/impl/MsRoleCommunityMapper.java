package com.zeroone.star.orgmanager.service.impl;

import com.zeroone.star.orgmanager.entity.SCommunity;
import com.zeroone.star.orgmanager.entity.URoleCommunity;
import com.zeroone.star.project.dto.j2.orgmanager.rolePermission.RoleCommunityDTO;
import com.zeroone.star.project.query.j2.orgmanager.rolePermission.GetAssociatedRoleCommunitiesQuery;
import com.zeroone.star.project.query.j2.orgmanager.rolePermission.PostRoleCommunityQuery;
import com.zeroone.star.project.dto.j2.orgmanager.rolePermission.AssociatedRoleCommunityDTO;
import com.zeroone.star.project.dto.j2.orgmanager.rolePermission.UnassociatedRoleCommunityDTO;
import org.mapstruct.Mapper;

@Mapper(componentModel = "spring")
public interface MsRoleCommunityMapper {
    /**
     * DAO DO Entity -> Service VO
     * 将URoleCommunity转换为AssociatedRoleCommunityVO
     * @param rcdo
     * @return
     */
    AssociatedRoleCommunityDTO URoleCommunitytoAssociatedRoleCommunityDTO(URoleCommunity rcdo);

    /**
     * DAO DO Entity -> Service VO
     * 将URoleCommunity转换为UnassociatedRoleCommunityVO
     * @param sdo
     * @return
     */
    UnassociatedRoleCommunityDTO SCommunitytoAssociatedRoleCommunityDTO(SCommunity sdo);

    /**
     * Browser DTO -> DAO DO Entity
     * 将RoleCommunityDTO转换为URoleCommunity
     * @param rcDTO
     */
    URoleCommunity RoleCommunityDTOtoURoleCommunity(RoleCommunityDTO rcDTO);

    /**
     * Browser DTO -> DAO DO Entity
     * 将GetRoleCommunitiesQuery转换为URoleCommunity
     * @param rcGetquery
     * @return
     */
    URoleCommunity GetRoleCommunitiesQuerytoRoleCommunityDTO(GetAssociatedRoleCommunitiesQuery rcGetquery);

    /**
     * Browser DTO -> DAO DO Entity
     * 将PostRoleCommunityQuery转换为URoleCommunity
     * @param rcPostquery
     * @return
     */
    URoleCommunity PostRoleCommunityQuerytoURoleCommunity(PostRoleCommunityQuery rcPostquery);


}
