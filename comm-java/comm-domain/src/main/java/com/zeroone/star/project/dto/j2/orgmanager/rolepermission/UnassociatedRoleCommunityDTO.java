package com.zeroone.star.project.dto.j2.orgmanager.rolePermission;

import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;

import javax.validation.constraints.NotBlank;

/**
 * 可关联角色小区对象
 * 适用于获取可关联小区列表
 */

@ApiModel("可关联角色小区对象")
@Data
public class UnassociatedRoleCommunityDTO {

    @ApiModelProperty(value = "小区ID", example = "2025052264550142", required = true)
    @NotBlank(message = "小区ID不能为空")
    private String communityId;

    @ApiModelProperty(value = "小区名称", example = "Y小区", required = true)
    @NotBlank(message = "小区名称不能为空")
    private String name;

    @ApiModelProperty(value = "小区地址", example = "浙江省杭州市上城区西湖边", required = true)
    @NotBlank(message = "小区地址不能为空")
    private String address;

}
