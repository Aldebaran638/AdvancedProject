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
@TableName("schedule_classes_staff")
public class ScheduleClassesStaff implements Serializable {

    private static final long serialVersionUID = 1L;

    /**
     * 主键
     */
    private String scsId;

    /**
     * 排班ID
     */
    private String scheduleId;

    /**
     * 商户ID
     */
    private String storeId;

    /**
     * 员工ID
     */
    private String staffId;

    /**
     * 员工名称
     */
    private String staffName;

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
