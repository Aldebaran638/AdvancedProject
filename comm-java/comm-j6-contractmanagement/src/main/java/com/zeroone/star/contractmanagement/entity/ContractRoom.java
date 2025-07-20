package com.zeroone.star.contractmanagement.entity;

import com.baomidou.mybatisplus.annotation.*;
import lombok.Getter;
import lombok.Setter;

import java.io.Serializable;
import java.time.LocalDateTime;

/**
 * <p>
 * 合同房屋关联表
 * </p>
 *
 * @author RC
 * @since 2025-05-18
 */
@Getter
@Setter
@TableName("contract_room")
public class ContractRoom implements Serializable {
    private static final long serialVersionUID = 1L;

    /**
     * 主键ID
     */
    @TableId(value = "cr_id", type = IdType.ASSIGN_ID)
    private String crId;

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
     * 创建时间
     */
    @TableField(fill = FieldFill.INSERT)
    private LocalDateTime createTime;

    /**
     * 数据状态：S 保存, 0 在用, 1 失效
     */
    @TableLogic(value = "0", delval = "1")
    private String statusCd;
}
