package com.zeroone.star.project.dto.j2.orgmanager.rolemanage;

import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;


/**
 * <p>
 * 描述：添加角色数据传输模型
 * </p>
 * <p>版权：&copy;01星球</p>
 * <p>地址：01星球总部</p>
 * @author LYZlearn
 * @version 1.0.0
 */

@ApiModel("添加角色")
@Data
public class RoleAddDTO {

    @ApiModelProperty(value = "角色名称", example = "管理员角色",required = true)
    private String name;

    @ApiModelProperty(value = "顺序", example = "1")
    private String seq;

    @ApiModelProperty(value = "角色描述", example = "保洁部门人员")
    private String description;

}
