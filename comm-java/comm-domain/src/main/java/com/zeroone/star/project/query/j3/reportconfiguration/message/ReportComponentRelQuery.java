package com.zeroone.star.project.query.j3.reportconfiguration.message;

import com.zeroone.star.project.query.PageQuery;
import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.AllArgsConstructor;
import lombok.Data;

import javax.validation.constraints.Min;

/**
 * 关联组件查询条件
 */
@ApiModel("关联组件查询条件")
@Data
@AllArgsConstructor
public class ReportComponentRelQuery extends PageQuery{
//
//    @ApiModelProperty(value = "组件关系编号", example = "102025051509590009")
//    private String relId;

    @ApiModelProperty(value = "报表编号", required = true)
    private String customId;
}
