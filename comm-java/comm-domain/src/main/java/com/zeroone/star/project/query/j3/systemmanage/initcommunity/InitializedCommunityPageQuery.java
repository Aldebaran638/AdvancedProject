package com.zeroone.star.project.query.j3.systemmanage.initcommunity;

import com.zeroone.star.project.query.PageQuery;
import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;

/**
 * 初始化小区查询数据模型
 */
@ApiModel(value = "初始化小区查询数据模型")
@Data
public class InitializedCommunityPageQuery extends PageQuery {

    @ApiModelProperty(value = "小区id" , example = "2024021911282483")
    private String communityId;

    @ApiModelProperty(value = "小区名称", example = "万科森林公园")
    private String name;
}
