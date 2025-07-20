package com.zeroone.star.project.vo.j1.menumana.menudir;

import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;


@Data
@ApiModel(value = "查询菜单目录响应参数")
public class MenuCatalogVO {
    /**
     * 菜单目录编号
     */
    @ApiModelProperty(value = "菜单目录编号", example = "102022022645630009", required = true)
    private String caId;

    /**
     * 菜单组名称
     */
    @ApiModelProperty(value = "菜单组名称", example = "设置", required = true)
    private String name;

    /**
     * 图标
     */
    @ApiModelProperty(value = "图标", example = "fa-home", required = true)
    private String icon;

    /**
     * 顺序
     */
    @ApiModelProperty(value = "顺序", example = "1", required = true)
    private Integer seq;

    /**
     * 商户类型
     */
    @ApiModelProperty(value = "商户类型", example = "运营团队", required = true)
    private String storeType;

    /**
     * 页面
     */
    @ApiModelProperty(value = "页面",example = "/",required = true)
    private String url;

    /**
     * 是否显示
     */
    @ApiModelProperty(value = "是否显示",example = "Y",required = true)
    private String isShow;

    /**
     *权限编号
     */
    @ApiModelProperty(value = "权限编号",example = "502024012543970005",required = true)
    private String privId;

}
