package com.zeroone.star.contractmanagement.entity;
import com.baomidou.mybatisplus.annotation.*;
import lombok.Getter;
import lombok.Setter;

import java.io.Serializable;
import java.math.BigDecimal;
import java.time.LocalDateTime;

/**
 * <p>
 * 合同信息表
 * </p>
 *
 * @author 554461614
 * @since 2025-05-18
 */
//Contract的DO，对应数据库
@Getter
@Setter
@TableName("contract")
public class Contract implements Serializable {
    private static final long serialVersionUID = 1L;

    /**
     * 合同ID
     */
    @TableId(value = "contract_id", type = IdType.ASSIGN_ID)
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
    private String objType;

    /**
     * 合同对象
     */
    private String objId;

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
     * 创建时间
     */
    @TableField(fill = FieldFill.INSERT)
    private LocalDateTime createTime;

    /**
     * 数据状态（S 保存，0 在用，1 失效）
     */
    @TableLogic(value = "0", delval = "1")
    private String statusCd;

    /**
     * 合同状态（11 待审核，22 审核通过，33 审核失败，44 手工停止）
     */
    private String state;

    /**
     * 审核意见
     */
    private String stateDesc;

    /**
     * 父合同ID
     */
    private String contractParentId;

    /**
     * 合同对象名称
     */
    private String objName;

    /**
     * 合同对象用户名称
     */
    private String objPersonName;

    /**
     * 合同对象用户ID
     */
    private String objPersonId;

    /**
     * 提交用户
     */
    private String startUserId;
}
