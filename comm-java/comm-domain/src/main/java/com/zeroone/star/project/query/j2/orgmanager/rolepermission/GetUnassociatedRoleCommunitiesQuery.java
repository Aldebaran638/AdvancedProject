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
@ApiModel("获取角色可关联小区查询对象")
public class GetUnassociatedRoleCommunitiesQuery extends GetAssociatedRoleCommunitiesQuery {

    @ApiModelProperty(value = "搜索关键词（小区名称）", example = "Y", required = false)
    private String searchKeyword;

}
