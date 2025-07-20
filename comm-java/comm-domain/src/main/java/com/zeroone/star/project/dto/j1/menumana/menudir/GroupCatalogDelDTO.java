package com.zeroone.star.project.dto.j1.menumana.menudir;

import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.AllArgsConstructor;
import lombok.Data;
import lombok.NoArgsConstructor;

import javax.validation.constraints.NotBlank;
import javax.validation.constraints.Pattern;

@ApiModel(value = "删除对应菜单组请求参数")
@Data
@AllArgsConstructor
@NoArgsConstructor
public class GroupCatalogDelDTO {
    /**
     * 菜单组目录编号
     */
    @ApiModelProperty(value = "菜单组目录编号",example = "102022022662880029",required = true)
    @NotBlank(message = "菜单组编号不能为空")
    @Pattern(regexp = "^\\d{18}$", message = "菜单组编号必须为18位数字")
    private String gcId;
}
