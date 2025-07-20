package com.zeroone.star.project.dto.j1.menumana.commonmenu;

import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.AllArgsConstructor;
import lombok.Data;
import lombok.NoArgsConstructor;

@Data
@AllArgsConstructor
@NoArgsConstructor
@ApiModel("添加常用菜单")
public class AddCommonMenuDTO {

    @ApiModelProperty(value = "菜单id",example = "700201904008",required = true)
    private String mid;

    @ApiModelProperty(value = "图标id",example = "fa fa-female",required = true)
    private String icon;

    @ApiModelProperty(value = "列顺序",example = "1",required = true)
    private String seq;
}
