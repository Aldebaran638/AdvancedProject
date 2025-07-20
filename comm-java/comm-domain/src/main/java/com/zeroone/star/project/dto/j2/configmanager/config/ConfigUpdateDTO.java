package com.zeroone.star.project.dto.j2.configmanager.config;

import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;

@ApiModel("修改配置项")
@Data
public class ConfigUpdateDTO extends ConfigAddDTO{

    @ApiModelProperty(value = "id",example = "444444444444",required = true)
    private String id;
}
