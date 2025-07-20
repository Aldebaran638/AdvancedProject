package com.zeroone.star.project.j1.menumana.menuitem;

import com.zeroone.star.project.dto.j1.menumana.menuitem.MenuPrivilegeTreeDTO;
import com.zeroone.star.project.vo.JsonVO;

import java.util.List;

/**
 * 菜单管理：菜单项：获取菜单名称树接口
 */
public interface MenuPriviliegeTreeApis {
    /**
     * 获取菜单名称树
     * @return
     */
    JsonVO<List<MenuPrivilegeTreeDTO>> getMenuPrivilegeTree();

}
