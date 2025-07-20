package com.zeroone.star.project.j2.orgmanager.role_priviledge.function;

import com.zeroone.star.project.query.j2.orgmanager.functionAuth.GetMenuTreeQuery;
import com.zeroone.star.project.query.j2.orgmanager.functionAuth.GetRolePermissionQuery;
import com.zeroone.star.project.query.j2.orgmanager.functionAuth.UpdateRolePermissionQuery;
import com.zeroone.star.project.vo.JsonVO;
import com.zeroone.star.project.vo.login.MenuTreeVO;

import java.util.List;

/**
 * 功能授权接口
 */
public interface FunctionAuthApis {
    /**
     * 获取菜单名称树
     */
    JsonVO<List<MenuTreeVO>> getMenuTree(GetMenuTreeQuery getMenuTreeQuery);
    /**
     * 获取指定角色分配的权限
     */
    JsonVO<List<MenuTreeVO>>  getRolePermission(GetRolePermissionQuery getRolePermissionQuery);
    /**
     * 修改角色授权
     */
    JsonVO<String> updateRolePermission(UpdateRolePermissionQuery updateRolePermissionQuery);

}
