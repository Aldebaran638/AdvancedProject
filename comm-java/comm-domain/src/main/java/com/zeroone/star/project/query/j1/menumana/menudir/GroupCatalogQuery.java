package com.zeroone.star.project.query.j1.menumana.menudir;

import com.zeroone.star.project.query.PageQuery;
import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;

import javax.validation.constraints.Min;
import javax.validation.constraints.NotBlank;
import javax.validation.constraints.NotNull;
import javax.validation.constraints.Pattern;

@ApiModel(value = "获取对应菜单组列表(条件+分页)请求参数")
@Data
public class GroupCatalogQuery{
    /**
     * 菜单目录编号
     */
    @ApiModelProperty(value = "菜单目录编号",example = "102022022695140008",required = true)
    @NotBlank(message = "菜单目录编号不能为空")
    @Pattern(regexp = "^\\d{18}$", message = "菜单目录编号必须为18位数字")
    private String caId;
    /**
     * 商户类型
     */
    @ApiModelProperty(value = "商户类型",example = "800900000000",required = true)
    @NotBlank(message = "商户类型不能为空")
    @Pattern(regexp = "^\\d{12}$", message = "商户类型必须为12位数字")
    private String storeType;

    /**
     * 查询页码
     */
    @Min(value = 1, message = "页码最小值为1")
    @ApiModelProperty(value = "查询页码", example = "1",required = true)
    private long pageIndex;
    /**
     * 查询条数
     */
    @Min(value = 1, message = "条数最小值为1")
    @ApiModelProperty(value = "查询条数", example = "10",required = true)
    private long pageSize;
}
