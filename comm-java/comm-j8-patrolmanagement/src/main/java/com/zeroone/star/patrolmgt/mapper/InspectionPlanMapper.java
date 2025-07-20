package com.zeroone.star.patrolmgt.mapper;


import com.baomidou.mybatisplus.core.mapper.BaseMapper;
import com.zeroone.star.patrolmgt.entity.InspectionPlan;
import org.apache.ibatis.annotations.Mapper;

import com.baomidou.mybatisplus.core.mapper.BaseMapper;
import com.baomidou.mybatisplus.core.metadata.IPage;
import com.baomidou.mybatisplus.extension.plugins.pagination.Page;
import com.zeroone.star.patrolmgt.entity.InspectionPlan;
import com.zeroone.star.project.j8.patrolmgt.plan.dto.PlanDTO;
import com.zeroone.star.project.j8.patrolmgt.plan.dto.PlanHeadDetailDTO;
import com.zeroone.star.project.j8.patrolmgt.plan.query.PlanQuery;
import org.apache.ibatis.annotations.Mapper;


@Mapper
public interface InspectionPlanMapper extends BaseMapper<InspectionPlan>  {

    IPage<PlanDTO> queryPlanList(Page<InspectionPlan> page, PlanQuery query);

    PlanHeadDetailDTO getPlanDetail(String planId);
}
