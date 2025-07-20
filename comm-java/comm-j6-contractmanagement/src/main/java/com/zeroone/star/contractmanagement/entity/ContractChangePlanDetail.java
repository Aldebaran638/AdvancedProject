package com.zeroone.star.contractmanagement.entity;

import com.baomidou.mybatisplus.annotation.*;
import lombok.Getter;
import lombok.Setter;

import java.io.Serializable;
import java.math.BigDecimal;
import java.time.LocalDateTime;

/**
 * <p>
 * 合同变更计划明细表
 * </p>
 *
 * @author RC
 * @since 2025-05-18
 */
@Getter
@Setter
@TableName("contract_change_plan_detail")
public class ContractChangePlanDetail implements Serializable {
    private static final long serialVersionUID = 1L;

    /**
     * 变更明细ID
     */
    @TableId(value = "detail_id", type = IdType.ASSIGN_ID)
    private String detailId;

    /**
     * 合并变更计划ID
     */
    private String planId;

    /**
     * 合同ID
     */
    private String contractId;

    /**
     * 合同编码
     */
    private String contractCode;

    /**
     * 合同名称
     */
    private String contractName;

    /**
     * 合同类型
     */
    private String contractType;

    /**
     * 合同对象类型：3333 房屋，1111 没有合同对象
     */
    private String objType = "1111";

    /**
     * 合同对象
     */
    private String objId = "-1";

    /**
     * 甲方
     */
    private String partyA;

    /**
     * 乙方
     */
    private String partyB;

    /**
     * 甲方联系人
     */
    private String aContacts;

    /**
     * 甲方联系电话
     */
    private String aLink;

    /**
     * 乙方联系人
     */
    private String bContacts;

    /**
     * 乙方联系电话
     */
    private String bLink;

    /**
     * 经办人
     */
    private String operator;

    /**
     * 经办人电话
     */
    private String operatorLink;

    /**
     * 合同金额
     */
    private BigDecimal amount;

    /**
     * 合同开始时间
     */
    private LocalDateTime startTime;

    /**
     * 合同结束时间
     */
    private LocalDateTime endTime;

    /**
     * 签订时间
     */
    private LocalDateTime signingTime;

    /**
     * 商户ID
     */
    private String storeId;

    /**
     * 数据操作标识：ADD 添加，DEL 删除
     */
//    @TableLogic(value = "ADD",delval = "DEL")
    private String operate;

    /**
     * 创建时间
     */
    @TableField(fill = FieldFill.INSERT)
    private LocalDateTime createTime;

}
