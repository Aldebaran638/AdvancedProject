package com.zeroone.star.project.vo.j1.dashboard.console;

import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.AllArgsConstructor;
import lombok.Builder;
import lombok.Data;
import lombok.NoArgsConstructor;

import java.io.Serializable;



@Data
@Builder
@ApiModel(value = "投诉统计视图对象" , description = "投诉统计数据")
@NoArgsConstructor
@AllArgsConstructor
public class ComplaintStatisticsVO {

    @ApiModelProperty(value = "全部投诉数量", example = "0")
    private Integer totalComplaints;

    @ApiModelProperty(value = "处理中投诉数量", example = "0")
    private Integer processingComplaints;

    @ApiModelProperty(value = "已处理投诉数量", example = "0")
    private Integer processedComplaints;
}
