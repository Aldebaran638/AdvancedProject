package com.zeroone.star.dashboard.entity;

import com.baomidou.mybatisplus.annotation.*;

import java.io.Serializable;
import java.time.LocalDateTime;
import lombok.Getter;
import lombok.Setter;

/**
 * <p>
 * 
 * </p>
 *
 * @author fayff
 * @since 2025-05-21
 */
@Getter
@Setter
@TableName("inspection_task")
public class InspectionTask implements Serializable {

    private static final long serialVersionUID = 1L;

    /**
     * 任务编码
     */
    @TableId(value = "task_id", type = IdType.ASSIGN_ID)
    private String taskId;

    /**
     * 业务ID
     */
    @TableField("b_id")
    private String bId;

    /**
     * 小区ID
     */
    @TableField("community_id")
    private String communityId;

    /**
     * 计划ID
     */
    @TableField("inspection_plan_id")
    private String inspectionPlanId;

    /**
     * 计划巡检时间
     */
    @TableField("plan_ins_time")
    private LocalDateTime planInsTime;

    /**
     * 实际巡检时间
     */
    @TableField("act_ins_time")
    private LocalDateTime actInsTime;

    /**
     * 计划巡检人员id
     */
    @TableField("plan_user_id")
    private String planUserId;

    /**
     * 计划巡检人员姓名
     */
    @TableField("plan_user_name")
    private String planUserName;

    /**
     * 实际巡检人员id
     */
    @TableField("act_user_id")
    private String actUserId;

    /**
     * 实际巡检人员姓名
     */
    @TableField("act_user_name")
    private String actUserName;

    /**
     * 实际巡检方式
     */
    @TableField("sign_type")
    private String signType;

    /**
     * 数据状态
     */
    @TableField("status_cd")
    private String statusCd;

    @TableField(value = "create_time", fill = FieldFill.INSERT)
    private LocalDateTime createTime;

    /**
     * 巡检状态
     */
    @TableField("state")
    private String state;

    /**
     * 巡检人ID
     */
    @TableField("ip_staff_id")
    private String ipStaffId;

    /**
     * 原计划巡检人userId
     */
    @TableField("original_plan_user_id")
    private String originalPlanUserId;

    /**
     * 原计划巡检人名称
     */
    @TableField("original_plan_user_name")
    private String originalPlanUserName;

    /**
     * 转移说明
     */
    @TableField("transfer_desc")
    private String transferDesc;

    /**
     * 任务类型 1000日常巡检任务 2000流转巡检任务
     */
    @TableField("task_type")
    private String taskType;

    /**
     * 计划巡检结束时间
     */
    @TableField(value = "plan_end_time", fill = FieldFill.UPDATE)
    private LocalDateTime planEndTime;


}
