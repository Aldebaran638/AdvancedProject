package com.zeroone.star.project.vo.j1.dashboard.data;

import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;
import lombok.Value;

/**
 * 小区缴费统计数据VO
 */
@Data
@ApiModel(value = "小区缴费统计VO", description = "小区缴费统计数据")
public class CommunityPaymentStatisticsVO {

    @ApiModelProperty(value = "小区ID", example = "2023052267100146")
    private String communityId;

    @ApiModelProperty(value = "小区名称", example = "星湖花园")
    private String communityName;

    @ApiModelProperty(value = "缴费次数", example = "120")
    private Integer paymentCount;

    @ApiModelProperty(value = "缴费金额", example = "10000.00")
    private Double paymentAmount;
}