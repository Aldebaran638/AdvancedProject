package com.zeroone.star.project.j8.patrolmgt.route.query;
import com.zeroone.star.project.query.PageQuery;
import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.AllArgsConstructor;
import lombok.Data;
import lombok.NoArgsConstructor;

import java.util.Date;

/**
 * 描述：巡检路线查询（条件分页查询）
 *
*/
@Data
@AllArgsConstructor
@NoArgsConstructor
@ApiModel("巡检路线查询模型")
public class RouteQuery extends PageQuery{
    //
    @ApiModelProperty(value = "社区id" ,example = "2024022647620054" ,required = true)
    private String communityId;
    //查询条件路线id
    @ApiModelProperty(value = "路线id" ,example = "502025051446110007")
    private String inspectionRouteId;
    //查询条件路线名称
    @ApiModelProperty(value = "路线名称" ,example = "沈工大路线")
    private String routeName;
    //查询条件路线顺序
    @ApiModelProperty(value = "路线顺序" ,example = "1")
    private String seq;



}
