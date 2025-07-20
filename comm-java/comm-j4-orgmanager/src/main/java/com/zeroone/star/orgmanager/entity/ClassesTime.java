package com.zeroone.star.orgmanager.entity;

import com.baomidou.mybatisplus.annotation.*;
import java.io.Serializable;
import java.time.LocalDateTime;
import lombok.*;
import lombok.Data;
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
@Data
@TableName("classes_time")
@Builder
@AllArgsConstructor
@NoArgsConstructor
public class ClassesTime implements Serializable {

    private static final long serialVersionUID = 1L;

    /**
     * 主键ID
     */
    private String timeId;

    /**
     * 天ID
     */
    private String classesId;

    /**
     * 开始时间
     */
    private String startTime;

    /**
     * 结束时间
     */
    private String endTime;

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
