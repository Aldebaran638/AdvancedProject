package com.zeroone.star.project.query.j2.orgmanager.rolePermission;

import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;

import java.util.List;

@Data
@ApiModel("添加关联小区对象")
public class PostRoleCommunityQuery {
    @ApiModelProperty(value = "角色ID", example = "6002022082274690021", required = true)
    private String roleId;

//    @ApiModelProperty(value = "商户ID", example = "400000000000000001", required = true)
//    private String storeId;

    @ApiModelProperty(value = "小区ID列表", example = "[\"2025052264550142\", \"2025052264550143\"]", required = true)
    private List<String> communityIds;

    @ApiModelProperty(value = "启用状态", example = "0", hidden = true)
    private String statusCd = "0"; // 启用状态，1表示启用，0表示禁用

}
