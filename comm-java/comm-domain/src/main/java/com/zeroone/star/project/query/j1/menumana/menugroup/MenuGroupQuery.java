package com.zeroone.star.project.query.j1.menumana.menugroup;

import com.fasterxml.jackson.annotation.JsonProperty;
import com.zeroone.star.project.query.PageQuery;
import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;

@Data
@ApiModel("菜单组查询参数")
public class MenuGroupQuery extends PageQuery {
    @ApiModelProperty(value = "菜单组Id", example = "800201904004")
    private String gid;
    @ApiModelProperty(value = "菜单组名称", example = "小区")
    private String name;
    @ApiModelProperty(value = "商户类型", example = "800900000003")
    private String storeType;
}
