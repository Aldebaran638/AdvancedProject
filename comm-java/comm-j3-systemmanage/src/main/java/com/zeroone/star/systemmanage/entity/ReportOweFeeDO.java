package com.zeroone.star.systemmanage.entity;

import com.baomidou.mybatisplus.annotation.TableName;
import lombok.Data;

import java.math.BigDecimal;
import java.time.LocalDateTime;

@Data
@TableName("report_owe_fee")
public class ReportOweFeeDO {
    /**
     * 欠费主键
     */
    private String oweId;

    /**
     * 费用项ID
     */
    private String configId;

    /**
     * 费用项名称
     */
    private String configName;

    /**
     * 费用ID
     */
    private String feeId;

    /**
     * 费用名称
     */
    private String feeName;

    /**
     * 当前欠费金额
     */
    private BigDecimal amountOwed;

    /**
     * 业主ID
     */
    private String ownerId;

    /**
     * 业主名称
     */
    private String ownerName;

    /**
     * 业主联系电话
     */
    private String ownerTel;

    /**
     * 对象ID
     */
    private String payerObjId;

    /**
     * 付费对象名称 如 1栋1单元1室 或者 1号停车场1号车位
     */
    private String payerObjName;

    /**
     * 付费对象类型 3333 房屋 6666 是车位 9999 合同
     */
    private String payerObjType;

    /**
     * 分片键，小区ID
     */
    private String communityId;

    /**
     * 创建时间
     */
    private LocalDateTime createTime;

    /**
     * 数据更新时间
     */
    private LocalDateTime updateTime;

    /**
     * 费用结束时间，当时跑账单时的费用结束时间
     */
    private LocalDateTime endTime;

    /**
     * 截止时间
     */
    private LocalDateTime deadlineTime;

}
