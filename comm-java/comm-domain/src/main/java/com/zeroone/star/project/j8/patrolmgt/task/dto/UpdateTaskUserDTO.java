package com.zeroone.star.project.j8.patrolmgt.task.dto;

import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;

/**
 * 流转巡检任务传输对象
 * @author JIAN
 */
@Data
@ApiModel("流转巡检任务传输对象")
public class UpdateTaskUserDTO {
    @ApiModelProperty(value = "巡检任务id" , required = true, example = "5220250519674431499")
    private String taskId;
    @ApiModelProperty(value = "被转移人id", required = true, example = "302025043082457777")
    private String newUserId;
    @ApiModelProperty(value = "转移描述", required = true ,example = "原负责人请假")
    private String transferDesc;
}