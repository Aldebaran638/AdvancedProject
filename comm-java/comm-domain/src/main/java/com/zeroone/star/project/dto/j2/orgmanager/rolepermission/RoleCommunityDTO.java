package com.zeroone.star.project.dto.j2.orgmanager.rolePermission;

import com.zeroone.star.project.dto.PageDTO;
import com.zeroone.star.project.query.PageQuery;
import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;

import javax.validation.constraints.NotBlank;

/**
 * 关联小区模型
 * 适用于添加和删除关联小区
 */

@ApiModel(value = "添加关联小区模型")
@Data
public class RoleCommunityDTO{
    @ApiModelProperty(value = "记录ID", example = "102025051938291445", required = true)
    @NotBlank(message = "记录不能为空")
    String rcId;

    @ApiModelProperty(value = "角色ID", example = "6002022082274690021", required = true)
    @NotBlank(message = "角色ID不能为空")
    String roleId;

    @ApiModelProperty(value = "小区ID", example = "2024022692080516", required = true)
    @NotBlank(message = "小区ID不能为空")
    String communityId;

    @ApiModelProperty(value = "启用状态", example = "1", required = true)
    @NotBlank(message = "启用状态不能为空")
    String statusCd;

    @ApiModelProperty(value = "小区名称", example = "Y小区", required = true)
    @NotBlank(message = "小区名称不能为空")
    String communityName;
}
