package com.zeroone.star.project.j2.orgmanager;

import com.zeroone.star.project.dto.j2.orgmanager.rolemanage.RoleAddDTO;
import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;

import javax.validation.constraints.NotBlank;

/**
 * <p>
 * 描述：修改角色数据传输模型
 * </p>
 * <p>版权：&copy;01星球</p>
 * <p>地址：01星球总部</p>
 * @author LYZlearn
 * @version 1.0.0
 */

@ApiModel("修改角色")
@Data
public class RoleDTO extends RoleAddDTO {

    @ApiModelProperty(value = "角色id" ,example = "6002025051438010007",required = true)
    @NotBlank(message = "id不能为空")
    private String pg_id;

}
