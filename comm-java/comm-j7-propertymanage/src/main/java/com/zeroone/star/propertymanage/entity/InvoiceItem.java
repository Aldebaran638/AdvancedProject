package com.zeroone.star.propertymanage.entity;

import cn.hutool.core.util.IdUtil;
import com.baomidou.mybatisplus.annotation.IdType;
import com.baomidou.mybatisplus.annotation.TableId;
import com.baomidou.mybatisplus.annotation.TableName;
import lombok.Getter;
import lombok.Setter;

import java.io.Serializable;

@Getter
@Setter
@TableName("invoice_apply_item")
public class InvoiceItem implements Serializable {

    /**
     * id
     */
     @TableId(value = "id")
     private String itemId;
    //雪花算法生成id
    public InvoiceItem () {
        this.itemId = IdUtil.getSnowflakeNextIdStr();
    }
    /**
     * 申请ID
     */
    private String applyId;

    /**
     *  申请项类型 1001 账户预存 2002 物业缴费
     */
    private String itemType;

    /**
     * 申请项名称
     */
    private  String itemName;

     /**
     * 收据id
     */
    private String itemObjId;

    /**
     * 收费金额
     */
    private Double itemAmount;

    /**
     * 小区ID
     */
    private String communityId;

    /**
     * 备注
     */
    private String remark;

    /**
     * 创建时间
     */
    private String createTime;

    /**
     * 数据状态，详细参考c_status表，0, 在用 1失效
     */
    private String statusCd;

    /**
     * 缴费时间
     */
    private String payTime;
}
