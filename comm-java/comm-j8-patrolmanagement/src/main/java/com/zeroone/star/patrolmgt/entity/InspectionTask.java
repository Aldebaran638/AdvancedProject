package com.zeroone.star.patrolmgt.entity;

import com.baomidou.mybatisplus.annotation.TableField;
import com.baomidou.mybatisplus.annotation.TableId;
import com.baomidou.mybatisplus.annotation.TableName;
import lombok.Data;

import java.time.LocalDateTime;

/**
 * 巡检任务实体类
 * @author JIAN
 */
@Data
@TableName("inspection_task")
public class InspectionTask {
    /**
     * 任务ID
     */
    @TableId
    private String taskId;

    /**
     * 业务ID(默认值为-1)
     */
    @TableField
    private String bId;

    /**
     * 小区ID
     */
    @TableField
    private String communityId;

    /**
     * 计划ID
     */
    @TableField
    private String inspectionPlanId;

    /**
     * 计划名称(用于联表查询时进行映射)
     */
    @TableField(exist = false)
    private String inspectionPlanName;

    /**
     * 计划巡检开始时间
     */
    @TableField
    private LocalDateTime planInsTime;

    /**
     * 计划巡检结束时间
     */
    @TableField
    private LocalDateTime planEndTime;

    /**
     * 实际巡检开始时间
     */
    @TableField
    private LocalDateTime actInsTime;

    /**
     * 计划巡检人员id
     */
    @TableField
    private String planUserId;

    /**
     * 计划巡检人员姓名
     */
    @TableField
    private String planUserName;

    /**
     * 实际巡检人员id
     */
    @TableField
    private String actUserId;

    /**
     * 实际巡检人员姓名
     */
    @TableField
    private String actUserName;

    /**
     * 巡检人员ID
     */
    @TableField
    private String ipStaffId;

    /**
     * 实际巡检方式
     */
    @TableField
    private String signType;

    /**
     * 原计划巡检人ID
     */
    @TableField
    private String originalPlanUserId;

    /**
     * 原计划巡检人姓名
     */
    @TableField
    private String originalPlanUserName;

    /**
     * 转移说明
     */
    @TableField
    private String transferDesc;

    /**
     * 巡检状态
     */
    private String state;

    /**
     * 任务类型 1000日常巡检任务 2000流转巡检任务
     */
    @TableField
    private String taskType;

    /**
     * 数据状态(默认值为0)
     */
    @TableField
    private String statusCd;

    /**
     * 创建时间
     */
    @TableField
    private LocalDateTime createTime;
}