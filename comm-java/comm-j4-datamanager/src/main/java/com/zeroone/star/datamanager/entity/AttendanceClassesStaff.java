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
@TableName("attendance_classes_staff")
public class AttendanceClassesStaff implements Serializable {

    private static final long serialVersionUID = 1L;

    /**
     * 班次员工ID
     */
    private String csId;

    /**
     * 班次ID
     */
    private String classesId;

    /**
     * 员工ID
     */
    private String staffId;

    /**
     * 员工名称
     */
    private String staffName;

    /**
     * 商户ID
     */
    private String storeId;

    /**
     * 创建时间
     */
    @TableField(fill = FieldFill.INSERT)
    private LocalDateTime createTime;

    /**
     * 数据状态，详细参考c_status表，S 保存，0, 在用 1失效
     */
    private String statusCd;


}
