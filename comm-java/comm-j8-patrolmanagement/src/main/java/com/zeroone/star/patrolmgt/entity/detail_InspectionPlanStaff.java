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
@TableName("inspection_plan_staff")
public class detail_InspectionPlanStaff implements Serializable {

    private static final long serialVersionUID = 1L;

    /**
     * 主键ID
     */
    @TableId("ip_staff_id")
    @TableField("ip_staff_id")
    private String ipStaffId;

    /**
     * 巡检计划ID
     */
    @TableField("inspection_plan_id")
    private String inspectionPlanId;

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
     * 巡检人
     */
    @TableField("staff_id")
    private String staffId;

    /**
     * 巡检人名称
     */
    @TableField("staff_name")
    private String staffName;

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
     * 创建时间（自动填充）
     */
    @TableField(fill = FieldFill.INSERT, value = "create_time")
    private LocalDateTime createTime;

    /**
     * 数据状态
     */
    @TableField("status_cd")
    private String statusCd;
}
