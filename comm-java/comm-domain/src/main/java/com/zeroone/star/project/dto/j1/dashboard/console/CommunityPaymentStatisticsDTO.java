package com.zeroone.star.project.dto.j1.dashboard.console;

import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;

/**
 * 小区缴费统计数据DTO
 */
@Data
@ApiModel(value = "小区缴费统计", description = "小区缴费统计数据")
public class CommunityPaymentStatisticsDTO {
    @ApiModelProperty(value = "小区名称", example = "星湖花园")
    private String communityName;

    @ApiModelProperty(value = "缴费次数", example = "120")
    private Integer paymentCount;

    @ApiModelProperty(value = "缴费金额", example = "10000.00")
    private Double paymentAmount;
}