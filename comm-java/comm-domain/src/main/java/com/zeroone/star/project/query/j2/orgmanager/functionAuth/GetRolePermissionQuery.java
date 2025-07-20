package com.zeroone.star.project.query.j2.orgmanager.functionAuth;

import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.AllArgsConstructor;
import lombok.Data;
import lombok.NoArgsConstructor;

@ApiModel("获取指定角色权限传入对象")
@Data
@NoArgsConstructor
@AllArgsConstructor
public class GetRolePermissionQuery {
    @ApiModelProperty(value = "指定角色Id", example = "6002",required = true)
    private String pgId;
    @ApiModelProperty(value = "商户类型id--用来查询出不同的菜单树", example = "111",required = false)
    private String storeId;
}
