package com.zeroone.star.project.dto.j2.orgmanager.rolePermission;


import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;

/**
 * 已关联角色小区对象
 * 适用于获取已关联小区列表
 */

@ApiModel("已关联角色小区对象")
@Data
public class AssociatedRoleCommunityDTO {

    @ApiModelProperty(value = "关联ID", example = "1929833304263725057", required = true)
    private String rcId;

    @ApiModelProperty(value = "小区ID", example = "2025052264550142", required = true)
    private String communityId;

    @ApiModelProperty(value = "小区名称", example = "Y小区", required = true)
    private String communityName;
}
