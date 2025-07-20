package com.zeroone.star.project.j8.patrolmgt.task.dto;

import com.fasterxml.jackson.annotation.JsonFormat;
import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;

import java.time.LocalDateTime;

/**
 * 巡检任务传输对象
 * @author JIAN
 */
@Data
@ApiModel("巡检任务传输对象")
public class TaskDTO {
    @ApiModelProperty(value = "巡检任务id", example = "5220250519674431499")
    private String taskId;
    @ApiModelProperty(value = "巡检计划id", example = "142025050108841149")
    private String planId;
    @ApiModelProperty(value = "巡检计划名称", example = "测试巡检计划01")
    private String planName;
    @JsonFormat(pattern = "yyyy-MM-dd HH:mm")
    @ApiModelProperty(value = "计划开始时间", example = "2025-05-18 08:05")
    private LocalDateTime planInsTime;
    @JsonFormat(pattern = "yyyy-MM-dd HH:mm")
    @ApiModelProperty(value = "计划结束时间", example = "2025-05-18 21:15")
    private LocalDateTime planEndTime;
    @JsonFormat(pattern = "yyyy-MM-dd HH:mm")
    @ApiModelProperty(value = "实际巡检时间", example = "2025-05-18 21:15")
    private LocalDateTime actInsTime;
    @ApiModelProperty(value = "计划巡检人姓名", example = "小王")
    private String planUserName;
    @ApiModelProperty(value = "实际巡检人姓名", example = "小王")
    private String actUserName;
    @ApiModelProperty(value = "转移描述", example = "原负责人请假")
    private String transferDesc;
    @ApiModelProperty(value = "巡检方式", example = "现场拍照（默认定位）")
    private String signType;
    @ApiModelProperty(value = "巡检状态", example = "未开始")
    private String state;
}