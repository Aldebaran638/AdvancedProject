package com.zeroone.star.project.j8.patrolmgt.plan.query;

import com.zeroone.star.project.query.PageQuery;
import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;

/**
 * @Author: huboce
 * @Date: 2025/5/20 10:00
 * @Description:
 */
@Data
@ApiModel(description = "获取巡检计划列表（条件+分页）")
public class PlanQuery extends PageQuery {
    @ApiModelProperty(value = "巡检计划ID", example = "1")
    private String inspectionPlanId;
    @ApiModelProperty(value = "巡检计划名称", example = "环境巡检计划")
    private String inspectionPlanName;
    @ApiModelProperty(value = "巡检计划状态", example = "启用")
    private String state;

}
