package com.zeroone.star.project.dto.j1.dashboard.data;

import com.fasterxml.jackson.annotation.JsonFormat;
import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.AllArgsConstructor;
import lombok.Data;
import lombok.NoArgsConstructor;

import java.io.Serializable;
import java.util.Date;

@Data
@ApiModel(value = "投诉统计传输对象" , description = "投诉统计数据")
@AllArgsConstructor
@NoArgsConstructor
public class ComplaintStatisticsDTO{

    @ApiModelProperty(value = "全部投诉数量", example = "0")
    private Integer totalComplaints;

    @ApiModelProperty(value = "处理中投诉数量", example = "0")
    private Integer processingComplaints;

    @ApiModelProperty(value = "已处理投诉数量", example = "0")
    private Integer processedComplaints;
}
