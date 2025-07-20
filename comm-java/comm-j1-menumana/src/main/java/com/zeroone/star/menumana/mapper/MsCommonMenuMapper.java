package com.zeroone.star.menumana.mapper;

import com.zeroone.star.menumana.entity.UserMenu;
import com.zeroone.star.project.dto.j1.menumana.commonmenu.AddCommonMenuDTO;
import com.zeroone.star.project.dto.j1.menumana.commonmenu.CommonMenuDTO;
import org.mapstruct.Mapper;


/**
 * \* @author cv
 * \* Time: 2025/5/20 + 18:35
 * \* Description: Privilege 对应的MapStruct映射接口
 * \
 */
@Mapper(componentModel = "spring")
public interface MsCommonMenuMapper {

    // 单例访问方式
//    MsCommonMenuMapper INSTANCE = Mappers.getMapper(MsCommonMenuMapper.class);

    /**
     * 将实体类转换为 DTO
     * @param cdo 实体类
     * @return 转换结果
     */
    CommonMenuDTO commonMenuToDto(UserMenu cdo) ;

    /**
     * 将 AddDto转换为实体类
     * @param dto DTO
     * @return 转换结果
     */
    UserMenu addDtoToDo(AddCommonMenuDTO dto);

    /**
     * 将 DTO 转换为实体类
     * @param dto DTO
     * @return 转换结果
     */
    UserMenu dtoToDo(CommonMenuDTO dto);
}