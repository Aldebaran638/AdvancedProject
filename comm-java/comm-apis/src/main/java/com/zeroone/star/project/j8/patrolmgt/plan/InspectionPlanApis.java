package com.zeroone.star.project.j8.patrolmgt.plan;

import com.zeroone.star.project.j8.patrolmgt.plan.dto.InspectionPlanDTO;
import com.zeroone.star.project.j8.patrolmgt.plan.dto.InspectionPlanModifyDTO;
import com.zeroone.star.project.vo.JsonVO;
import com.zeroone.star.project.vo.ResultStatus;

import com.zeroone.star.project.dto.PageDTO;
import com.zeroone.star.project.j8.patrolmgt.plan.dto.PlanDTO;
import com.zeroone.star.project.j8.patrolmgt.plan.dto.PlanHeadDetailDTO;
import com.zeroone.star.project.j8.patrolmgt.plan.query.PlanQuery;
import com.zeroone.star.project.vo.JsonVO;

public interface InspectionPlanApis {

    /*
     * 查询巡检计划列表
     * @Param query 查询条件
     * @return 巡检计划列表
     */
    JsonVO<PageDTO<PlanDTO>> queryPlanList(PlanQuery query);

    JsonVO<PlanHeadDetailDTO> queryPlanDetail(String planId);

    /**
     * 添加巡检计划
     *
     * @param inspectionPlanDTO 巡检计划信息
     * @return 添加结果
     */
    JsonVO<ResultStatus> addInspectionPlan(InspectionPlanDTO inspectionPlanDTO);

    /**
     * 修改巡检计划
     *
     * @param inspectionPlanModifyDTO 巡检计划信息
     * @return 修改结果
     */
    JsonVO<ResultStatus> modifyInspectionPlan(InspectionPlanModifyDTO inspectionPlanModifyDTO);

    /**
     * 删除巡检计划
     *
     * @param id 巡检计划id
     * @return 删除结果
     */
    JsonVO<ResultStatus> removeInspectionPlan(String id);

    /**
     * 修改巡检计划状态
     *
     * @param id    巡检计划id
     * @param state 状态
     * @return 修改结果
     */
    JsonVO<ResultStatus> modifyInspectionPlanState(String id, String state);
}

