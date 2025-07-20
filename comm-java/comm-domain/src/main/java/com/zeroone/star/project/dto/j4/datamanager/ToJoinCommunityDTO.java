package com.zeroone.star.project.dto.j4.datamanager;

import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;

/**
 * 加入小区
 * @author: 玺朽
 */
@ApiModel("加入小区")
@Data
public class ToJoinCommunityDTO {
    @ApiModelProperty(value = "小区id", example = "2023052267100146", required = true)
    private String communityId;
}
