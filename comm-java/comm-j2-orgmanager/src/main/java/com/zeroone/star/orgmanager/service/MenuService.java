package com.zeroone.star.orgmanager.service;

import com.zeroone.star.project.query.j2.orgmanager.functionAuth.GetRolePermissionQuery;
import com.zeroone.star.project.query.j2.orgmanager.functionAuth.UpdateRolePermissionQuery;
import com.zeroone.star.project.vo.login.MenuTreeVO;

import java.util.List;

public interface MenuService {
    List<MenuTreeVO> getMenuTree(String storeId, String roleType);
    List<MenuTreeVO> getRolePermission(GetRolePermissionQuery getRolePermissionQuery);
    String updateRolePermission(UpdateRolePermissionQuery updateRolePermissionQuery);
}
