package com.zeroone.star.configmanager.service.impl;


import com.zeroone.star.configmanager.entity.CMappingDomain;
import com.zeroone.star.project.dto.j2.configmanager.mappingdomain.MappingDomainAddDTO;
import com.zeroone.star.project.dto.j2.configmanager.mappingdomain.MappingDomainDTO;
import org.mapstruct.Mapper;

/**
 * <p>
 * 描述：MappingDomain对应的MapStruct映射接口
 * </p>
 * <p>版权：&copy;01星球</p>
 * <p>地址：01星球总部</p>
 * @author hubery
 * @version 1.0.0
 */
@Mapper(componentModel = "spring")
public interface MsMappingDomainMapper {

    /**
     * 将实体类转dto
     */
    MappingDomainDTO doToDto(CMappingDomain mappingDomain);


    /**
     * 将add dto转为do
     */
    CMappingDomain addDtoToDo(MappingDomainAddDTO addDTO);


    /**
     * dto 转do
     */
    CMappingDomain dtoToDo(MappingDomainDTO dto);
}
