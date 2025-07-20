package com.zeroone.star.orgmanager.service.impl;

import com.zeroone.star.orgmanager.entity.SCommunity;
import com.zeroone.star.project.dto.j2.orgmanager.rolePermission.RoleCommunityDTO;
import com.zeroone.star.project.query.j2.orgmanager.rolePermission.GetAssociatedRoleCommunitiesQuery;
import com.zeroone.star.project.dto.j2.orgmanager.rolePermission.UnassociatedRoleCommunityDTO;
import org.mapstruct.Mapper;

@Mapper(componentModel = "spring")
public interface MsSCommunityMapper {
    /**
     * DAO DO Entity -> Service VO
     * 将SCommunity转换为UnassociatedRoleCommunityVO
     * @param sdo
     * @return
     */
    UnassociatedRoleCommunityDTO SCommunitytoAssociatedRoleCommunityDTO(SCommunity sdo);

    /**
     * Browser DTO -> DAO DO Entity
     * 将RoleCommunityDTO转换为SCommunity
     * @param rcDTO
     */
    SCommunity RoleCommunityDTOtoSCommunity(RoleCommunityDTO rcDTO);

    /**
     * Browser DTO -> DAO DO Entity
     * 将GetRoleCommunitiesQuery转换为SCommunity
     * @param rcGetquery
     * @return
     */
    SCommunity GetRoleCommunitiesQuerytoRoleCommunityDTO(GetAssociatedRoleCommunitiesQuery rcGetquery);

}

