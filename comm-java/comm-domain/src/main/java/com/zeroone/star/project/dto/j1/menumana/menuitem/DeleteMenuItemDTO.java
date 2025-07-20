package com.zeroone.star.project.dto.j1.menumana.menuitem;

import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;

import javax.validation.constraints.NotBlank;
import java.io.Serializable;

/**
 * @Description
 * @Author eu
 * @Date 2025/5/21
 */
@Data
@ApiModel("删除菜单项数据传输对象")
public class DeleteMenuItemDTO implements Serializable {
    @NotBlank(message = "菜单项ID不能为空")
    //@Pattern(regexp = "^[1-9]+$", message = "菜单项ID必须为正整数")
    @ApiModelProperty(value = "菜单项ID", example = "1",required = true)
    private String mid;
}
