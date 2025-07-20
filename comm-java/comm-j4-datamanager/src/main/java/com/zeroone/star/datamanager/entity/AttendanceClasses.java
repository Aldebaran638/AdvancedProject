package com.zeroone.star.datamanager.entity;

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
@TableName("attendance_classes")
public class AttendanceClasses implements Serializable {

    private static final long serialVersionUID = 1L;

    /**
     * 班次ID
     */
    private String classesId;

    /**
     * 商户ID
     */
    private String storeId;

    /**
     * 业务ID
     */
    private String bId;

    /**
     * 班级名称
     */
    private String classesName;

    /**
     * 允许打卡范围，单位为分钟
     */
    private Integer timeOffset;

    /**
     * 打卡次数 默认为 2 次 4 次 6次
     */
    private Integer clockCount;

    /**
     * 打卡类型，1001 每天打卡 1002 隔天打卡 1003 自定义
     */
    private String clockType;

    /**
     * 打卡规则，* 每天打卡 ? 隔天打卡 0-6组成逗号分隔 自定义
     */
    private String clockTypeValue;

    /**
     * 迟到时间范围，超过改时间即为旷工
     */
    private Integer lateOffset;

    /**
     * 早退时间范围，超过改时间即为旷工
     */
    private Integer leaveOffset;

    /**
     * 创建时间
     */
    @TableField(fill = FieldFill.INSERT)
    private LocalDateTime createTime;

    /**
     * 数据状态，详细参考c_status表，S 保存，0, 在用 1失效
     */
    private String statusCd;

    /**
     * 当天下班正常考勤范围，超过改时间即为旷工
     */
    private Integer maxLastOffset;


}
