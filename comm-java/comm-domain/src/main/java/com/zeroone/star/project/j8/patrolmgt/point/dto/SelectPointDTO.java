package com.zeroone.star.project.j8.patrolmgt.point.dto;

import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;

@Data
@ApiModel("可选巡检点信息DTO")
public class SelectPointDTO {

    @ApiModelProperty(value = "巡检点ID", example = "132025051426620008")
    private String inspectionId;

    @ApiModelProperty(value = "巡检点名称", example = "库房")
    private String inspectionName;
}