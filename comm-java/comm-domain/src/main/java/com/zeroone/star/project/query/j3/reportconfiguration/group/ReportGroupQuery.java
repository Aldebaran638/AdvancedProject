package com.zeroone.star.project.query.j3.reportconfiguration.group;

import com.zeroone.star.project.query.PageQuery;
import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;
@ApiModel("查询报表组信息查询模型")
@Data
public class ReportGroupQuery extends PageQuery {

    @ApiModelProperty(value = "组ID",example ="102021111007300001" )
    private String groupId;
    @ApiModelProperty(value = "组名称",example = "报修报表")
    private String name;
    @ApiModelProperty(value = "组url",example = "/#/pages/property/custom.html")
    private String url;

}
