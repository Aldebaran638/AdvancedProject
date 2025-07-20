package com.zeroone.star.contractmanagement.entity;


import com.baomidou.mybatisplus.annotation.*;
import lombok.Getter;
import lombok.Setter;

import java.io.Serializable;
import java.time.LocalDateTime;

/**
 * <p>
 * 合同变更计划表
 * </p>
 *
 * @author RC
 * @since 2025-05-18
 */
@Getter
@Setter
@TableName("contract_change_plan")
public class ContractChangePlan implements Serializable {
    private static final long serialVersionUID = 1L;

    /**
     * 合并变更计划ID
     */
    @TableId(value = "plan_id", type = IdType.ASSIGN_ID)
    private String planId;

    /**
     * 合同ID
     */
    private String contractId;

    /**
     * 变更类型：1001 主体变更, 2002 租期调整, 3003 资产调整,
     *           4004 费用标准调整, 5005 退约管理, 6006 续约管理
     */
    private String planType;

    /**
     * 变更人
     */
    private String changePerson;

    /**
     * 变更理由
     */
    private String remark;

    /**
     * 审核状态：11 待审核, 22 审核通过, 33 审核失败
     */
    private String state = "22";

    /**
     * 创建时间
     */
    @TableField(fill = FieldFill.INSERT)
    private LocalDateTime createTime;

    /**
     * 数据状态：S 保存, 0 在用, 1 失效
     */
    @TableLogic(value = "0",delval = "1")
    private String statusCd;

    /**
     * 商户ID
     */
    private String storeId;
}

