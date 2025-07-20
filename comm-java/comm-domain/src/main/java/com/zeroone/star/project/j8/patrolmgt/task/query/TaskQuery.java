package com.zeroone.star.project.j8.patrolmgt.task.query;

import com.zeroone.star.project.query.PageQuery;
import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;
import org.springframework.format.annotation.DateTimeFormat;

import javax.validation.constraints.NotNull;
import java.time.LocalDateTime;

/**
 * 巡检任务分页查询对象
 * @author JIAN
 */
@Data
@ApiModel("巡检任务分页查询对象")
public class TaskQuery extends PageQuery {
    @NotNull
    @ApiModelProperty(value = "小区id", required = true, example = "2024022643710121")
    private String communityId;
    @ApiModelProperty(value = "巡检计划id", example = "142024021699470706")
    private String planId;
    @ApiModelProperty(value = "计划巡检人姓名", example = "小王")
    private String planUserName;
    @ApiModelProperty(value = "实际巡检人姓名", example = "小王")
    private String actUserName;
    @DateTimeFormat(pattern = "yyyy-MM-dd HH:mm")
    @ApiModelProperty(value = "开始时间", example = "2025-05-18 08:05")
    private LocalDateTime planInsTime;
    @DateTimeFormat(pattern = "yyyy-MM-dd HH:mm")
    @ApiModelProperty(value = "结束时间", example = "2025-05-18 21:15")
    private LocalDateTime planEndTime;
    @ApiModelProperty(value = "巡检状态", example = "未开始")
    private String state;
}