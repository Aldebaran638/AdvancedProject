package com.zeroone.star.project.vo.j2.orgmanager.rolePermission;

import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;

import javax.validation.constraints.NotBlank;

/**
 * 可关联角色小区对象
 * 适用于获取可关联小区列表
 */

@ApiModel("可关联角色小区对象")
public class UnassociatedRoleCommunityVO extends AssociatedRoleCommunityVO {

    @ApiModelProperty(value = "小区地址", example = "浙江省杭州市上城区西湖边", required = true)
    @NotBlank(message = "小区地址不能为空")
    private String community_address;

}
