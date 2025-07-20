package com.zeroone.star.menumana.service;

import com.zeroone.star.project.dto.PageDTO;
import com.zeroone.star.project.dto.j1.menumana.menuitem.AddMenuItemDTO;
import com.zeroone.star.project.dto.j1.menumana.menuitem.DeleteMenuItemDTO;
import com.zeroone.star.project.dto.j1.menumana.menuitem.MenuItemDTO;
import com.zeroone.star.project.dto.j1.menumana.menuitem.ModifyMenuItemDTO;
import com.zeroone.star.project.query.j1.menumana.menuitem.MenuItemQuery;
import com.zeroone.star.project.vo.JsonVO;
import springfox.documentation.spring.web.json.Json;

import java.util.List;

/**
 * @Description
 * @Author eu
 * @Date 2025/5/25
 */
public interface IMenuItemService {
    /**
    * @Description 分页查询
    * @param    query ：查询条件
    * @return  分页结果
    * @Author eu
    * @Date
    */
    PageDTO<MenuItemDTO> listAllMenuItemsPage(MenuItemQuery query);
    /**
    * @Description 添加菜单项
    * @param   ：菜单项
    * @return   添加结果
    * @Author eu
    * @Date
    */
    JsonVO<String> addMenuItem(AddMenuItemDTO addMenuItemDTO);
    /**
    * @Description 删除菜单项
    * @param
    * @return 删除结果
    * @Author eu
    * @Date
    */
    JsonVO<String> deleteMenuItem(DeleteMenuItemDTO deleteMenuItemDTO);
    /**
    * @Description   修改菜单项
    * @param
    * @return
    * @Author eu
    * @Date
    */
    JsonVO<String> modifyMenuItem(ModifyMenuItemDTO modifyMenuItemDTO);
}
