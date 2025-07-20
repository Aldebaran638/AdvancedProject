package com.zeroone.star.orgmanager.service.impl;

import com.zeroone.star.orgmanager.entity.PPrivilegeGroup;
import com.zeroone.star.project.dto.j2.orgmanager.rolemanage.RoleAddDTO;
import com.zeroone.star.project.dto.j2.orgmanager.rolemanage.RoleDTO;
import org.mapstruct.Mapper;

@Mapper(componentModel = "spring")
public interface MsRoleManageMapper {

    /**
     * 实体类转DTO
     * @param ddo 实体类
     * @return 转换结果 DTO
     */
    RoleDTO PPrivilegeGroupToDto(PPrivilegeGroup ddo);

    /**
     * AddDto转实体类
     * @param dto ADD DTO
     * @return 转换结果 实体类
     */
    PPrivilegeGroup addDtoToDo(RoleAddDTO dto);

    /**
     * Dto转换为实体类
     * @param dto DTO
     * @return 转换结果
     */
    PPrivilegeGroup DtoToDo(RoleDTO dto);
}
