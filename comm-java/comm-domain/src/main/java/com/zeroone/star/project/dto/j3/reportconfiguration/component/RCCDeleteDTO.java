package com.zeroone.star.project.dto.j3.reportconfiguration.component;

import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;

import javax.validation.constraints.NotNull;

@ApiModel(value = "删除组件目录模型")
@Data
public class RCCDeleteDTO {
    /*
     * 组件id
     * */
    @NotNull
    @ApiModelProperty(value = "组件id",example = "102023070480690007",required = true)
    private String componentId;
}
