package com.zeroone.star.project.query.j2.orgmanager.rolePermission;

import com.zeroone.star.project.query.PageQuery;
import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;
import lombok.EqualsAndHashCode;

/**
 * 获取角色关联小区查询对象
 * 适用于获取已关联/可关联小区列表
 */

@EqualsAndHashCode(callSuper = true)
@Data
@ApiModel("获取角色已关联小区查询对象")
public class GetAssociatedRoleCommunitiesQuery extends PageQuery {

    @ApiModelProperty(value = "角色ID", example = "6002022082274690021", required = true)
    private String roleId;

}
