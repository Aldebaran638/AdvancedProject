package com.zeroone.star.project.dto.j3.merchantmanage.admin;

import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;

import javax.validation.constraints.NotNull;
import javax.validation.constraints.Pattern;

/**
 * 状态信息传输模型
 *
 * @author wyr on 2025/5/19
 */
@Data
@ApiModel("状态信息传输模型")
public class UpdateStatusDTO {
    @NotNull(message = "管理员ID不能为空")
    @Pattern(regexp = "^\\d+$", message = "管理员ID必须为纯数字")
    @ApiModelProperty(value = "管理员ID", example = "302024021945972511")
    private String userId;
    /**
     * 状态
     * 48001 商户正常状态
     * 48002 +限制商户登录
     */
    @ApiModelProperty(value = "状态", example = "48001", notes = "48001 商户正常状态 48002 限制商户登录")
    private String status;
}
