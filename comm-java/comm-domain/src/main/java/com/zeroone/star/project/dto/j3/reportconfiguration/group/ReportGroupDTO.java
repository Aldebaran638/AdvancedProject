package com.zeroone.star.project.dto.j3.reportconfiguration.group;

import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;
@ApiModel("报表组信息模型")
@Data
public class ReportGroupDTO {
    @ApiModelProperty(value = "组ID",example ="102021111007300001" )
    private String groupId;
    @ApiModelProperty(value = "组名称",example = "报修报表")
    private String name;
    @ApiModelProperty(value = "组url",example = "/#/pages/property/custom.html")
    private String url;
    @ApiModelProperty(value = "描述",example = "保修报表")
    private String remark;
}
