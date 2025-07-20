package com.zeroone.star.project.dto.j1.menumana.commonmenu;

import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.AllArgsConstructor;
import lombok.Data;
import lombok.NoArgsConstructor;

@Data
@AllArgsConstructor
@NoArgsConstructor
@ApiModel("查询常用菜单信息")
public class CommonMenuDTO {

    @ApiModelProperty(value = "菜单编号",example = "102023010858333111",required = true)
    private String muId;

    @ApiModelProperty(value = "菜单名称",example = "我的小区",required = true)
    private String name;

    @ApiModelProperty(value = "图标id",example = "fa fa-female",required = true)
    private String icon;

    @ApiModelProperty(value = "url地址",example = "/#/pages/common/enterCommunity",required = true)
    private String url;

    @ApiModelProperty(value = "列顺序",example = "1",required = true)
    private String seq;
}
