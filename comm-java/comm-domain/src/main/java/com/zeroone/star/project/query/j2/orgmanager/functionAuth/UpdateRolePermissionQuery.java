package com.zeroone.star.project.query.j2.orgmanager.functionAuth;

import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.AllArgsConstructor;
import lombok.Data;
import lombok.NoArgsConstructor;

@ApiModel("更新角色权限传入对象")
@Data
@NoArgsConstructor
@AllArgsConstructor
public class UpdateRolePermissionQuery {
    @ApiModelProperty(value = "角色Id--用来表示谁修改的", example = "6002",required = true)
    private String pgId;

    @ApiModelProperty(value = "权限ID,对应某个权限内容", example = "6002022022407141135")
    private String pId;

    @ApiModelProperty(value = "数据状态,0在用；1失效", example = "0")
    private String statusCd;

    @ApiModelProperty(value = "商户ID，用来区分不同的菜单树", example = "402021080402040153")
    private String storeId;

}
