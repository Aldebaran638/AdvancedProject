package com.zeroone.star.project.j1.menumana.menugroup;

import com.zeroone.star.project.dto.PageDTO;
import com.zeroone.star.project.dto.j1.menumana.menugroup.MenuGroupDTO;
import com.zeroone.star.project.dto.j1.menumana.menugroup.UpdateMenuGroupDTO;
import com.zeroone.star.project.query.j1.menumana.menugroup.MenuGroupQuery;
import com.zeroone.star.project.vo.JsonVO;
import com.zeroone.star.project.vo.j1.menumana.menugroup.MenuGroupNameVO;
import com.zeroone.star.project.vo.j1.menumana.menugroup.MenuGroupVO;

import java.util.List;

/**
 * <p>
 * 描述：菜单管理接口
 * </p>
 *
 * @author AMG007
 * @since 2025-05-20
 */
public interface MenuGroupApis {
    /**
     * 获取菜单组名称列表
     * @return
     */
    JsonVO<List<MenuGroupNameVO>> listMenuGroupName(String storeType);

    /**
     * 获取菜单组列表(分页+条件查询)
     * @return
     */
    JsonVO<PageDTO<MenuGroupVO>> listMenuGroup(MenuGroupQuery query);

    /**
     * 添加菜单组
     * @param menuGroupDTO
     * @return
     */
    JsonVO<String> addMenuGroup(MenuGroupDTO menuGroupDTO);

    /**
     * 修改菜单组
     * @param updateMenuGroupDTO
     * @return
     */
    JsonVO<String> updateMenuGroup(UpdateMenuGroupDTO updateMenuGroupDTO);
    /**
     * 删除菜单组
     * @param gid
     * @return
     */
    JsonVO<String> deleteMenuGroup(String gid);
}
