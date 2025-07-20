package com.zeroone.star.project.dto.j2.configmanager.config;

import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;

@Data
@ApiModel("添加配置项")
public class ConfigDTO extends ConfigAddDTO{
    @ApiModelProperty(value = "配置项编号", example = "1")
    private Long id;
}
