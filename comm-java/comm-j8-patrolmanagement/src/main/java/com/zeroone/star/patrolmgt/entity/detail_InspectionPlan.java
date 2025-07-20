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
@TableName("inspection_plan")
public class detail_InspectionPlan implements Serializable {

    private static final long serialVersionUID = 1L;

    /**
     * 巡检计划ID
     */
    @TableId("inspection_plan_id")
    @TableField("inspection_plan_id")
    private String inspectionPlanId;

    /**
     * 业务ID
     */
    @TableField("b_id")
    private String bId;

    /**
     * 巡检计划名称
     */
    @TableField("inspection_plan_name")
    private String inspectionPlanName;

    /**
     * 巡检路线ID
     */
    @TableField("inspection_route_id")
    private String inspectionRouteId;

    /**
     * 小区ID
     */
    @TableField("community_id")
    private String communityId;

    /**
     * 开始日期
     */
    @TableField("start_date")
    private LocalDateTime startDate;

    /**
     * 结束日期
     */
    @TableField("end_date")
    private LocalDateTime endDate;

    /**
     * 开始时间
     */
    @TableField("start_time")
    private String startTime;

    /**
     * 结束时间
     */
    @TableField("end_time")
    private String endTime;

    /**
     * 任务提前
     */
    @TableField("before_time")
    private String beforeTime;

    /**
     * 执行周期
     */
    @TableField("inspection_plan_period")
    private String inspectionPlanPeriod;

    /**
     * 月份
     */
    @TableField("inspection_month")
    private String inspectionMonth;

    /**
     * 天
     */
    @TableField("inspection_day")
    private String inspectionDay;

    /**
     * 周
     */
    @TableField("inspection_workday")
    private String inspectionWorkday;

    /**
     * 签到方式
     */
    @TableField("sign_type")
    private String signType;

    /**
     * 允许补检  1000不允许  2000允许
     */
    @TableField("can_reexamine")
    private String canReexamine;

    /**
     * 当前状态
     */
    @TableField("state")
    private String state;

    /**
     * 备注说明
     */
    @TableField("remark")
    private String remark;

    /**
     * 制定人员ID
     */
    @TableField("create_user_id")
    private String createUserId;

    /**
     * 制定人员姓名
     */
    @TableField("create_user_name")
    private String createUserName;

    /**
     * 创建时间（自动填充）
     */
    @TableField(fill = FieldFill.INSERT,  value = "create_time")
    private LocalDateTime createTime;

    /**
     * 数据状态
     */
    @TableField("status_cd")
    private String statusCd;
}
