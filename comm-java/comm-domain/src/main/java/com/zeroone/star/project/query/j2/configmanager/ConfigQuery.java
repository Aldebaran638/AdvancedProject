package com.zeroone.star.project.query.j2.configmanager;

import com.zeroone.star.project.query.PageQuery;
import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;

@Data
@ApiModel("配置查询")
public class ConfigQuery extends PageQuery {
    @ApiModelProperty(value = "名称", example = "移动短信地址")
    private String name;

    @ApiModelProperty(value = "键", example = "yidong_url")
    private String key;

    @ApiModelProperty(value = "配置项",example = "环境配置")
    private String domain;
}
