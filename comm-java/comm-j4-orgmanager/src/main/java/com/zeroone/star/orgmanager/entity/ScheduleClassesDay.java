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
@TableName("schedule_classes_day")
public class ScheduleClassesDay implements Serializable {

    private static final long serialVersionUID = 1L;

    /**
     * 主键ID
     */
    private String dayId;

    /**
     * 排班ID
     */
    private String scheduleId;

    /**
     * 星期
     */
    private Integer weekFlag;

    /**
     * 天
     */
    private Integer day;

    /**
     *  2002 休息日 其他为工作日
     */
    private String workday;

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
