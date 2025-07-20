package com.zeroone.star.orgmanager.entity;

import com.baomidou.mybatisplus.annotation.*;

import java.io.Serializable;
import java.time.LocalDateTime;
import lombok.Getter;
import lombok.Setter;

/**
 * <p>
 * 
 * </p>
 *
 * @author SETTRA
 * @since 2025-05-30
 */
@Getter
@Setter
@TableName("p_privilege_group")
public class PPrivilegeGroup implements Serializable {

    private static final long serialVersionUID = 1L;

    /**
     * 权限组ID
     */
    @TableId(value="pg_id",type = IdType.ASSIGN_ID)
    private String pgId;

    /**
     * 权限组名称
     */
    private String name;

    /**
     * 权限组描述
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
     * 商户ID
     */
    private String storeId;

    /**
     * 权限组域 商户详见store_type store_type_cd
     */
    private String domain;

    /**
     * SYSTEM 系统角色 USER 用户角色
     */
    private String roleType;

    /**
     * 顺序
     */
    private String seq;


}
