package com.zeroone.star.patrolmgt.controller;

import com.zeroone.star.patrolmgt.service.InspectionPlanService;
import com.zeroone.star.project.j8.patrolmgt.plan.InspectionPlanApis;
import com.zeroone.star.project.j8.patrolmgt.plan.dto.InspectionPlanDTO;
import com.zeroone.star.project.j8.patrolmgt.plan.dto.InspectionPlanModifyDTO;
import com.zeroone.star.project.vo.JsonVO;
import com.zeroone.star.project.vo.ResultStatus;
import io.swagger.annotations.Api;
import io.swagger.annotations.ApiOperation;
import org.springframework.web.bind.annotation.*;

import com.baomidou.mybatisplus.core.metadata.IPage;
import com.baomidou.mybatisplus.extension.plugins.pagination.Page;
import com.zeroone.star.patrolmgt.entity.InspectionPlan;
import com.zeroone.star.patrolmgt.service.InspectionPlanService;
import com.zeroone.star.project.dto.PageDTO;
import com.zeroone.star.project.j8.patrolmgt.plan.InspectionPlanApis;
import com.zeroone.star.project.j8.patrolmgt.plan.dto.PlanDTO;
import com.zeroone.star.project.j8.patrolmgt.plan.dto.PlanHeadDetailDTO;
import com.zeroone.star.project.j8.patrolmgt.plan.query.PlanQuery;
import com.zeroone.star.project.vo.JsonVO;
import io.swagger.annotations.Api;
import io.swagger.annotations.ApiOperation;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RestController;

@RestController
@RequestMapping("/j8-patrolmgt/plan")
@Api(tags = "巡检计划")
public class InspectionPlanController implements InspectionPlanApis {

    private final InspectionPlanService inspectionPlanService;

    public InspectionPlanController(InspectionPlanService inspectionPlanService) {
        this.inspectionPlanService = inspectionPlanService;
    }
    @Autowired
    private InspectionPlanService planService;

    @ApiOperation("获取巡检计划列表（条件+分页）")
    @GetMapping("/query-plan-list")
    @Override
    public JsonVO<PageDTO<PlanDTO>> queryPlanList(PlanQuery query) {
        Page<InspectionPlan> page = new Page<>(query.getPageIndex(), query.getPageSize());
        IPage<PlanDTO> result = planService.queryPlanList(page, query);
        // 使用 PageDTO 的静态方法创建实例
        PageDTO<PlanDTO> pageDTO = new PageDTO<>();
        pageDTO.setPageIndex(result.getCurrent());
        pageDTO.setPageSize(result.getSize());
        pageDTO.setTotal(result.getTotal());
        pageDTO.setPages(result.getPages());
        pageDTO.setRows(result.getRecords());
        return JsonVO.success(pageDTO);
    }

    @ApiOperation("获取巡检计划详情")
    @GetMapping("/query-plan-detail")
    @Override
    public JsonVO<PlanHeadDetailDTO> queryPlanDetail(String planId) {
        PlanHeadDetailDTO detail = planService.getPlanDetail(planId);
        if (detail == null) {
            return JsonVO.fail(null);
        }
        return JsonVO.success(detail);
    }

    @ApiOperation(value = "添加巡检计划")
    @PostMapping("/add-inspection-plan")
    @Override
    public JsonVO<ResultStatus> addInspectionPlan(@RequestBody InspectionPlanDTO inspectionPlanDTO) {
        inspectionPlanService.addInspectionPlan(inspectionPlanDTO);
        return JsonVO.success(ResultStatus.SUCCESS);
    }

    @ApiOperation(value = "修改巡检计划")
    @PutMapping("/modify-inspection-plan")
    @Override
    public JsonVO<ResultStatus> modifyInspectionPlan(@RequestBody InspectionPlanModifyDTO inspectionPlanModifyDTO) {
        inspectionPlanService.updateInspectionPlan(inspectionPlanModifyDTO);
        return JsonVO.success(ResultStatus.SUCCESS);
    }

    @ApiOperation(value = "删除巡检计划")
    @DeleteMapping("/remove-inspection-plan/{inspectionPlanId}")
    @Override
    public JsonVO<ResultStatus> removeInspectionPlan(@PathVariable String inspectionPlanId) {
        inspectionPlanService.removeInspectionPlan(inspectionPlanId);
        return JsonVO.success(ResultStatus.SUCCESS);
    }

    @ApiOperation(value = "停用巡检计划")
    @GetMapping("/modify-inspection-plan-state")
    @Override
    public JsonVO<ResultStatus> modifyInspectionPlanState(@RequestParam String inspectionPlanId, @RequestParam String state) {
        inspectionPlanService.updateInspectionPlanState(inspectionPlanId,state);
        return JsonVO.success(ResultStatus.SUCCESS);
    }
}
