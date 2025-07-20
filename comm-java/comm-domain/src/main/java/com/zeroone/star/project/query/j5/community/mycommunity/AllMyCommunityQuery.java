package com.zeroone.star.project.query.j5.community.mycommunity;

import com.zeroone.star.project.query.PageQuery;
import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;

@Data
@ApiModel("查询所有我的小区查询参数")
public class AllMyCommunityQuery extends PageQuery {
    @ApiModelProperty(value = "小区名称",example = "HC演示小区3")
    private String name;
}
