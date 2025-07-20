package com.zeroone.star.orgmanager.service.serviceImpl;

import com.zeroone.star.orgmanager.entity.UUserDO;
import com.zeroone.star.project.dto.j2.orgmanager.rolePermission.EmpListDTO;
import org.mapstruct.Mapper;

/**
 * 实体类转换为DTO
 */
@Mapper(componentModel = "spring")
public interface MSEmpListMapper {
    /**
     * 将实体类转换为DTO
     * @param udo 实体类
     * @return 转换结果
     */
    EmpListDTO uuserToDto(UUserDO udo);

    /**
     * 将DTO转换为实体类
     * @param dto DTO
     * @return 转换结果
     */
    UUserDO dtoToDo(EmpListDTO dto);
}
