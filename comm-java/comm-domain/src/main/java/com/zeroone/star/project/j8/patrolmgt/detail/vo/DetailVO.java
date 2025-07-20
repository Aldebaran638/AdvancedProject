package com.zeroone.star.project.j8.patrolmgt.detail.vo;

import com.fasterxml.jackson.annotation.JsonFormat;
import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;
import org.springframework.format.annotation.DateTimeFormat;

import java.util.Date;

@Data
@ApiModel("巡检明细显示模型")
public class DetailVO {

    @ApiModelProperty(value = "任务明细ID",example = "5320250519249329192")
    private String task_detail_id;

    @ApiModelProperty(value = "巡检点名称",example = "巡检点1")
    private String inspection_name;

    //通过巡检任务task_id查询巡检任务，巡检任务里面有巡检计划id，查询计划id，查询计划名称
    @ApiModelProperty(value = "巡检计划名称",example = "巡检计划1")
    private String inspection_plan_name;

    //跟上面一样，巡检计划里有巡检路线id，查询路线id，查询路线名称
    @ApiModelProperty(value = "巡检路线名称",example = "巡检路线1")
    private String inspection_route_name;

    @ApiModelProperty(value = "巡检人开始时间", example = "2024-01-11 11:11:11")
    @JsonFormat(pattern = "yyyy-MM-dd HH:mm:ss")
    @DateTimeFormat(pattern = "yyyy-MM-dd HH:mm:ss")
    private Date inspection_person_start_time;

    @ApiModelProperty(value = "巡检人结束时间", example = "2024-01-11 11:11:11")
    @JsonFormat(pattern = "yyyy-MM-dd HH:mm:ss")
    @DateTimeFormat(pattern = "yyyy-MM-dd HH:mm:ss")
    private Date inspection_person_end_time;

    @ApiModelProperty(value = "巡检点开始时间", example = "2024-01-11 11:11:11")
    @JsonFormat(pattern = "yyyy-MM-dd HH:mm:ss")
    @DateTimeFormat(pattern = "yyyy-MM-dd HH:mm:ss")
    private Date point_start_time;

    @ApiModelProperty(value = "巡检点结束时间", example = "2024-01-11 11:11:11")
    @JsonFormat(pattern = "yyyy-MM-dd HH:mm:ss")
    @DateTimeFormat(pattern = "yyyy-MM-dd HH:mm:ss")
    private Date point_end_time;

    @ApiModelProperty(value = "实际巡检时间", example = "2024-01-11 11:11:11")
    @JsonFormat(pattern = "yyyy-MM-dd HH:mm:ss")
    @DateTimeFormat(pattern = "yyyy-MM-dd HH:mm:ss")
    private Date inspection_actual_patrol_time;

    @ApiModelProperty(value = "实际巡检签到状态",example = "1")
    private String inspection_actual_sign_status;

    @ApiModelProperty(value = "计划巡检人名称",example = "张三")
    private String inspection_plan_person_name;

    @ApiModelProperty(value = "实际巡检人名称",example = "李四")
    private String inspection_actual_person_name;

    @ApiModelProperty(value = "巡检方式",example = "现场拍照(默认定位)")
    private String inspection_method;

    @ApiModelProperty(value = "巡检任务状态",example = "未开始")
    private String inspection_task_status;

    @ApiModelProperty(value = "巡检点状态",example = "未开始")
    private String inspection_point_status;

    @ApiModelProperty(value = "巡检情况",example = "未开始")
    private String inspection_patrol_status;

    @ApiModelProperty(value = "巡检照片",example = "http://www.baidu.com")
    private String inspection_photo;

    @ApiModelProperty(value = "创建时间", example = "2024-01-11 11:11:11")
    @JsonFormat(pattern = "yyyy-MM-dd HH:mm:ss")
    @DateTimeFormat(pattern = "yyyy-MM-dd HH:mm:ss")
    private Date create_time;

    @ApiModelProperty(value = "位置信息",example = "北京")
    private String locationInformation;
}
