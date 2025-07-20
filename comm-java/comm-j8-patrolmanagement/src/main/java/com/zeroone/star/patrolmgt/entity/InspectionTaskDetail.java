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
@TableName("inspection_task_detail")
public class InspectionTaskDetail implements Serializable {

    private static final long serialVersionUID = 1L;

    /**
     * 任务明细编码
     */
    @TableId("task_detail_id")
    @TableField("task_detail_id")
    private String taskDetailId;

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
     * 任务ID
     */
    @TableField("task_id")
    private String taskId;

    /**
     * 巡检点ID
     */
    @TableField("inspection_id")
    private String inspectionId;

    /**
     * 巡检点名称
     */
    @TableField("inspection_name")
    private String inspectionName;

    /**
     * 巡检点状态
     */
    @TableField("state")
    private String state;

    /**
     * 数据状态
     */
    @TableField("status_cd")
    private String statusCd;

    @TableField(value = "create_time",fill = FieldFill.INSERT)
    private LocalDateTime createTime;

    /**
     * 巡检情况
     */
    @TableField("patrol_type")
    private String patrolType;

    /**
     * 巡检说明
     */
    @TableField("description")
    private String description;

    /**
     * 经度
     */
    @TableField("longitude")
    private String longitude;

    /**
     * 纬度
     */
    @TableField("latitude")
    private String latitude;

    /**
     * 签到状态
     */
    @TableField("inspection_state")
    private String inspectionState;

    /**
     * 巡检点打卡时间
     */
    @TableField("inspection_time")
    private LocalDateTime inspectionTime;

    /**
     * 巡检点开始时间
     */
    @TableField("point_start_time")
    private String pointStartTime;

    /**
     * 巡检点结束时间
     */
    @TableField("point_end_time")
    private String pointEndTime;

    /**
     * 排序
     */
    @TableField("sort_number")
    private Integer sortNumber;

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
     * 巡检提醒标记
     */
    @TableField("send_flag")
    private String sendFlag;


}
