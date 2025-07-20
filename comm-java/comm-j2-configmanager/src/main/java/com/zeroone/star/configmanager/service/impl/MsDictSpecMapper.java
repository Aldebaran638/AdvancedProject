package com.zeroone.star.configmanager.service.impl;

import com.zeroone.star.configmanager.entity.DictSpec;
import com.zeroone.star.project.dto.j2.configmanager.dict.DictSpecAddDTO;
import com.zeroone.star.project.dto.j2.configmanager.dict.DictSpecDTO;
import org.mapstruct.Mapper;


/**
 * <p>
 * 用于将实体类自动转换为DTO类,实现类在target中生成
 * </p>
 * <p>版权：&copy;01星球</p>
 * <p>地址：01星球总部</p>
 * @author fish
 * @version 1.0.0
 */
@Mapper(componentModel = "spring")
public interface MsDictSpecMapper {
    /**
     * 将实体类转换为DTO
     * @param ddo 实体类
     * @return 转换结果
     */
    DictSpecDTO dictSpecToDto(DictSpec ddo);

    /**
     * 将实体类转换为Add DTO
     * @param ddo 实体类
     * @return 转换结果
     * */
    DictSpecAddDTO dictSpecToAddDto(DictSpec ddo);

    /**
     * 将Add DTO转换为实体类
     * @param dto Add DTO
     * @return 转换结果
     */
    DictSpec addDtoToDo(DictSpecAddDTO dto);

    /**
     * 将DTO转换为实体类
     * @param dto DTO
     * @return 转换结果
     */
    DictSpec dtoToDo(DictSpecDTO dto);
}
