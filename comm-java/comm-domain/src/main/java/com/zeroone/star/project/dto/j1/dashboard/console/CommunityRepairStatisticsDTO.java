package com.zeroone.star.project.dto.j1.dashboard.console;

import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;

/**
 * 小区报修统计数据DTO
 */
@Data
@ApiModel(value = "小区报修统计", description = "小区报修统计数据")
public class CommunityRepairStatisticsDTO {
    @ApiModelProperty(value = "小区名称", example = "星湖花园")
    private String communityName;

    @ApiModelProperty(value = "报修次数", example = "5")
    private Integer repairCount;
}