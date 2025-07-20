package com.zeroone.star.project.j8.patrolmgt.route.query;

import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.AllArgsConstructor;
import lombok.Data;
import lombok.NoArgsConstructor;


@Data
@AllArgsConstructor
@NoArgsConstructor
@ApiModel("巡检路线名称查询模型")
public class RouteNameQuery {
    @ApiModelProperty(value = "社区id" ,example = "2024022647620054",required = true)
    private String communityId;


}
