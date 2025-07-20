package com.zeroone.star.menumana.mapper;

import com.zeroone.star.menumana.entity.MenuCatalog;
import com.zeroone.star.project.dto.j1.menumana.menudir.AddMenuCatalogDTO;
import com.zeroone.star.project.dto.j1.menumana.menudir.DeleteMenuCatalogDTO;
import com.zeroone.star.project.dto.j1.menumana.menudir.MenuCatalogDTO;
import com.zeroone.star.project.dto.j1.menumana.menudir.UpdateMenuCatalogDTO;
import org.mapstruct.Mapper;

@Mapper(componentModel = "spring")
public interface MsMenuCatalogMapper {
    /**
     * 将实体类转换为DTO
     * @param sdo 实体类
     * @return 转换结果
     */
    MenuCatalogDTO MenuCatalogToDto(MenuCatalog sdo);

    /**
     * 将Add DTO转换为实体类
     * @param dto Add DTO
     * @return 转换结果
     */
    MenuCatalog addDtoToDo(AddMenuCatalogDTO dto);

    /**
     * 将DTO转换为实体类
     * @param dto DTO
     * @return 转换结果
     */
    MenuCatalog dtoToDo(MenuCatalogDTO dto);

    /**
     * 将Update DTO转换为实体类
     * @param dto Update DTO
     * @return 转换结果
     */
    MenuCatalog updateDtoToDo(UpdateMenuCatalogDTO dto);


    /**
     * 将del DTO转换为实体类
     * @param dto Del DTO
     * @return 转换结果
     */
    MenuCatalog delDtoToDo(DeleteMenuCatalogDTO dto);

}
