package com.zeroone.star.menumana.mapper;

import com.baomidou.mybatisplus.core.mapper.BaseMapper;
import com.zeroone.star.menumana.entity.MenuCatalog;
import com.zeroone.star.project.dto.j1.menumana.menudir.AddMenuCatalogDTO;
import com.zeroone.star.project.dto.j1.menumana.menudir.DeleteMenuCatalogDTO;
import com.zeroone.star.project.dto.j1.menumana.menudir.MenuCatalogDTO;
import com.zeroone.star.project.dto.j1.menumana.menudir.UpdateMenuCatalogDTO;
import com.zeroone.star.project.query.j1.menumana.menudir.MenuCatalogQuery;
import org.apache.ibatis.annotations.*;

import java.util.List;

@Mapper
public interface IMenuCatalogMapper extends BaseMapper<MenuCatalog> {
    /**
     * 根据条件查询菜单组
     */
    @Select("")
    List<MenuCatalogDTO> selectByConditions(MenuCatalogQuery menuCatalogQuery);

    /**
     * 添加对应菜单组
     */
    @Insert("")
    Integer insertMenuCatalog(AddMenuCatalogDTO addMenuCatalogDTO);

    /**
     * 删除对应菜单组
     */
    @Delete("")
    Integer deleteMenuCatalog(DeleteMenuCatalogDTO deleteMenuCatalogDTO);

    /**
     * 修改菜单目录
     */
    @Update("")
    Integer updateMenuCatalog(UpdateMenuCatalogDTO updateMenuCatalogDTO);
}
