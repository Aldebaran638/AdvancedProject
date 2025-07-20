package com.zeroone.star.project.j1.menumana.menudir;


import com.baomidou.mybatisplus.extension.plugins.pagination.Page;
import com.zeroone.star.project.dto.j1.menumana.menudir.*;
import com.zeroone.star.project.dto.PageDTO;
import com.zeroone.star.project.query.j1.menumana.menudir.MenuCatalogQuery;
import com.zeroone.star.project.vo.JsonVO;

import java.util.List;

/**
 * 菜单管理：菜单目录：获取菜单目录列表、添加菜单目录、修改菜单目录、删除菜单目录
 */
public interface MenuCatalogApis {
    /**
     * 分页查询菜单目录列表
     * @param query 查询条件
     * @return 分页结果
     */
    JsonVO<PageDTO<MenuCatalogDTO>> queryMenuCatalogPage( MenuCatalogQuery query) throws Exception;
    
    /**
     * 添加菜单目录
     * @param addMenuCatalogDTO 菜单目录数据
     * @return 操作结果
     */
    JsonVO<String> addMenuCatalog(AddMenuCatalogDTO addMenuCatalogDTO) throws Exception;
    
    /**
     * 修改菜单目录
     * @param updateMenuCatalogDTO 菜单目录数据
     * @return 操作结果
     */
    JsonVO<String> modifyMenuCatalog(UpdateMenuCatalogDTO updateMenuCatalogDTO) throws Exception;

    /**
     * 删除菜单目录
     * @param id 菜单目录ID
     * @return 操作结果
     */
    JsonVO<String> removeMenuCatalog(String id) throws Exception;
}