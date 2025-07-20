package com.zeroone.star.project.dto.j1.menumana.menugroup;

import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;

@ApiModel("菜单组")
@Data
public class MenuGroupDTO {
    @ApiModelProperty(value="组名称", example = "小区",required = true)
    private String name;
    @ApiModelProperty(value="图标", example = "fa fa-th-large",required = true)
    private String icon;
    @ApiModelProperty(value="标签", example = "TOP")
    private String label;
    @ApiModelProperty(value="序列", example = "1",  required = true)
    private Integer seq;
    @ApiModelProperty(value="组类型", example = "P_WEB")
    private String groupType;
    @ApiModelProperty(value="归属商户", example = "800900000003")
    private String storeType;
    @ApiModelProperty(value="描述", example = "小区管理")
    private String description;
}
