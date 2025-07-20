package com.zeroone.star.menumana.entity;

import com.baomidou.mybatisplus.annotation.*;
import lombok.Data;

import java.io.Serializable;
import java.time.LocalDateTime;

/**
 * \* @author cv
 * \* Time: 2025/5/20 + 16:46
 * \* Description:
 * \
 */
@Data
@TableName("p_privilege")
public class Privilege implements Serializable {
    private static final long serialVersionUID = 1L;

    /**
     * 权限ID
     */
    @TableId(value="p_id",type = IdType.ASSIGN_ID)
    private String pId;

    /**
     * 权限名称
     */
    private String name;

    /**
     * 权限描述
     */
    private String description;

    /**
     * 创建时间
     */
    @TableField(fill = FieldFill.INSERT)
    private LocalDateTime createTime;

    /**
     * 数据状态，详细参考c_status表，0在用，1失效
     */
    private String statusCd;

    /**
     * 权限域 商户详见store_type store_type_cd
     */
    private String domain;

    /**
     * 资源路径
     */
    private String resource;

    /**
     * 菜单ID
     */
    private String mId;

    public Privilege() {
    }
}
