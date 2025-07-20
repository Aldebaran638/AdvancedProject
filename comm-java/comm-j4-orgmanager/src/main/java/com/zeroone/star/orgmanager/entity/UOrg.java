package com.zeroone.star.orgmanager.entity;

import com.baomidou.mybatisplus.annotation.*;

import java.io.Serializable;
import java.time.LocalDateTime;

import com.baomidou.mybatisplus.extension.plugins.pagination.PageDTO;
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
@Data
@TableName("u_org")
public class UOrg implements Serializable {

    private static final long serialVersionUID = 1L;

    /**
     * 组织id
     */
    @TableId(value = "id", type = IdType.ASSIGN_ID)
    private String orgId;

    /**
     * 业务ID
     */
    @TableField(fill = FieldFill.UPDATE)
    private String bId;

    /**
     * 商户ID
     */
    @TableField(fill = FieldFill.UPDATE)
    private String storeId;

    /**
     * 组织名称
     */
    @TableField(fill = FieldFill.UPDATE)
    private String orgName;

    /**
     * 组织级别1 公司级 2 分公司级，3 部门级 查看t_dict表
     */
     @TableField(fill = FieldFill.INSERT)
    private String orgLevel;

    /**
     * 上级组织ID，一级时填写org_id
     */
    @TableField(fill = FieldFill.UPDATE)
    private String parentOrgId;

    /**
     * 组织描述
     */
    @TableField(fill = FieldFill.UPDATE)
    private String description;

    /**
     * 创建时间
     */
    @TableField(fill = FieldFill.INSERT)
    private LocalDateTime createTime;

    /**
     * 数据状态，详细参考c_status表，0在用，1失效
     */
    @TableField(fill = FieldFill.UPDATE)
    private String statusCd;

    /**
     * 归属小区，9999 归属于入驻的所有小区，否则是为小区ID
     */
    @TableField(fill = FieldFill.UPDATE)
    private String belongCommunityId;

    /**
     * 允许前台操作数据，T可以，F不可以
     */
    @TableField(fill = FieldFill.UPDATE)
    private String allowOperation;


}
