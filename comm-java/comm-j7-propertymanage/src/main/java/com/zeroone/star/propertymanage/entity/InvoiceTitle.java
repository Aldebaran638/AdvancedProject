package com.zeroone.star.propertymanage.entity;

import lombok.AllArgsConstructor;
import lombok.Data;
import lombok.NoArgsConstructor;

import java.io.Serializable;
import java.time.LocalDateTime;
@Data
@AllArgsConstructor
@NoArgsConstructor
public class InvoiceTitle implements Serializable {
    private String oiId;

    /**
     * 业主ID
     */
    private String ownerId;

    /**
     * 业主名称
     */
    private String ownerName;

    /**
     * 发票类型 1001 个人 2002 企业
     */
    private String invoiceType;

    /**
     * 小区ID
     */
    private String communityId;

    /**
     * 发票名头
     */
    private String invoiceName;

    /**
     * 纳税人识别号
     */
    private String invoiceNum;

    /**
     * 地址、电话
     */
    private String invoiceAddress;

    /**
     * 备注
     */
    private String remark;

    /**
     * 创建时间
     */
    private LocalDateTime createTime;

    /**
     * 数据状态，详细参考c_status表，0, 在用 1失效
     */
    private String statusCd;

}
