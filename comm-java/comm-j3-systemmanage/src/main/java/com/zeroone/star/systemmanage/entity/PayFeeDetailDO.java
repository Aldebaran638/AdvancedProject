package com.zeroone.star.systemmanage.entity;

import com.baomidou.mybatisplus.annotation.TableName;
import lombok.Data;

import java.math.BigDecimal;
import java.time.LocalDateTime;

/**
 * 费用明细实体类
 */
@Data
@TableName("pay_fee_detail")
public class PayFeeDetailDO {
    /**
     * 费用明细ID
     */
    private String detailId;

    /**
     * 业务ID
     */
    private String bId;

    /**
     * 费用ID
     */
    private String feeId;

    /**
     * 小区ID
     */
    private String communityId;

    /**
     * 周期，以月为单位
     */
    private BigDecimal cycles;

    /**
     * 应收金额
     */
    private BigDecimal receivableAmount;

    /**
     * 应收金额
     */
    private BigDecimal receivedAmount;

    /**
     * 支付方式
     */
    private BigDecimal primeRate;

    /**
     * 备注
     */
    private String remark;

    /**
     * 创建时间
     */
    private LocalDateTime createTime;

    /**
     * 数据状态，详细参考c_status表，S 保存，0, 在用 1失效
     */
    private String statusCd;

    /**
     * 用于退费状态参考字典表
     */
    private String state;

    /**
     * 费用开始时间
     */
    private LocalDateTime startTime;

    /**
     * 费用结束时间
     */
    private LocalDateTime endTime;

    /**
     * 应缴金额
     */
    private BigDecimal payableAmount;

    /**
     * 支付订单ID
     */
    private String payOrderId;

    /**
     * 收银员ID，员工ID
     */
    private String cashierId;

    /**
     * 收银员,员工
     */
    private String cashierName;

    /**
     * 是否开票 Y 已开票 N 未开票
     */
    private String openInvoice;

    /**
     * 账户抵扣金额
     */
    private BigDecimal acctAmount;

    /**
     * 优惠打折金额
     */
    private BigDecimal discountAmount;

    /**
     * 优惠减免金额
     */
    private BigDecimal deductionAmount;

    /**
     * 滞纳金
     */
    private BigDecimal lateAmount;

    /**
     * 赠送金额
     */
    private BigDecimal giftAmount;
}