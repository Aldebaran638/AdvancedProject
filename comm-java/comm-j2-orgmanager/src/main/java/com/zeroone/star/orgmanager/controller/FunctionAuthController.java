package com.zeroone.star.orgmanager.controller;

import com.alibaba.cloud.commons.lang.StringUtils;
import com.zeroone.star.orgmanager.service.MenuService;
import com.zeroone.star.project.j2.orgmanager.role_priviledge.function.FunctionAuthApis;
import com.zeroone.star.project.query.j2.orgmanager.functionAuth.GetMenuTreeQuery;
import com.zeroone.star.project.query.j2.orgmanager.functionAuth.GetRolePermissionQuery;
import com.zeroone.star.project.query.j2.orgmanager.functionAuth.UpdateRolePermissionQuery;
import com.zeroone.star.project.vo.JsonVO;
import com.zeroone.star.project.vo.login.MenuTreeVO;
import io.swagger.annotations.Api;
import io.swagger.annotations.ApiOperation;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.web.bind.annotation.*;

import java.util.List;

@Api(tags = "组织管理-角色权限-功能授权")
@RestController
@RequestMapping("/j2-orgmanager/role/func")
public class FunctionAuthController implements FunctionAuthApis {
    @Autowired
    private MenuService menuService;

    @ApiOperation(value = "获取菜单名称树",notes = "根据商户id来查询菜单树")
    @GetMapping
    public JsonVO<List<MenuTreeVO>> getMenuTree(GetMenuTreeQuery getMenuTreeQuery) {
        List<MenuTreeVO> menuTree = menuService.getMenuTree(
                getMenuTreeQuery.getStoreId(),
                getMenuTreeQuery.getRoleType()
        );
        return JsonVO.success(menuTree);
    }
    @ApiOperation(value = "获取指定角色分配的权限",notes = "根据权限组id来查询指定角色权限状态")
    @GetMapping("/permissions")
    public JsonVO<List<MenuTreeVO>> getRolePermission(GetRolePermissionQuery getRolePermissionQuery) {
        List<MenuTreeVO> rolePermissions = menuService.getRolePermission(getRolePermissionQuery);
        return JsonVO.success(rolePermissions);
    }

    @ApiOperation(value = "修改角色权限",notes = "根据权限组id来更新指定角色权限状态")
    @PostMapping("/update-permissions")
    public JsonVO<String> updateRolePermission(@RequestBody UpdateRolePermissionQuery updateRolePermissionQuery) {
        //校验输入参数
        if(StringUtils.isBlank(updateRolePermissionQuery.getPgId())){
            return JsonVO.fail("权限组id不能为空");
        }
        if(StringUtils.isBlank(updateRolePermissionQuery.getPId())){
            return JsonVO.fail("权限id不能为空");
        }

        return JsonVO.success(menuService.updateRolePermission(updateRolePermissionQuery));
    }
}
