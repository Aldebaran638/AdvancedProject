package com.zeroone.star.project.query.j2.orgmanager.functionAuth;

import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.AllArgsConstructor;
import lombok.Data;
import lombok.NoArgsConstructor;

@ApiModel("获取菜单名称树对象")
@Data
@NoArgsConstructor
@AllArgsConstructor
public class GetMenuTreeQuery {
    @ApiModelProperty(value = "商户类型id--用来查询出不同的菜单树", example = "111",required = true)
    private String storeId;
    @ApiModelProperty(value = "角色种类--user,admin", example = "User",required = false)
    private String roleType;
}

