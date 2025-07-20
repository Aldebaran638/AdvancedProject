package com.zeroone.star.patrolmgt.entity;

import com.baomidou.mybatisplus.annotation.FieldFill;
import com.baomidou.mybatisplus.annotation.TableField;
import com.baomidou.mybatisplus.annotation.TableId;
import com.baomidou.mybatisplus.annotation.TableName;
import java.io.Serializable;
import java.time.LocalDateTime;
import lombok.Getter;
import lombok.Setter;

/**
 * <p>
 *
 * </p>
 *
 * @author yuanzijie
 * @since 2025-05-24
 */
@Getter
@Setter
@TableName("inspection_task")
public class detail_InspectionTask implements Serializable {

    private static final long serialVersionUID = 1L;

    /**
     * 任务编码
     */
    @TableId("task_id")
    @TableField("task_id")
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

    /**
     * 创建时间（自动填充）
     */
    @TableField(fill = FieldFill.INSERT, value = "create_time")
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
    @TableField("plan_end_time")
    private LocalDateTime planEndTime;

}
