package com.zeroone.star.project.query.j3.reportconfiguration.component;

import com.zeroone.star.project.query.PageQuery;
import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;

import javax.validation.constraints.Min;
import javax.validation.constraints.NotNull;

@ApiModel(value = "分页查询组件目录查询模型")
@Data
public class RCCQuery extends PageQuery {
    @ApiModelProperty(value = "组件id",example = "102023070480690007")
    private String componentId;
    @ApiModelProperty(value = "组件名称",example = "房屋入驻报表")
    private String name;
    @ApiModelProperty(value = "组件类型",example = "组件类型,组件组 为C时 1001 表格，2002 饼状图 等等 组件组为Q 3003 input 4004 select 5005 日期 等等")
    private String componentType;


}
