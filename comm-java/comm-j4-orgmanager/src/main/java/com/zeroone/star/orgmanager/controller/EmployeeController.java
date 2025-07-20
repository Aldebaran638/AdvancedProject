package com.zeroone.star.orgmanager.controller;

import com.zeroone.star.orgmanager.service.EmployeeService;
import com.zeroone.star.project.dto.PageDTO;
import com.zeroone.star.project.dto.j4.orgmanager.AddEmployeeDTO;
import com.zeroone.star.project.dto.j4.orgmanager.ModifyEmployeeDTO;
import com.zeroone.star.project.dto.j4.orgmanager.ScheduleClassesDTO;
import com.zeroone.star.project.query.j4.orgmanager.employee.EmployeeQuery;
import com.zeroone.star.project.query.j4.orgmanager.employee.EmployeeSchedulingInfoQuery;
import com.zeroone.star.project.vo.ResultStatus;
import com.zeroone.star.project.vo.j4.orgmanager.EmpOrgAuthorityVO;
import com.zeroone.star.project.j4.orgmanager.EmployeeApis;
import com.zeroone.star.project.vo.JsonVO;
import com.zeroone.star.project.vo.j4.orgmanager.EmployeeBaseInfoVO;
import com.zeroone.star.project.vo.j4.orgmanager.EmployeeListVO;
import io.swagger.annotations.Api;
import io.swagger.annotations.ApiOperation;
import lombok.extern.slf4j.Slf4j;
import lombok.RequiredArgsConstructor;
import org.springframework.web.bind.annotation.*;
import javax.annotation.Resource;

import java.util.List;

/**
 * @Author: bu
 * @Description: 员工信息controller
 */
@RestController
@RequestMapping("/j4-orgmanager/employee")
@RequiredArgsConstructor
@Api(tags = "员工信息接口")
@Slf4j
public class EmployeeController implements EmployeeApis {

    @Resource
    EmployeeService employeeService;
    @ApiOperation(value = "删除员工")
    @DeleteMapping("delete-emp")

    @Override
    public JsonVO<String> deleteEmployee(String userId) {
        String ans = employeeService.deleteEmployee(userId);
        if(ans.equals("success")){
            return JsonVO.success(ans);
        }
        return JsonVO.fail(ans);
    }

    @ApiOperation(value = "获取员工基础信息")
    @GetMapping("query-emp-base")
    @Override
    public JsonVO<EmployeeBaseInfoVO> getEmployeeBaseInfo(String userId) {
        return employeeService.getEmployeeBaseInfo(userId);
    }

    @ApiOperation(value = "获取员工组织权限信息")
    @GetMapping("query-emp-orgAndAuth")
    @Override
    public JsonVO<EmpOrgAuthorityVO> getEmpOrgAuthority(String userId) {
        return employeeService.getEmpOrgAuthority(userId);
    }

    @ApiOperation(value = "添加员工")
    @PostMapping("add-emp")
    @Override
    public JsonVO<String> addEmployee(@ModelAttribute AddEmployeeDTO addEmployeeDTO) {
        String ans = employeeService.addEmployee(addEmployeeDTO);
        if(ans.equals("success")) return JsonVO.success(ans);
        else return JsonVO.fail(ans);
    }

    @ApiOperation(value = "修改员工")
    @PutMapping("modify-emp")
    @Override
    public JsonVO<String> modifyEmployee(@ModelAttribute ModifyEmployeeDTO modifyEmployeeDTO) {
        String ans = employeeService.modifyEmployee(modifyEmployeeDTO);
        if(ans.equals("success")) return JsonVO.success(ans);
        else return JsonVO.fail(ans);
    }

    @ApiOperation(value = "重置密码")
    @GetMapping("reset-password")
    @Override
    public JsonVO<String> resetPassword(String userId) {
        String ans = employeeService.resetPassword(userId);
        if(ans.equals("fail") || ans.equals("user不存在")){
            return JsonVO.fail(ans);
        }else{
            return JsonVO.success(ans);
        }
    }

    @ApiOperation(value = "获取员工列表")
    @GetMapping("/get-empList")
    @ResponseBody
    @Override
    public JsonVO<PageDTO<EmployeeListVO>> getEmployeeList(EmployeeQuery employeeQuery) {
        return employeeService.emplist(employeeQuery);
    }

    @ApiOperation(value = "获得员工排班信息")
    @GetMapping("/get-emp-scheduling")
    @ResponseBody
    @Override
    public JsonVO<ScheduleClassesDTO> getEmployeeSchedulingInfo(EmployeeSchedulingInfoQuery employeeSchedulingInfoQuery) {
        return null;
    }
}
