package com.zeroone.star.project.query.j1.dashboard.console;

import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.AllArgsConstructor;
import lombok.Builder;
import lombok.Data;
import lombok.NoArgsConstructor;

import java.io.Serializable;


@Data
@Builder
@NoArgsConstructor
@AllArgsConstructor
@ApiModel(value = "报修统计查询对象" , description = "报修统计查询数据")
public class RepairStatisticsQuery{

    @ApiModelProperty(value = "全部报修数量", example = "0")
    private int allRepairs;       // 全部报修

    @ApiModelProperty(value = "待派单数量", example = "0")
    private int pendingRepairs;   // 待派单

    @ApiModelProperty(value = "处理中数量", example = "0")
    private int processingRepairs;// 处理中

    @ApiModelProperty(value = "已处理数量", example = "0")
    private int processedRepairs; // 已处理
}