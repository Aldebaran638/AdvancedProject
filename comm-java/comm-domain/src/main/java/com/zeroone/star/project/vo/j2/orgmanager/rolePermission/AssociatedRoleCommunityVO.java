package com.zeroone.star.project.vo.j2.orgmanager.rolePermission;


import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;

/**
 * 已关联角色小区对象
 * 适用于获取已关联小区列表
 */

@ApiModel("已关联角色小区对象")
@Data
public class AssociatedRoleCommunityVO {

    @ApiModelProperty(value = "小区ID", example = "2025052264550142", required = true)
    private String community_id;

    @ApiModelProperty(value = "小区名称", example = "Y小区", required = true)
    private String community_name;
}
