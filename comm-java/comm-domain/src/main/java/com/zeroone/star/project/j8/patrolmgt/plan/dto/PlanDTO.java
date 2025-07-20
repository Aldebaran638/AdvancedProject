package com.zeroone.star.project.j8.patrolmgt.plan.dto;

import lombok.Data;

import java.util.Date; // 或者使用 java.time.LocalDateTime 等现代日期时间API

/**
 * 巡检计划DTO
 */
@Data
public class PlanDTO{

    /**
     * 巡检计划名称
     */
    private String inspectionPlanName;


    /**
     * 路线名
     */
    private String routeName;

    /**
     * 执行周期 (例如：每天, 每周, 每月等)
     */
    private String inspectionPlanPeriod;

    /**
     * 签到方式
     */
    private String signType;

    /**
     * 开始日期
     */
    private Date startDate; // 或者 LocalDateTime startDate;

    /**
     * 结束日期
     */
    private Date endDate; // 或者 LocalDateTime endDate;

    private String dateRange;
    /**
     * 开始时间 (格式如 HH:mm)
     */
    private String startTime;

    /**
     * 结束时间 (格式如 HH:mm)
     */
    private String endTime;

    private String timeRange;

    /**
     * 任务提前时间（单位可能是分钟），默认为'30'
     */
    private String beforeTime;

    /**
     * 制定人员姓名
     */
    private String createUserName;

    /**
     * 创建时间，默认为当前时间戳
     */
    private Date createTime; // 或者 Timestamp createTime; 或者 LocalDateTime createTime;

    /**
     * 当前状态
     */
    private String state;

}