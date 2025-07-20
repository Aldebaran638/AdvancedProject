package com.zeroone.star.oauth2.entity;

import com.baomidou.mybatisplus.annotation.*;
import lombok.Getter;
import lombok.Setter;

import java.io.Serializable;
import java.time.LocalDateTime;

/**
 * <p>
 * store_type店铺类型表实体类
 * </p>
 */
@Getter
@Setter
@TableName("store_type")
public class Store implements Serializable {

    private static final long serialVersionUID = 1L;

    /**
     * id
     */
    @TableId(value = "id", type = IdType.AUTO)
    private Integer id;

    /**
     * 店铺编码
     */
    @TableField("store_type_cd")
    private String storeTypeCd;

    /**
     * 店铺种类编码
     */
    @TableField("name")
    private String name;

    /**
     * 描述
     */
    @TableField("description")
    private String description;

    /**
     * 创建时间
     */
    @TableField(value = "create_time", fill = FieldFill.INSERT)
    private LocalDateTime createTime;

    /**
     * 是否显示
     */
    @TableField("is_show")
    private String isShow;

}

