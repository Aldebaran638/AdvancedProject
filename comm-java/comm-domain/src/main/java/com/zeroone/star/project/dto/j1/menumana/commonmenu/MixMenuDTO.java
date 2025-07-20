package com.zeroone.star.project.dto.j1.menumana.commonmenu;

import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Getter;
import lombok.Setter;

@ApiModel("获取可选菜单下拉列表")
@Setter
@Getter
public class MixMenuDTO {
    @ApiModelProperty(value = "模块-菜单名称",example = "小区-我的小区")
    private String mixName;

    @ApiModelProperty(value = "菜单id",example = "700201904008")
    private String mid;
}
