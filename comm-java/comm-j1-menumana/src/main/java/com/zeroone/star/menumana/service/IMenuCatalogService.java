package com.zeroone.star.menumana.service;


import com.baomidou.mybatisplus.extension.plugins.pagination.Page;
import com.baomidou.mybatisplus.extension.service.IService;
import com.zeroone.star.menumana.entity.MenuCatalog;
import com.zeroone.star.project.dto.PageDTO;
import com.zeroone.star.project.dto.j1.menumana.menudir.*;
import com.zeroone.star.project.query.j1.menumana.menudir.MenuCatalogQuery;

import java.util.List;

public interface IMenuCatalogService extends IService<MenuCatalog> {

    /**
     * 分页查询菜单目录
     * @param page
     * @param query
     * @return
     * @throws Exception
     */
    PageDTO<MenuCatalogDTO> listMenuCatalogPage(Page<MenuCatalog> page,MenuCatalogQuery query) throws Exception;

    /**
     * 新增菜单目录
     * @param menuCatalog
     * @return
     */
    Boolean saveMenuCatalog(MenuCatalog menuCatalog) throws Exception;

    /**
     * 修改菜单目录
     * @param updateMenuCatalogDTO
     * @return
     */
    Boolean updateMenuCatalog(UpdateMenuCatalogDTO updateMenuCatalogDTO) throws Exception;

    /**
     * 删除菜单目录
     * @param caId
     * @return
     */
    Boolean removeMenuCatalog(String caId) throws Exception;
}