package com.zeroone.star.systemmanage.entity;

import com.baomidou.mybatisplus.annotation.TableName;
import lombok.Data;

import java.math.BigDecimal;
import java.time.LocalDateTime;

@Data
@TableName("account")
public class AccountDO {
    /**
     * 账户ID
     */
    private String acctId;

    /**
     * 账户名称
     */
    private String acctName;

    /**
     * 账户类型，2003 现金账户 2004 积分账户 2005 优惠券账户
     */
    private String acctType;

    /**
     * 金额
     */
    private BigDecimal amount;

    /**
     * 对象类型，6006 个人 7007 商户
     */
    private String objType;

    /**
     * 对象ID
     */
    private String objId;

    /**
     * 业务Id
     */
    private String bId;

    /**
     * 创建时间
     */
    private LocalDateTime createTime;

    /**
     * 数据状态，详细参考c_status表，S 保存，0, 在用 1失效
     */
    private String statusCd;

    /**
     * 局部ID
     */
    private String partId;

    /**
     * 账户手机号
     */
    private String link;
}
