package com.zeroone.star.project.query.j6.datamanagement.importtemplate;

import com.fasterxml.jackson.annotation.JsonProperty;
import com.zeroone.star.project.query.PageQuery;
import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;
import lombok.EqualsAndHashCode;

/*
 *描述 ：
 *Author:28768
 */
@EqualsAndHashCode(callSuper = true)
@Data
@ApiModel("获取模版列表查询对象")
public class TemplatePageQuery extends PageQuery {

    @ApiModelProperty(value = "文件名",example = "小区信息导出模板")
    @JsonProperty("name")
    private String name;
}
