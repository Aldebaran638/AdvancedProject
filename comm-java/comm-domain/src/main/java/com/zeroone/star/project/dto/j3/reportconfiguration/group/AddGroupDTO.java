package com.zeroone.star.project.dto.j3.reportconfiguration.group;

import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;

@ApiModel("添加报表组对象")
@Data
public class AddGroupDTO {
    @ApiModelProperty(value = "组名称", example = "报修报表", required = true)
    private String name;
    @ApiModelProperty(value = "组url", example = "/#/pages/property/custom.html", required = true)
    private String url;
    @ApiModelProperty(value = "描述", example = "报修报表", required = true)
    private String remark;
}
