package com.zeroone.star.project.query.j1.dashboard.console;

import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.AllArgsConstructor;
import lombok.Data;
import lombok.NoArgsConstructor;


@Data
@ApiModel(value = "投诉统计查询对象" , description = "投诉统计查询数据")
@NoArgsConstructor
@AllArgsConstructor
public class ComplaintStatisticsQuery {

    @ApiModelProperty(value = "全部投诉数量", example = "0")
    private Integer totalComplaints;

    @ApiModelProperty(value = "处理中投诉数量", example = "0")
    private Integer processingComplaints;

    @ApiModelProperty(value = "已处理投诉数量", example = "0")
    private Integer processedComplaints;
}