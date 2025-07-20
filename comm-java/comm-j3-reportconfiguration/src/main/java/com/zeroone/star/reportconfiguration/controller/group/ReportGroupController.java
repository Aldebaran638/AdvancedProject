package com.zeroone.star.reportconfiguration.controller.group;

import com.zeroone.star.project.dto.PageDTO;
import com.zeroone.star.project.dto.j3.reportconfiguration.group.ReportGroupDTO;
import com.zeroone.star.project.dto.j3.reportconfiguration.group.AddGroupDTO;
import com.zeroone.star.project.dto.j3.reportconfiguration.group.GroupDTO;
import com.zeroone.star.project.j3.reportconfiguration.group.ReportGroupApis;
import com.zeroone.star.project.query.j3.reportconfiguration.component.RCCQuery;
import com.zeroone.star.project.query.j3.reportconfiguration.group.ReportGroupQuery;
import com.zeroone.star.project.vo.JsonVO;
import com.zeroone.star.project.vo.j3.reportconfiguration.component.RCCVO;
import com.zeroone.star.project.vo.j3.reportconfiguration.group.ReportGroupVO;
import com.zeroone.star.reportconfiguration.service.IReportGroupService;
import io.swagger.annotations.Api;
import io.swagger.annotations.ApiOperation;
import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RestController;
import io.swagger.annotations.ApiImplicitParam;
import org.springframework.web.bind.annotation.*;

import javax.annotation.Resource;
import java.util.List;


@RestController
@RequestMapping("j3-report/report-group")
@Api(tags = "报表组")
public class ReportGroupController implements ReportGroupApis {

    @Resource
    IReportGroupService iReportGroupService;
    @ApiOperation("获取报表组列表（条件+分页）")
    @GetMapping("/query-all")
    @Override
    public JsonVO<PageDTO<ReportGroupVO>> queryAll(ReportGroupQuery query) {
        PageDTO<ReportGroupVO> groupList = iReportGroupService.getGroupList(query);
        if(groupList.getTotal()==0){
            return JsonVO.fail(null);
        }

        return JsonVO.success(iReportGroupService.getGroupList(query));
    }

    @ApiOperation("获取报表组名称列表")
    @GetMapping("/query-report-component-name")
    @Override
    public JsonVO<List<ReportGroupVO>> queryReportConfigurationName() {
        return JsonVO.success(iReportGroupService.getGroupNameList());
    }
    @ApiOperation(value = "添加报表组")
    @PostMapping ("/add-group")
    @Override
    public JsonVO<String> addGroup(@RequestBody AddGroupDTO addGroupDTO) {
        String groupId = iReportGroupService.saveGroup(addGroupDTO);
        return JsonVO.success(groupId);
    }

    @ApiOperation(value = "修改报表组")
    @PutMapping("/modify-group")
    @Override
    public JsonVO<String> modifyGroup(@RequestBody GroupDTO groupDTO) {
        Integer cnt = iReportGroupService.updateGroup(groupDTO);
        String groupId = groupDTO.getGroupId();
        if(cnt > 0) return JsonVO.success(groupId);
        return JsonVO.fail(groupId + "不存在");
    }

    @ApiOperation(value = "删除报表组")
    @ApiImplicitParam(name = "groupId", value = "组ID", required = true)
    @DeleteMapping("/remove-group")
    @Override
    public JsonVO<String> removeGroup(String groupId) {
        Integer cnt = iReportGroupService.removeGroup(groupId);
        if(cnt > 0) return JsonVO.success(groupId);
        return JsonVO.fail(groupId + "不存在");
    }
}
