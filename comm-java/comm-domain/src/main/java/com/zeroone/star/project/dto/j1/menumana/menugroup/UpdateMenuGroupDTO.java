package com.zeroone.star.project.dto.j1.menumana.menugroup;

import com.fasterxml.jackson.annotation.JsonProperty;
import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;

@Data
@ApiModel("修改菜单组参数")
public class UpdateMenuGroupDTO {
    @ApiModelProperty(value="菜单组ID", example = "800201904004",required = true)
    private String gid;
    @ApiModelProperty(value="组名称", example = "小区")
    private String name;
    @ApiModelProperty(value="图标", example = "fa fa-th-large")
    private String icon;
    @ApiModelProperty(value="标签", example = "TOP")
    private String label;
    @ApiModelProperty(value="列序", example = "1")
    private Integer seq;
    @ApiModelProperty(value="组类型", example = "P_WEB")
    private String groupType;
    @ApiModelProperty(value="归属商户", example = "800900000003")
    private String storeType;
    @ApiModelProperty(value="描述", example = "小区管理")
    private String description;
}
