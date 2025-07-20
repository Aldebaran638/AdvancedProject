package com.zeroone.star.project.j8.patrolmgt.plan.dto;

import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;
import org.springframework.stereotype.Component;

@Data
@ApiModel(description = "巡检计划详情")
public class PlanHeadDetailDTO { // 或者 InspectionPlanDetailVO

    @ApiModelProperty(value = "巡检计划名称", example = "环境巡检计划")
    private String inspectionPlanName;

    @ApiModelProperty(value = "计划路线名称", example = "迎春园")
    private String routeName;

    @ApiModelProperty(value = "计划周期", example = "月/日")
    private String inspectionPlanPeriod;

    @ApiModelProperty(value = "签到方式", example = "现场拍照（默认定位）")
    private String signType;

    @ApiModelProperty(value = "开始日期", example = "2025-05-14")
    private String startDate;

    @ApiModelProperty(value = "结束日期", example = "2050-01-01") // 如：每日、每周、每月、自定义等
    private String endDate;

    @ApiModelProperty(value = "日期范围", example = "2025-05-14~2050-01-01")
    private String dateRange;

    @ApiModelProperty(value = "开始时间", example = "13:50")
    private String startTime;

    @ApiModelProperty(value = "结束时间", example = "14:50") // 如：每日、每周、每月、自定义等
    private String endTime;

    @ApiModelProperty(value = "时间范围", example = "13:50~14:50")
    private String timeRange;

    @ApiModelProperty(value = "任务提前（分钟）", example = "0")
    private String beforeTime;

    @ApiModelProperty(value = "创建人名称", example = "wuxw")
    private String createUserName;

    @ApiModelProperty(value = "创建时间", example = "2025-05-20 10:00:00")
    private String createTime;

    @ApiModelProperty(value = "状态", example = "启用")
    private String state;
}