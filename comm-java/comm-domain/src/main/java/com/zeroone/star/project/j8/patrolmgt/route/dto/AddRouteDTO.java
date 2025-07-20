package com.zeroone.star.project.j8.patrolmgt.route.dto;


import io.swagger.annotations.ApiModel;
        import io.swagger.annotations.ApiModelProperty;
        import lombok.Data;

import javax.validation.constraints.NotBlank;
import javax.validation.constraints.NotNull;

/**
 * <p>
 * 描述：添加巡检路线模型
 * </p>
 * <p>版权：&copy;01星球</p>
 * <p>地址：01星球总部</p>
 * @author Niu
 * @version 1.0.0
 */
@ApiModel("添加巡检路线模型")
@Data
public class AddRouteDTO {
    @NotBlank(message = "路线名称不能为空且长度必须大于0")
    @ApiModelProperty(value = "路线名称", example = "黄利路", required = true)
    private String routeName;

    @NotBlank(message = "检查项数量不能为空且长度必须大于0")
    @ApiModelProperty(value = "顺序", example = "1", required = true)
    private String seq;

    @NotBlank(message = "小区id不能为空且长度必须大于0")
    @ApiModelProperty(value = "小区id", example = "2025041251140067", required = true)
    private String communityId;


    @ApiModelProperty(value = "备注", example = "需要仔细巡检，早晚各一次", required = false)
    private String remark;
}
