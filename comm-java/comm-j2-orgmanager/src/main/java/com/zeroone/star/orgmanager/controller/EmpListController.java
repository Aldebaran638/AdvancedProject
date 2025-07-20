package com.zeroone.star.orgmanager.controller;

import com.zeroone.star.orgmanager.service.EmpListService;
import com.zeroone.star.project.dto.PageDTO;
import com.zeroone.star.project.dto.j2.orgmanager.rolePermission.AddEmpListDTO;
import com.zeroone.star.project.dto.j2.orgmanager.rolePermission.EmpListDTO;
import com.zeroone.star.project.j2.orgmanager.rolepermission.EmpListApis;
import com.zeroone.star.project.query.j2.orgmanager.rolePermission.EmpListQuery;
import com.zeroone.star.project.vo.JsonVO;
import com.zeroone.star.project.vo.ResultStatus;
import io.swagger.annotations.Api;
import io.swagger.annotations.ApiImplicitParam;
import io.swagger.annotations.ApiOperation;
import io.swagger.annotations.ApiParam;
import org.springframework.validation.annotation.Validated;
import org.springframework.web.bind.annotation.*;

import javax.annotation.Resource;
import java.util.List;

/**
 * 员工关联控制器
 */
@Api(tags = "组织管理-角色权限-员工关联")
@RestController
@RequestMapping("/j2-orgmanager/group/role")
public class EmpListController implements EmpListApis {
    @Resource
    private EmpListService empListService;
    @ApiOperation(value = "获取已关联员工列表（条件+分页）", notes = "根据角色查询列表")
    @GetMapping("/emplist")
    @Override
    public JsonVO<PageDTO<EmpListDTO>> queryEmpList(@Validated EmpListQuery query) {
        return JsonVO.success(empListService.listAllEmp(query));
    }

    @ApiOperation(value = "新增关联", notes = "根据ID新增关联")
    @PostMapping("/emplist")
    @Override
    public JsonVO<Boolean> addEmpList(AddEmpListDTO addEmpListDTO) {

        ResultStatus result=empListService.saveEmpList(addEmpListDTO);
        return JsonVO.create(result.getCode()==10000,result);
    }
    @ApiOperation(value = "删除关联",notes = "根据ID删除关联")
    @Override
    @DeleteMapping("/emplist")
    public JsonVO<String> removeEmpList(@ApiParam(value = "权限ID",required = true) String pId,@ApiParam(value = "权限组ID",required = true) String pgId) {
        int result=empListService.removeEmpList(pId,pgId);
        return result>0? JsonVO.success("删除成功"):JsonVO.fail("删除失败");
    }
}
