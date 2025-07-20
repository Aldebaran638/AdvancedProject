package com.zeroone.star.orgmanager.entity;

import com.baomidou.mybatisplus.annotation.FieldFill;
import com.baomidou.mybatisplus.annotation.TableField;
import com.baomidou.mybatisplus.annotation.TableName;
import java.io.Serializable;
import java.time.LocalDateTime;
import lombok.AllArgsConstructor;
import lombok.Getter;
import lombok.NoArgsConstructor;
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
@TableName("u_org_staff_rel")
@AllArgsConstructor
@NoArgsConstructor
public class UOrgStaffRel implements Serializable {

    private static final long serialVersionUID = 1L;

    /**
     * 组织员工ID
     */
    private String relId;

    /**
     * 业务ID
     */
    private String bId;

    /**
     * 组织ID
     */
    private String orgId;

    /**
     * 员工ID
     */
    private String staffId;

    /**
     * 关系角色，10000 普通员工， 20000部门经理 查看t_dict表
     */
    private String relCd;

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
}
