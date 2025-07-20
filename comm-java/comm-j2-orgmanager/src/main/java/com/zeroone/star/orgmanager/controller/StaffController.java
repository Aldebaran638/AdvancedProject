package com.zeroone.star.orgmanager.controller;



import com.zeroone.star.orgmanager.service.lStaffService;
import com.zeroone.star.project.dto.PageDTO;
import com.zeroone.star.project.dto.j2.orgmanager.AddStaffDTO;
import com.zeroone.star.project.dto.j2.orgmanager.StaffDTO;
import com.zeroone.star.project.j2.orgmanager.StaffApis;
import com.zeroone.star.project.query.j2.orgmanager.StaffQuery;
import com.zeroone.star.project.vo.JsonVO;
import io.swagger.annotations.Api;
import io.swagger.annotations.ApiImplicitParam;
import io.swagger.annotations.ApiOperation;
import org.springframework.validation.annotation.Validated;
import org.springframework.web.bind.annotation.*;

import javax.annotation.Resource;
import java.util.List;

/**
 * <p>
 * 员工管理控制器
 * </p>
 *
 * @author 瓜田里犯了错
 **/
@Api(tags = "组织管理-数据权限-员工关联")
@RequestMapping("/orgmanager/dataprivilege")
@RestController
public class StaffController implements StaffApis {

    @Resource
    lStaffService lservice;


    @ApiOperation(value = "获取关联员工列表（条件+分页）")
    @GetMapping("/staff")
    @Override
    public JsonVO<PageDTO<StaffDTO>> queryStaff(@Validated StaffQuery condition) {
        return JsonVO.success(lservice.listAll(condition));
    }


    @ApiOperation(value = "新增关联员工")
    @PutMapping("/staff")
    @Override
    public JsonVO<Integer> addStaff(@Validated @RequestBody AddStaffDTO addStaffDTO) {
        return lservice.saveStaff(addStaffDTO);
    }


    @ApiOperation(value = "删除关联员工")
    @ApiImplicitParam(name = "staffId", value = "关联员工ID", required = true, example = "102023031146610004")
    @DeleteMapping("/staff/{staffId}")
    @Override
    public JsonVO<String> removeStaff(@PathVariable String staffId) {
        return lservice.removeStaff(staffId);
    }
}
