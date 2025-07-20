package com.zeroone.star.project.query.j1.menumana.menuitem;

import com.zeroone.star.project.query.PageQuery;
import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;
import lombok.EqualsAndHashCode;

import javax.validation.constraints.NotBlank;
import javax.validation.constraints.NotEmpty;

@EqualsAndHashCode(callSuper = true)
@Data
@ApiModel("菜单项查询对象")
public class MenuItemQuery extends PageQuery {
    /*
    查询条件 组名称（不支持模糊查询） 菜单名称（支持模糊查询）
    */
    @NotBlank(message = "菜单id不能为空")
    @ApiModelProperty(value = "组名", example = "商家")
    private String groupName;
    @NotBlank(message = "菜单项名称不能为空")
    @ApiModelProperty(value = "菜单项名称", example = "员工信息")
    private String menuName;
}
