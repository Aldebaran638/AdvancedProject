package com.zeroone.star.orgmanager.entity;

import com.baomidou.mybatisplus.annotation.FieldFill;
import com.baomidou.mybatisplus.annotation.TableField;
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
 * @author zhangdashuai
 * @since 2025-05-21
 */
@Getter
@Setter
@TableName("schedule_classes")
public class ScheduleClasses implements Serializable {

    private static final long serialVersionUID = 1L;

    /**
     * 排班ID
     */
    private String scheduleId;

    /**
     * 业务ID
     */
    private String bId;

    /**
     * 班次名称
     */
    private String name;

    /**
     * 排班类型 1001 按日排班 2002 按周排班 3003 按月排班
     */
    private String scheduleType;

    /**
     * 排班周期
     */
    private String scheduleCycle;

    /**
     * 商户ID
     */
    private String storeId;

    /**
     * 状态 1001 启用 2002 停用
     */
    private String state;

    /**
     * 备注说明
     */
    private String remark;

    /**
     * 计算时间
     */
    private LocalDateTime computeTime;

    /**
     * 创建时间
     */
    @TableField(fill = FieldFill.INSERT)
    private LocalDateTime createTime;

    /**
     * 数据状态
     */
    private String statusCd;


}
