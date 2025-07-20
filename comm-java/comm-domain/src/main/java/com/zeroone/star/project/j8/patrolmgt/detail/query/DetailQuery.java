package com.zeroone.star.project.j8.patrolmgt.detail.query;

import com.fasterxml.jackson.annotation.JsonFormat;
import com.zeroone.star.project.query.PageQuery;
import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;
import org.springframework.format.annotation.DateTimeFormat;

import java.time.LocalTime;
import java.util.Date;

@Data
@ApiModel("巡检明细查询模型")
public class DetailQuery extends PageQuery {

    @ApiModelProperty(value = "计划巡检人名称",example = "张三")
    private String planUserName;

    @ApiModelProperty(value = "巡检点开始时间", example = "2024-01-11 11:11:11")
    @JsonFormat(pattern = "yyyy-MM-dd HH:mm:ss")
    @DateTimeFormat(pattern = "yyyy-MM-dd HH:mm:ss")
    private Date pointStartTime;

    @ApiModelProperty(value = "巡检点结束时间", example = "2024-01-11 11:11:11")
    @JsonFormat(pattern = "yyyy-MM-dd HH:mm:ss")
    @DateTimeFormat(pattern = "yyyy-MM-dd HH:mm:ss")
    private Date pointEndTime;
}
