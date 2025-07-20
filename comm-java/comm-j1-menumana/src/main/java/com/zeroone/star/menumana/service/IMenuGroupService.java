package com.zeroone.star.menumana.service;

import com.zeroone.star.project.dto.PageDTO;
import com.zeroone.star.project.dto.j1.menumana.menugroup.MenuGroupDTO;
import com.zeroone.star.project.dto.j1.menumana.menugroup.UpdateMenuGroupDTO;
import com.zeroone.star.project.query.j1.menumana.menugroup.MenuGroupQuery;
import com.zeroone.star.project.vo.j1.menumana.menugroup.MenuGroupNameVO;
import com.zeroone.star.project.vo.j1.menumana.menugroup.MenuGroupVO;

import java.util.List;

public interface IMenuGroupService {
    /**
     * 获取菜单组名称列表
     * @param storeType
     * @return
     */
    List<MenuGroupNameVO> listMenuGroupName(String storeType);

    /**
     * 获取菜单组列表
     * @param query
     * @return
     */
    PageDTO<MenuGroupVO> listMenuGroup(MenuGroupQuery query);

    /**
     * 添加菜单组
     * @param menuGroupDTO
     */
    boolean addMenuGroup(MenuGroupDTO menuGroupDTO);

    /**
     * 修改菜单组
     * @param updateMenuGroupDTO
     * @return
     */
    boolean updateMenuGroup(UpdateMenuGroupDTO updateMenuGroupDTO);

    /**
     * 删除菜单组
     * @param gid
     * @return
     */
    boolean deleteMenuGroupById(String gid);
}
