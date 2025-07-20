package com.zeroone.star.project.j8.housemgt.committee.query;

import com.zeroone.star.project.query.PageQuery;
import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;

@Data
@ApiModel("业委会列表查询模型")
public class CommitteeListQuery extends PageQuery {

    @ApiModelProperty(value = "姓名", example = "张三")
    private String name;  // 请选择姓名

    @ApiModelProperty(value = "电话", example = "18909711425")
    private String link;  // 请选择电话

    @ApiModelProperty(value = "状态", example = "1000")
    private String state;  // 请选择状态
}