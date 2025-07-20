package com.zeroone.star.project.dto.j3.reportconfiguration.message;

import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;

@Data
@ApiModel("添加报表组件关系")
public class ComponentRelDTO {

    @ApiModelProperty(value = "组件ID", example = "102022040879310012", required = true)
    private String componentId;

    @ApiModelProperty(value = "报表编号", example = "1020211112807918355", required = true)
    private String customId;

    @ApiModelProperty(value = "序号", example = "1")
    private int seq;
}
