package com.zeroone.star.project.query.j4.datamanager;

import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;

/**
 * 查询不加入小区列表
 * @author: 玺朽
 */

@Data
@ApiModel("查询不加入小区列表")
public class NoJoinCommunityQuery {
    @ApiModelProperty(value = "业务id", example = "10202305221014333605000192", required = true)
    private String communityMemberId;
}
