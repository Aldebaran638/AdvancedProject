package com.zeroone.star.project.dto.j1.menumana.menudir;

import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.AllArgsConstructor;
import lombok.Data;
import lombok.NoArgsConstructor;

import javax.validation.constraints.NotBlank;
import javax.validation.constraints.Pattern;

@ApiModel(value = "添加对应菜单组请求参数")
@Data
@AllArgsConstructor
@NoArgsConstructor
public class GroupCatalogAddDTO {
    /**
     * 菜单目录编号
     */
    @ApiModelProperty(value = "菜单目录编号",example = "102022022695140008",required = true)
    @NotBlank(message = "菜单目录编号不能为空")
    @Pattern(regexp = "^\\d{18}$", message = "菜单目录编号必须为18位数字")
    private String caId;
    /**
     * 商户类型编号
     */
    @ApiModelProperty(value = "商户类型",example = "800900000000",required = true)
    @NotBlank(message = "商户类型不能为空")
    @Pattern(regexp = "^\\d{12}$", message = "商户类型必须为12位数字")
    private String storeType;
    /**
     * 菜单组编号
     */
    @ApiModelProperty(value = "菜单组编号",example = "802021031653410070",required = true)
    @NotBlank(message = "菜单组编号不能为空")
    @Pattern(regexp = "^\\d{18}$", message = "菜单组编号必须为18位数字")
    private String gid;
}
