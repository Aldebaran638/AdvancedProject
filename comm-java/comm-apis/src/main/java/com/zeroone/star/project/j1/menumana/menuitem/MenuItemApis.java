package com.zeroone.star.project.j1.menumana.menuitem;


import com.zeroone.star.project.dto.PageDTO;
import com.zeroone.star.project.dto.j1.menumana.menuitem.AddMenuItemDTO;
import com.zeroone.star.project.dto.j1.menumana.menuitem.DeleteMenuItemDTO;
import com.zeroone.star.project.dto.j1.menumana.menuitem.MenuItemDTO;
import com.zeroone.star.project.dto.j1.menumana.menuitem.ModifyMenuItemDTO;
import com.zeroone.star.project.query.j1.menumana.menuitem.MenuItemQuery;
import com.zeroone.star.project.vo.JsonVO;

import javax.validation.Valid;
import javax.validation.constraints.NotBlank;
import javax.validation.constraints.NotEmpty;
import javax.validation.constraints.Size;
import java.util.List;

/*
*菜单项管理
*获取菜单项（分页 菜单项列表）
* 添加菜单项  修改菜单项 删除菜单项
* */
public interface MenuItemApis {
    /**
     * @Description  分页+条件查询
     * @param query ：查询条件
     * @return 分页结果
     * @Author eu
     */
    JsonVO<PageDTO<MenuItemDTO>> queryMenuItem(@Valid MenuItemQuery query);
    /**
     * @Description  添加菜单项
     * @param    menuItemDTO ：菜单项
     * @return 添加结果
     * @Author eu
     */
    JsonVO<String> addMenuItem(@Valid AddMenuItemDTO menuItemDTO);
    /**
     * @Description  修改菜单项
     * @param  menuItemDTO ：菜单项
     * @return  修改结果
     * @Author eu
     */
    JsonVO<String> modifyMenuItem(@Valid ModifyMenuItemDTO menuItemDTO);
    /**
     * @Description   删除菜单项
     * @param  ：菜单项ID
     * @return  删除结果
     * @Author eu
     */
    JsonVO<String> deleteMenuItem(@Valid DeleteMenuItemDTO deleteMenuItemDTO);
}

