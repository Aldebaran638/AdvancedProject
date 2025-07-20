package com.zeroone.star.project.vo.j2.orgmanager.functionAuth;

import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.AllArgsConstructor;
import lombok.Data;
import lombok.NoArgsConstructor;

@ApiModel("获取指定角色分配的权限")
@Data
@NoArgsConstructor
@AllArgsConstructor
public class GetRolePermissionVO extends GetMenuTreeVO{
    @ApiModelProperty(value = "状态代码", example = "0")
    private String statusCd;

}
