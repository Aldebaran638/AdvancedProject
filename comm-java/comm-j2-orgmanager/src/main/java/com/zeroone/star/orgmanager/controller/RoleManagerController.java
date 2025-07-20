package com.zeroone.star.orgmanager.controller;


import com.zeroone.star.orgmanager.mapper.PPrivilegeGroupMapper;
import com.zeroone.star.orgmanager.service.RoleManageService;
import com.zeroone.star.project.dto.j2.orgmanager.rolemanage.RoleAddDTO;
import com.zeroone.star.project.dto.j2.orgmanager.rolemanage.RoleDTO;
import com.zeroone.star.project.j2.orgmanager.RoleManagerApis;
import com.zeroone.star.project.vo.JsonVO;
import io.swagger.annotations.Api;
import io.swagger.annotations.ApiImplicitParam;
import io.swagger.annotations.ApiOperation;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.validation.annotation.Validated;
import org.springframework.web.bind.annotation.*;

import javax.annotation.Resource;
import java.util.List;

@RestController
@RequestMapping("/j2-orgmanager/role-manage")
@Api(tags = "组织管理-角色权限-角色基础信息")
@Validated
public class RoleManagerController implements RoleManagerApis {
    @Resource
    RoleManageService roleManageService;

    @Autowired
    PPrivilegeGroupMapper pPrivilegeGroupMapper;
    /**
     * 根据传入条件分页查询角色
     * @return 查询结果
     */
    @ApiOperation(value = "获取角色列表")
    @GetMapping("/query")
    @Override
    public JsonVO<List<RoleDTO>> queryAllRole() {
        return JsonVO.success(roleManageService.listAllRoles());
    }

    /**
     * 增加角色
     * @param addDTO
     */
    @ApiOperation(value = "添加角色")
    @PostMapping("/add")
    @Override
    public JsonVO<String> addRole(@Validated @RequestBody RoleAddDTO addDTO) {
        if(roleManageService.saveRole(addDTO).equals("0")) return JsonVO.success("添加角色成功");
        else return JsonVO.fail("添加角色失败");
    }

    /**
     * 修改角色
     * @param dto
     */
    @ApiOperation(value = "修改角色")
    @PutMapping("/update")
    @Override
    public JsonVO<String> modifyRole(@Validated @RequestBody RoleDTO dto) {
        if(roleManageService.updateRole(dto).equals("0")) return JsonVO.success("修改角色信息成功");
        else return JsonVO.fail("修改角色信息失败");
    }

    /**
     * 删除角色
     * @param pg_id 角色id
     */
    @ApiOperation(value = "删除角色")
    @ApiImplicitParam(name = "pg_id",value = "角色id",example = "6002025051438010007",required = true)
    @DeleteMapping("/delete")
    @Override
    public JsonVO<String> deleteRole(String pg_id) {
        if(roleManageService.deleteRole(pg_id).equals("0")) return JsonVO.success("删除角色成功");
        else return JsonVO.fail("删除角色失败");
    }
}
