package com.zeroone.star.project.query.j2.orgmanager.dataPrivilege;

import com.zeroone.star.project.query.PageQuery;
import io.swagger.annotations.Api;
import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;

/**
 * 查询数据权限
 * @author: zake
 */
@ApiModel(value = "查询数据权限模型")
@Data
public class DataPrivilegeQuery extends PageQuery {

    @ApiModelProperty(value = "编号",example = "2")
    String code;
    @ApiModelProperty(value = "小区ID",example = "2025041251140067")
    String communityId;
    @ApiModelProperty(value = "用户ID",example = "102025051938291445")
    String dpId;
    @ApiModelProperty(value = "权限名称",example = "权限名称")
    String name;
}
