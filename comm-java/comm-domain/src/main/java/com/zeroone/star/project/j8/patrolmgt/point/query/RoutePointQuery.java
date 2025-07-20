package com.zeroone.star.project.j8.patrolmgt.point.query;

import com.zeroone.star.project.query.PageQuery;
import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;
@Data
@ApiModel("巡检路线巡检点查询模型")
public class RoutePointQuery extends PageQuery {
    @ApiModelProperty(value = "社区id" ,example = "2024022647620054" ,required = true)
    private String communityId;
    @ApiModelProperty(value = "巡检路线id",example = "502024021607110704",required = true)
    private String inspectionRouteId;


}