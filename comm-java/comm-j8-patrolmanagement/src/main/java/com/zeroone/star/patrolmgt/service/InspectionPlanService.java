package com.zeroone.star.patrolmgt.service;

import com.baomidou.mybatisplus.core.metadata.IPage;
import com.baomidou.mybatisplus.extension.plugins.pagination.Page;
import com.baomidou.mybatisplus.extension.service.IService;
import com.zeroone.star.patrolmgt.entity.InspectionPlan;
import com.zeroone.star.patrolmgt.entity.InspectionPlanStaff;
import com.zeroone.star.project.dto.PageDTO;
import com.zeroone.star.project.j8.patrolmgt.plan.dto.PlanDTO;
import com.zeroone.star.project.j8.patrolmgt.plan.dto.PlanHeadDetailDTO;
import com.zeroone.star.project.j8.patrolmgt.plan.query.PlanQuery;

import com.baomidou.mybatisplus.extension.service.IService;
import com.zeroone.star.patrolmgt.entity.InspectionPlan;
import com.zeroone.star.project.j8.patrolmgt.plan.dto.InspectionPlanDTO;
import com.zeroone.star.project.j8.patrolmgt.plan.dto.InspectionPlanModifyDTO;


public interface InspectionPlanService extends IService<InspectionPlan> {
    IPage<PlanDTO> queryPlanList(Page<InspectionPlan> page, PlanQuery query);

    PlanHeadDetailDTO getPlanDetail(String planId);

    void addInspectionPlan(InspectionPlanDTO inspectionPlanDTO);

    void updateInspectionPlan(InspectionPlanModifyDTO inspectionPlanModifyDTO);

    void updateInspectionPlanState(String inspectionPlanId, String state);

    void removeInspectionPlan(String inspectionPlanId);
}
