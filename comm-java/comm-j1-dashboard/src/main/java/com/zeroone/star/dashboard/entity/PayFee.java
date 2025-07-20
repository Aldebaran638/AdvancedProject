package com.zeroone.star.dashboard.entity;

import com.baomidou.mybatisplus.annotation.*;

import java.io.Serializable;
import java.math.BigDecimal;
import java.time.LocalDateTime;
import lombok.Getter;
import lombok.Setter;

/**
 * <p>
 * 
 * </p>
 *
 * @author fayff
 * @since 2025-05-21
 */
@Getter
@Setter
@TableName("pay_fee")
public class PayFee implements Serializable {

    private static final long serialVersionUID = 1L;

    /**
     * 费用ID
     */
    @TableId(value = "fee_id", type = IdType.ASSIGN_ID)
    private String feeId;

    /**
     * 业务ID
     */
    @TableField("b_id")
    private String bId;

    /**
     * 费用类型，物业费，停车费
     */
    @TableField("fee_type_cd")
    private String feeTypeCd;

    /**
     * 小区ID
     */
    @TableField("community_id")
    private String communityId;

    /**
     * 付款方ID
     */
    @TableField("payer_obj_id")
    private String payerObjId;

    /**
     * 收款方ID
     */
    @TableField("income_obj_id")
    private String incomeObjId;

    /**
     * 开始时间
     */
    @TableField("start_time")
    private LocalDateTime startTime;

    /**
     * 结束时间
     */
    @TableField("end_time")
    private LocalDateTime endTime;

    /**
     * 总金额，如物业费，停车费等没有总金额的，填写为-1.00
     */
    @TableField("amount")
    private BigDecimal amount;

    /**
     * 创建用户ID
     */
    @TableField("user_id")
    private String userId;

    /**
     * 创建时间
     */
    @TableField(value = "create_time", fill = FieldFill.INSERT)
    private LocalDateTime createTime;

    /**
     * 数据状态，详细参考c_status表，S 保存，0, 在用 1失效
     */
    @TableField("status_cd")
    private String statusCd;

    /**
     * 费用标识 1003006 为周期性费用 2006012 为一次性费用
     */
    @TableField("fee_flag")
    private String feeFlag;

    /**
     * 状态 2007001收费未开始 2008001 收费中状态 2009001 收费结束
     */
    @TableField("state")
    private String state;

    /**
     * 费用项ID
     */
    @TableField("config_id")
    private String configId;

    /**
     * 付费对象类型 3333 房屋 6666 是车位
     */
    @TableField("payer_obj_type")
    private String payerObjType;

    /**
     * 批次ID
     */
    @TableField("batch_id")
    private String batchId;
}
