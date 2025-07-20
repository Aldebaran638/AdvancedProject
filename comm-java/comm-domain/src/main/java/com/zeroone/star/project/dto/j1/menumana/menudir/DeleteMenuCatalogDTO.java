package com.zeroone.star.project.dto.j1.menumana.menudir;

import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.AllArgsConstructor;
import lombok.Data;
import lombok.NoArgsConstructor;

@Data
@AllArgsConstructor
@NoArgsConstructor
@ApiModel("删除菜单目录")
public class DeleteMenuCatalogDTO {
    @ApiModelProperty(value = "菜单目录编号",example = "102022022737620040",required = true)
    private String caId;
}
