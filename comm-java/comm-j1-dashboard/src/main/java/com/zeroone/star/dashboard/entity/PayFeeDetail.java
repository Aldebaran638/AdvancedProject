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
@TableName("pay_fee_detail")
public class PayFeeDetail implements Serializable {

    private static final long serialVersionUID = 1L;

    /**
     * 费用明细ID
     */
    @TableId(value = "detail_id", type = IdType.ASSIGN_ID)
    private String detailId;

    /**
     * 业务ID
     */
    @TableField("b_id")
    private String bId;

    /**
     * 费用ID
     */
    @TableField("fee_id")
    private String feeId;

    /**
     * 小区ID
     */
    @TableField("community_id")
    private String communityId;

    /**
     * 周期，以月为单位
     */
    @TableField("cycles")
    private BigDecimal cycles;

    /**
     * 应收金额
     */
    @TableField("receivable_amount")
    private BigDecimal receivableAmount;

    /**
     * 应收金额
     */
    @TableField("received_amount")
    private BigDecimal receivedAmount;

    /**
     * 支付方式
     */
    @TableField("prime_rate")
    private BigDecimal primeRate;

    /**
     * 备注
     */
    @TableField("remark")
    private String remark;

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
     * 用于退费状态参考字典表
     */
    @TableField("state")
    private String state;

    /**
     * 费用开始时间
     */
    @TableField("start_time")
    private LocalDateTime startTime;

    /**
     * 费用结束时间
     */
    @TableField("end_time")
    private LocalDateTime endTime;

    /**
     * 应缴金额
     */
    @TableField("payable_amount")
    private BigDecimal payableAmount;

    /**
     * 支付订单ID
     */
    @TableField("pay_order_id")
    private String payOrderId;

    /**
     * 收银员ID，员工ID
     */
    @TableField("cashier_id")
    private String cashierId;

    /**
     * 收银员,员工
     */
    @TableField("cashier_name")
    private String cashierName;

    /**
     * 是否开票 Y 已开票 N 未开票
     */
    @TableField("open_invoice")
    private String openInvoice;

    /**
     * 账户抵扣金额
     */
    @TableField("acct_amount")
    private BigDecimal acctAmount;

    /**
     * 优惠打折金额
     */
    @TableField("discount_amount")
    private BigDecimal discountAmount;

    /**
     * 优惠减免金额
     */
    @TableField("deduction_amount")
    private BigDecimal deductionAmount;

    /**
     * 滞纳金
     */
    @TableField("late_amount")
    private BigDecimal lateAmount;

    /**
     * 赠送金额
     */
    @TableField("gift_amount")
    private BigDecimal giftAmount;


}
