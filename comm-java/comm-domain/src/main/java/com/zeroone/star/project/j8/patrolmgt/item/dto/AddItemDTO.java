package com.zeroone.star.project.j8.patrolmgt.item.dto;

import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;

/**
 * 添加巡检项目模型类
 */
@ApiModel("添加巡检项目模型类")
@Data
public class AddItemDTO {
    @ApiModelProperty(value="巡检项目",example="电梯巡检",required = true)
    private String itemName;
    @ApiModelProperty(value="备注",example="电梯日巡",required = true)
    private String remark;
    @ApiModelProperty(value="小区ID(隐藏条件)",example="2024012252790005",required = true,notes = "该字段前端无需展示输入框,但是需要传递给后端")
    private String communityId;
}
