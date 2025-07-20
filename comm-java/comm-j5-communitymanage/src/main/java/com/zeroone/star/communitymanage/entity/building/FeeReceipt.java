package com.zeroone.star.communitymanage.entity.building;

import com.baomidou.mybatisplus.annotation.FieldFill;
import com.baomidou.mybatisplus.annotation.TableField;
import com.baomidou.mybatisplus.annotation.TableName;
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
 * @author langzi
 * @since 2025-05-23
 */
@Getter
@Setter
@TableName("fee_receipt")
public class FeeReceipt implements Serializable {

    private static final long serialVersionUID = 1L;

    /**
     * 收据ID
     */
    private String receiptId;

    /**
     * 小区ID
     */
    private String communityId;

    /**
     * 收据对象 3333 房屋 6666 车位车辆
     */
    private String objType;

    /**
     * 对象ID
     */
    private String objId;

    /**
     * 对象名称
     */
    private String objName;

    /**
     * 实收金额
     */
    private BigDecimal amount;

    /**
     * 创建时间
     */
    @TableField(fill = FieldFill.INSERT)
    private LocalDateTime createTime;

    /**
     * 数据状态
     */
    private String statusCd;

    /**
     * 备注
     */
    private String remark;

    /**
     * 付费人
     */
    private String payObjId;

    /**
     * 付费人
     */
    private String payObjName;

    /**
     * 收据编号
     */
    private String receiptCode;

    /**
     * 应收金额
     */
    private BigDecimal receivableAmount;


}
