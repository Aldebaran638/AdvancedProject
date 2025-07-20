package com.zeroone.star.contractmanagement.entity;


import com.baomidou.mybatisplus.annotation.*;
import lombok.Getter;
import lombok.Setter;

import java.io.Serializable;
import java.time.LocalDateTime;

/**
 * <p>
 * 变更房屋计划表
 * </p>
 *
 * @author RC
 * @since 2025-05-18
 */
@Getter
@Setter
@TableName("contract_change_plan_room")
public class ContractChangePlanRoom implements Serializable {
    private static final long serialVersionUID = 1L;

    /**
     * 变更房屋ID
     */
    @TableId(value = "pr_id", type = IdType.ASSIGN_ID)
    private String prId;

    /**
     * 合并变更计划ID
     */
    private String planId;

    /**
     * 合同ID
     */
    private String contractId;

    /**
     * 房屋ID
     */
    private String roomId;

    /**
     * 房屋名称
     */
    private String roomName;

    /**
     * 业主ID
     */
    private String ownerId;

    /**
     * 业主名称
     */
    private String ownerName;

    /**
     * 商户ID
     */
    private String storeId;

    /**
     * 数据状态：ADD 添加, DEL 删除
     */
    private String operate;

    /**
     * 创建时间
     */
    @TableField(fill = FieldFill.INSERT)
    private LocalDateTime createTime;
}

