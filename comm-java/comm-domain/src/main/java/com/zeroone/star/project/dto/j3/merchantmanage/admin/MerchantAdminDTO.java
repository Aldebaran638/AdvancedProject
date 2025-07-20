package com.zeroone.star.project.dto.j3.merchantmanage.admin;

import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;

import java.time.LocalDateTime;

/**
 * 商户管理员信息传输模型
 * @author wyr on 2025/5/19
 */
@Data
@ApiModel("商户管理员信息传输模型")
public class MerchantAdminDTO {
    @ApiModelProperty(value = "物业名称", example = "万科物业")
    private String name;
    @ApiModelProperty(value = "管理员姓名", example = "万科物业")
    private String userName;
    @ApiModelProperty(value = "管理员电话", example = "15956590988")
    private String tel;
    @ApiModelProperty(value = "管理员ID", example = "302024021945972511")
    private String userId;
    @ApiModelProperty(value = "状态", example = "48001", notes = "48001 商户正常状态 48002 限制商户登录")
    private String status;
    @ApiModelProperty(value = "状态文本", example = "商户正常状态", notes = "48001 商户正常状态 48002 限制商户登录")
    private String statusText;
    @ApiModelProperty(value = "创建时间", example = "2023-07-06 23:04:49")
    private LocalDateTime createTime;

}
