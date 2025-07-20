package com.zeroone.star.project.dto.j1.menumana.menudir;

import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.AllArgsConstructor;
import lombok.Data;
import lombok.NoArgsConstructor;

import java.io.Serializable;

@Data
@AllArgsConstructor
@NoArgsConstructor
@ApiModel("菜单目录数据对象")
public class MenuCatalogDTO extends AddMenuCatalogDTO implements Serializable {

    private static final long serialVersionUID = 1L;

    /**
     * 菜单目录编号
     */
    @ApiModelProperty(value = "菜单目录编号", example = "102022022645630009", required = true)
    private String caId;

}