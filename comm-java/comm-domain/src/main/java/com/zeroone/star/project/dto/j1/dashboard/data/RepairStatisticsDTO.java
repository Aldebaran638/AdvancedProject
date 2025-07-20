package com.zeroone.star.project.dto.j1.dashboard.data;


import com.fasterxml.jackson.annotation.JsonFormat;
import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.AllArgsConstructor;
import lombok.Builder;
import lombok.Data;
import lombok.NoArgsConstructor;

import java.io.Serializable;
import java.util.Date;


@Data
@ApiModel(value = "报修统计传输对象" , description = "报修统计数据")
@Builder
@AllArgsConstructor
@NoArgsConstructor
public class RepairStatisticsDTO{

    @ApiModelProperty(value = "全部报修数量", example = "0")
    private Integer allRepairs;       // 全部报修

    @ApiModelProperty(value = "待派单数量", example = "0")
    private Integer pendingRepairs;   // 待派单

    @ApiModelProperty(value = "处理中数量", example = "0")
    private Integer processingRepairs;// 处理中

    @ApiModelProperty(value = "已处理数量", example = "0")
    private Integer processedRepairs; // 已处理
}
