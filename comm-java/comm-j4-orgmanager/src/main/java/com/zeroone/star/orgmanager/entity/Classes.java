package com.zeroone.star.orgmanager.entity;

import com.baomidou.mybatisplus.annotation.FieldFill;
import com.baomidou.mybatisplus.annotation.TableField;
import java.io.Serializable;
import java.time.LocalDateTime;

import lombok.*;

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
@Builder
@AllArgsConstructor
@NoArgsConstructor
public class Classes implements Serializable {

    private static final long serialVersionUID = 1L;

    /**
     * 班次ID
     */
    private String classesId;

    /**
     * 业务ID
     */
    private String bId;

    /**
     * 班次名称
     */
    private String name;

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
     * 创建时间
     */
    @TableField(fill = FieldFill.INSERT)
    private LocalDateTime createTime;

    /**
     * 数据状态
     */
    private String statusCd;


}
