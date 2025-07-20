package com.zeroone.star.systemmanage.entity;

import com.baomidou.mybatisplus.annotation.TableName;
import lombok.Data;

import java.math.BigDecimal;
import java.time.LocalDateTime;

/**
 * 费用按月明细实体类
 */
@Data
@TableName("pay_fee_detail_month")
public class PayFeeDetailMonthDO {
    /**
     * 月ID
     */
    private String monthId;

    /**
     * 费用ID
     */
    private String feeId;

    /**
     * 费用明细ID
     */
    private String detailId;

    /**
     * 小区ID
     */
    private String communityId;

    /**
     * 年
     */
    private Integer detailYear;

    /**
     * 月
     */
    private Integer detailMonth;

    /**
     * 应收金额
     */
    private BigDecimal receivableAmount;

    /**
     * 应收金额
     */
    private BigDecimal receivedAmount;

    /**
     * 折扣金额
     */
    private BigDecimal discountAmount;

    /**
     * 说明
     */
    private String remark;

    /**
     * 创建时间
     */
    private LocalDateTime createTime;

    /**
     * 数据状态
     */
    private String statusCd;

    /**
     * 收费对象
     */
    private String objName;

    /**
     * 收费对象
     */
    private String objId;

    /**
     * 业主名称
     */
    private String ownerName;

    /**
     * 业主ID
     */
    private String ownerId;

    /**
     * 手机号
     */
    private String link;

    /**
     * 状态 W 未缴费 C缴费完成 R 已退费
     */
    private String state;

    /**
     * 缴费时间
     */
    private LocalDateTime payFeeTime;

    /**
     * 当月时间
     */
    private LocalDateTime curMonthTime;

    /**
     * 费用名称
     */
    private String feeName;

    /**
     * 标准ID
     */
    private String configId;

    /**
     * 缴费截止时间
     */
    private LocalDateTime deadlineTime;

    /**
     * 对象目录，房屋时 floor_id 车辆时 pa_id 合同时 contract_type_id
     */
    private String objFpcId;

    /**
     * 费用大类
     */
    private String feeTypeCd;
}