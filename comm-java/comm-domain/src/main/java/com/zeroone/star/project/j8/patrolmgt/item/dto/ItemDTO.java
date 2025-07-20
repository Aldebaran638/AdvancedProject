package com.zeroone.star.project.j8.patrolmgt.item.dto;

import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;

/**
 * 修改巡检项目模型
 */
@ApiModel("修改巡检项目模型类")
@Data
public class ItemDTO extends AddItemDTO{
    @ApiModelProperty(value="巡检项目的主键id(隐藏条件)",example="102022122193930552",required=true,notes = "该字段前端无需展示输入框,但是需要传递给后端")
    private String itemId;
}
