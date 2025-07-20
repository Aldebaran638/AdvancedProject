package com.zeroone.star.project.dto.j2.configmanager.config;

import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;

import javax.validation.constraints.NotBlank;
import javax.validation.constraints.NotNull;

@Data
@ApiModel("添加配置项")
public class ConfigAddDTO {
    @ApiModelProperty(value = "域名", example = "SYSTEM_SWITCH",required = true)
    @NotBlank(message = "域名不能为空")
    private String domain;

        @ApiModelProperty(value = "配置名称", example = "系统开关",required = true)
    @NotBlank(message = "配置名称不能为空")
    private String name;

    @ApiModelProperty(value = "配置键", example = "SWITCH_OPEN",required = true)
    @NotBlank(message = "配置键不能为空")
    private String key;

    @ApiModelProperty(value = "配置值", example = "OFF",required = true)
    @NotNull(message = "配置值不能为空")
    private String value;

    @ApiModelProperty(value = "备注", example = "用于控制功能是否开启")
    private String remark;

}
