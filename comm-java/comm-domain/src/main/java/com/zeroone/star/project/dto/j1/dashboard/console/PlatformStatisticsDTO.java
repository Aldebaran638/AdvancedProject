package com.zeroone.star.project.dto.j1.dashboard.console;

import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;

/**
 * 平台统计数据DTO
 */
@Data
@ApiModel(value = "平台统计数据", description = "平台整体统计数据")
public class PlatformStatisticsDTO {
    @ApiModelProperty(value = "小区数", example = "30")
    private Integer communityCount;

    @ApiModelProperty(value = "物业数", example = "20")
    private Integer propertyCount;

    @ApiModelProperty(value = "商家数", example = "0")
    private Integer businessCount;

    @ApiModelProperty(value = "店铺数", example = "0")
    private Integer shopCount;

    @ApiModelProperty(value = "房屋数", example = "284")
    private Integer houseCount;

    @ApiModelProperty(value = "商铺数", example = "47")
    private Integer commercialHouseCount;

    @ApiModelProperty(value = "业主数", example = "222")
    private Integer ownerCount;

    @ApiModelProperty(value = "车辆数", example = "69")
    private Integer carCount;

    @ApiModelProperty(value = "今日缴费数", example = "9")
    private Integer todayPaymentCount;

    @ApiModelProperty(value = "今日报修数", example = "2")
    private Integer todayRepairCount;

    @ApiModelProperty(value = "今日巡检数", example = "0")
    private Integer todayInspectionCount;

    @ApiModelProperty(value = "今日投诉数", example = "0")
    private Integer todayComplaintCount;
}