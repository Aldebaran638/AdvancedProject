package com.zeroone.star.menumana.mapper;

import com.zeroone.star.menumana.entity.Privilege;
import com.zeroone.star.project.dto.j1.menumana.privilege.PrivilegeAddDTO;
import com.zeroone.star.project.dto.j1.menumana.privilege.PrivilegeDTO;
import org.mapstruct.Mapper;
import org.mapstruct.factory.Mappers;
/**
 * \* @author cv
 * \* Time: 2025/5/20 + 18:35
 * \* Description: Privilege 对应的MapStruct映射接口
 * \
 */
@Mapper(componentModel = "spring")
public interface MsPrivilegeMapper {

    // 单例访问方式
    MsPrivilegeMapper INSTANCE = Mappers.getMapper(MsPrivilegeMapper.class);

    /**
     * 将实体类转换为 DTO
     */
    PrivilegeDTO PrivilegeToDto(Privilege privilege) ;

    /**
     * 将 AddDto 转换为实体类
     */
    Privilege addDtoToPrivilege(PrivilegeAddDTO dto);

    /**
     * 将 DTO 转换为实体类
     */
    Privilege dtoToDo(PrivilegeDTO dto);

    // 处理 Long 类型的转换
    default Long mapToLong(Long value) {
        return value;
    }

    default Long mapToLong(String value) {
        return value == null ? null : Long.parseLong(value);
    }
}