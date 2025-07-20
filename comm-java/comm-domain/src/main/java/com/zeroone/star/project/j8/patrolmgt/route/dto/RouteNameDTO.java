package com.zeroone.star.project.j8.patrolmgt.route.dto;

import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.AllArgsConstructor;
import lombok.Data;
import lombok.NoArgsConstructor;

@ApiModel("巡检路线名称数据传输模型")
@AllArgsConstructor
@NoArgsConstructor
@Data
public class RouteNameDTO {

    @ApiModelProperty(value = "路线名称", example = "沈工大路线")
    private  String routeName;
}
