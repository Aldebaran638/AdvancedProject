package com.zeroone.star.project.dto.j1.menumana.commonmenu;

import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.AllArgsConstructor;
import lombok.Data;
import lombok.NoArgsConstructor;

@Data
@AllArgsConstructor
@NoArgsConstructor
@ApiModel("删除常用菜单")
public class DeleteCommonMenuDTO {
    @ApiModelProperty(value = "菜单编号",example = "102022030737501028",required = true)
    private String muId;
}
