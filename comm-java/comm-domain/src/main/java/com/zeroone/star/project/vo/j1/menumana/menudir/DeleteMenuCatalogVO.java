package com.zeroone.star.project.vo.j1.menumana.menudir;

import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;

@ApiModel("删除菜单目录响应参数")
@Data
public class DeleteMenuCatalogVO {

    @ApiModelProperty(value = "菜单目录编号",example = "102022022737620040",required = true)
    private String caId;
}