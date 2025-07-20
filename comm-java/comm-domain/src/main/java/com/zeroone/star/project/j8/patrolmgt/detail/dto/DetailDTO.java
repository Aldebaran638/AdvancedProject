package com.zeroone.star.project.j8.patrolmgt.detail.dto;


import com.fasterxml.jackson.annotation.JsonFormat;
import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;
import org.springframework.format.annotation.DateTimeFormat;

import java.util.Date;

//改为和实体类相同的驼峰命名法
@Data
@ApiModel("巡检明细数据模型")
public class DetailDTO {

    @ApiModelProperty(value = "任务明细ID",example = "5320250519249329192")
    private String taskDetailId;

    @ApiModelProperty(value = "巡检点名称",example = "巡检点1")
    private String inspectionName;

    //通过巡检任务task_id查询巡检任务，巡检任务里面有巡检计划id，查询计划id，查询计划名称
    @ApiModelProperty(value = "巡检计划名称",example = "巡检计划1")
    private String inspectionPlanName;

    //跟上面一样，巡检计划里有巡检路线id，查询路线id，查询路线名称
    @ApiModelProperty(value = "巡检路线名称",example = "巡检路线1")
    private String inspectionRouteName;

    @ApiModelProperty(value = "巡检人开始时间", example = "2024-01-11 11:11:11")
    @JsonFormat(pattern = "yyyy-MM-dd HH:mm:ss")
    @DateTimeFormat(pattern = "yyyy-MM-dd HH:mm:ss")
    private Date inspectionPersonStartTime;

    @ApiModelProperty(value = "巡检人结束时间", example = "2024-01-11 11:11:11")
    @JsonFormat(pattern = "yyyy-MM-dd HH:mm:ss")
    @DateTimeFormat(pattern = "yyyy-MM-dd HH:mm:ss")
    private Date inspectionPersonEndTime;

    @ApiModelProperty(value = "巡检点开始时间", example = "2024-01-11 11:11:11")
    @JsonFormat(pattern = "yyyy-MM-dd HH:mm:ss")
    @DateTimeFormat(pattern = "yyyy-MM-dd HH:mm:ss")
    private Date pointStartTime;

    @ApiModelProperty(value = "巡检点结束时间", example = "2024-01-11 11:11:11")
    @JsonFormat(pattern = "yyyy-MM-dd HH:mm:ss")
    @DateTimeFormat(pattern = "yyyy-MM-dd HH:mm:ss")
    private Date pointEndTime;

    @ApiModelProperty(value = "实际巡检时间", example = "2024-01-11 11:11:11")
    @JsonFormat(pattern = "yyyy-MM-dd HH:mm:ss")
    @DateTimeFormat(pattern = "yyyy-MM-dd HH:mm:ss")
    private Date actPatrolTime;

    @ApiModelProperty(value = "实际巡检签到状态",example = "1")
    private String inspectionState;

    @ApiModelProperty(value = "计划巡检人名称",example = "张三")
    private String inspectionPlanPersonName;

    @ApiModelProperty(value = "实际巡检人名称",example = "李四")
    private String actUserName;

    @ApiModelProperty(value = "巡检方式",example = "现场拍照(默认定位)")
    private String inspectionMethod;

    @ApiModelProperty(value = "巡检任务状态",example = "未开始")
    private String inspectionTaskStatus;

    @ApiModelProperty(value = "巡检点状态",example = "未开始")
    private String state;

    @ApiModelProperty(value = "巡检情况",example = "未开始")
    private String patrolType;

    @ApiModelProperty(value = "巡检照片",example = "http://www.baidu.com")
    private String inspectionPhoto;

    @ApiModelProperty(value = "创建时间", example = "2024-01-11 11:11:11")
    @JsonFormat(pattern = "yyyy-MM-dd HH:mm:ss")
    @DateTimeFormat(pattern = "yyyy-MM-dd HH:mm:ss")
    private Date createTime;

    @ApiModelProperty(value = "位置信息",example = "北京")
    private String locationInformation;
}