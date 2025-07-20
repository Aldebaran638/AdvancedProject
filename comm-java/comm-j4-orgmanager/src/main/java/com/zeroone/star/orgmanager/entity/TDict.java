package com.zeroone.star.orgmanager.entity;

import com.baomidou.mybatisplus.annotation.FieldFill;
import com.baomidou.mybatisplus.annotation.IdType;
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
 * @author Alisa
 * @since 2025-05-25
 */
@Getter
@Setter
@TableName("t_dict")
public class TDict implements Serializable {

    private static final long serialVersionUID = 1L;

    /**
     * id
     */
    @TableId(value = "id", type = IdType.ASSIGN_ID)
    private Integer id;

    /**
     * 表字段状态 取值
     */
    @TableField(fill = FieldFill.UPDATE)
    private String statusCd;

    /**
     * 名称
     */
    @TableField(fill = FieldFill.UPDATE)
    private String name;

    /**
     * 描述
     */
    @TableField(fill = FieldFill.UPDATE)
    private String description;

    /**
     * 创建时间
     */
    @TableField(fill = FieldFill.INSERT)
    private LocalDateTime createTime;

    /**
     * 表名
     */
    @TableField(fill = FieldFill.UPDATE)
    private String tableName;

    /**
     * 表字段说明
     */
    @TableField(fill = FieldFill.UPDATE)
    private String tableColumns;

}
