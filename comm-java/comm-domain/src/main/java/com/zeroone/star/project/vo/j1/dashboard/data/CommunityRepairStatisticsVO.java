package com.zeroone.star.project.vo.j1.dashboard.data;

import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;

/**
 * 小区报修统计数据VO
 */
@Data
@ApiModel(value = "小区报修统计VO", description = "小区报修统计数据")
public class CommunityRepairStatisticsVO {
    @ApiModelProperty(value = "小区ID", example = "2023052267100146")
    private String communityId;

    @ApiModelProperty(value = "小区名称", example = "星湖花园")
    private String communityName;

    @ApiModelProperty(value = "报修次数", example = "5")
    private Integer repairCount;
}