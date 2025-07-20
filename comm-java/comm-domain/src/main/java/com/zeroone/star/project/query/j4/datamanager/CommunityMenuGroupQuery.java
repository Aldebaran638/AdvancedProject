package com.zeroone.star.project.query.j4.datamanager;

import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;

/**
 *  查询小区属性
 *  @author 玺朽
 */
@Data
@ApiModel(value = "查询小区属性")
public class CommunityMenuGroupQuery {
    @ApiModelProperty(value = "小区id", example = "2022092200930358",required = true)
    private String communityId;
}
