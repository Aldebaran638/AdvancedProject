package com.zeroone.star.project.vo.j1.menumana.menugroup;

import com.fasterxml.jackson.annotation.JsonProperty;
import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;

import java.time.LocalDateTime;

@Data
@ApiModel("菜单组")
public class MenuGroupVO {
    @ApiModelProperty(value = "组ID", example = "800201904004")
    private String gid;
    @ApiModelProperty(value = "名称", example = "小区")
    private String name;
    @ApiModelProperty(value = "图标", example = "fa fa-th-large")
    private String icon;
    @ApiModelProperty(value = "标签", example = "HOT")
    private String label;
    @ApiModelProperty(value = "列序", example = "1")
    private String seq;
    @ApiModelProperty(value = "类型", example = "WEB菜单")
    private String groupType;
    @ApiModelProperty(value = "归属商户", example = "800900000003")
    private String storeType;
}
