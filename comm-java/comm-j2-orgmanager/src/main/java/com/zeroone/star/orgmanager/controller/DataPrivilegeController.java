package com.zeroone.star.orgmanager.controller;


import com.zeroone.star.orgmanager.entity.DataPrivilege;
import com.zeroone.star.orgmanager.service.IDataPrivilegeService;
import com.zeroone.star.orgmanager.service.serviceImpl.MsDataPrivilegeMapper;
import com.zeroone.star.project.dto.j2.orgmanager.DataPrivilegeAddDTO;
import com.zeroone.star.project.dto.j2.orgmanager.dataPrivilege.DataPrivilegeDTO;
import com.zeroone.star.project.j2.orgmanager.DataPrivilegeApis;
import com.zeroone.star.project.vo.JsonVO;
import io.swagger.annotations.Api;
import io.swagger.annotations.ApiImplicitParam;
import io.swagger.annotations.ApiOperation;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.web.bind.annotation.*;

import java.time.LocalDateTime;
import java.util.List;

/**
 * <p>
 *  前端控制器
 * </p>
 *
 * @author hubery
 * @since 2025-05-19
 */
@RestController
@RequestMapping("/j2-orgmanager/data")
@Api(tags = "组织管理-数据权限")
public class DataPrivilegeController implements DataPrivilegeApis {

    @Autowired
    private IDataPrivilegeService service;
    @Autowired
    private MsDataPrivilegeMapper ms;


    @Override
    @ApiOperation(value = "获取数据权限列表（条件+分页）")
    @GetMapping("/dataPrivilege/{communityId}")
    public JsonVO<List<DataPrivilegeDTO>> queryAll(@PathVariable(value = "communityId") String communityId) {
        return JsonVO.success(service.listAll(communityId));
    }


    @Override
    @ApiOperation(value = "添加数据权限")
    @PostMapping("/add")
    public JsonVO<String> addDataPrivilege(@RequestBody DataPrivilegeAddDTO addDTO) {
        DataPrivilege dataPrivilege = ms.addDtoToDo(addDTO);
        dataPrivilege.setStatusCd("0");
        dataPrivilege.setCreateTime(LocalDateTime.now());
        if(service.save(dataPrivilege)) {
            return JsonVO.success(dataPrivilege.getDpId());
        }
        return JsonVO.fail(null);
    }



//    @GetMapping("/data-privilege/{dpId}")
//    @ApiImplicitParam(name = "dpId", value = "数据权限编号", required = true )
//    @ApiOperation("根据id查询数据权限信息")
//    @Override
//    public JsonVO<DataPrivilegeDTO> queryDataPrivilege(@PathVariable(value = "dpId") String dpId) {
//        return JsonVO.success(ms.doToDto(service.getById(dpId)));
//    }


    @PutMapping("/data-privilege")
    @ApiOperation("修改数据权限")
    @Override
    public JsonVO<String> modifyDataPrivilege(@RequestBody DataPrivilegeDTO dto) {
        DataPrivilege dataPrivilege = ms.dtoToDo(dto);
        dataPrivilege.setStatusCd("0");
        if(service.updateById(dataPrivilege)) {
            return JsonVO.success(dataPrivilege.getDpId());
        }
        return JsonVO.fail(null);
    }


    @Override
    @ApiOperation(value = "删除数据权限")
    @ApiImplicitParam(name = "dpId", value = "数据权限编号", required = true )
    @DeleteMapping("/delete/{dpId}")
    public JsonVO<String> deleteDataPrivilege(@PathVariable(value = "dpId") String dpId) {
        // 先查询出该数据
        DataPrivilege dataPrivilege = service.getById(dpId);
        if(dataPrivilege == null){
            return JsonVO.fail(null);
        }
        dataPrivilege.setStatusCd("1");// 修改数据状态为不可用
        if(service.updateById(dataPrivilege)) { //更新数据
            return JsonVO.success(dataPrivilege.getDpId());
        }
        return JsonVO.fail(null);
    }
}

