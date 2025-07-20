package com.zeroone.star.orgmanager.service.serviceImpl;

import com.zeroone.star.orgmanager.entity.DataPrivilege;
import com.zeroone.star.project.dto.j2.orgmanager.DataPrivilegeAddDTO;
import com.zeroone.star.project.dto.j2.orgmanager.dataPrivilege.DataPrivilegeDTO;
import org.mapstruct.Mapper;

/**
 * <p>
 * 描述：DataPrivilege对应的MapStruct映射接口
 * </p>
 * <p>版权：&copy;01星球</p>
 * <p>地址：01星球总部</p>
 * @author hubery
 * @version 1.0.0
 */
@Mapper(componentModel = "spring")
public interface MsDataPrivilegeMapper {

    /**
     * do 转dto
     */
    DataPrivilegeDTO doToDto(DataPrivilege dataPrivilege);

    /**
     * add dto 转 do
     */
    DataPrivilege addDtoToDo(DataPrivilegeAddDTO addDTO);


    /**
     * dto 转do
     */
    DataPrivilege dtoToDo(DataPrivilegeDTO dataPrivilegeDTO);



}