package com.zeroone.star.project.query.j4.datamanager;

import com.zeroone.star.project.query.PageQuery;
import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;

/**
 * 查询加入小区列表
 * @author: 玺朽
 */

@Data
@ApiModel("查询加入小区列表")
public class JoinCommunityQuery extends PageQuery {
    @ApiModelProperty(value = "物业id", example = "10202305221014333605000192",  required = true)
    private String communityMemberId;
    @ApiModelProperty(value = "小区id", example = "2024022692080516",  required = false)
    private String communityId;
    @ApiModelProperty(value = "小区名称", example = "YF小区",  required = false)
    private String communityName;
}
