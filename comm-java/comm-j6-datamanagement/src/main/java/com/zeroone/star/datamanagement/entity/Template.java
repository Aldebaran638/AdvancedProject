package com.zeroone.star.datamanagement.entity;

import com.baomidou.mybatisplus.annotation.*;

import java.io.Serializable;
import java.time.LocalDate;
import java.time.LocalDateTime;

import lombok.Getter;
import lombok.Setter;

/**
 * <p>
 * 模板文件表
 * </p>
 *
 * @author 落
 * @since 2025-05-18
 */
@Getter
@Setter
@TableName("template")
public class Template implements Serializable {

    private static final long serialVersionUID = 1L;

    /**
     * 文件md5值
     */
    @TableId(value = "id", type = IdType.ASSIGN_ID)
    private String id;

    /**
     * 文件名
     */
    private String name;

    /**
     * 文件分组
     */
    @TableField(value = "`group`")
    private String group;

    /**
     * 分组路径
     */
    private String storageId;

    /**
     * 文件路径
     */
    private String path;

    /**
     * 创建时间
     */
    @TableField(fill = FieldFill.INSERT)
    private LocalDateTime createTime;

    /**
     * 修改时间
     */
    @TableField(fill=FieldFill.INSERT_UPDATE)
    private LocalDateTime updateTime;


}
