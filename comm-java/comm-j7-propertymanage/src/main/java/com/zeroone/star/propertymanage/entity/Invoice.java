package com.zeroone.star.propertymanage.entity;

import cn.hutool.core.util.IdUtil;
import com.baomidou.mybatisplus.annotation.IdType;
import com.baomidou.mybatisplus.annotation.TableId;
import com.baomidou.mybatisplus.annotation.TableName;
import lombok.*;

import java.io.Serializable;

/**
 * <p>
 * 发票表
 * </p>
 *
 * @author douya266
 * @since 2025-05-25
 */
@Data
@TableName("invoice_apply")
@Builder
@AllArgsConstructor
public class Invoice implements Serializable {
    /**
     * ID
     */
    @TableId(value = "apply_id", type = IdType.ASSIGN_ID)
    private String applyId;

    //雪花算法生成id
    public Invoice () {
        this.applyId = IdUtil.getSnowflakeNextIdStr();
    }

    /**
     * 业主发票ID
     */
    private String oiId;

    /**
     * 发票类型 1001 个人 2002 企业
     */
    private String invoiceType;

    /**
     * 业主名称
     */
    private String ownerName;

    /**
     * 申请电话
     */
    private String applyTel;

    /**
     * 申请金额
     */
    private Double invoiceAmount;

    /**
     * 小区ID
     */
    private String communityId;

    /**
     * 用户ID
     */
    private String createUserId;

    /**
     * 申请人
     */
    private String createUserName;

    /**
     * 审核状态 W待审核 U 待上传 F 审核失败 G 带领用 C 已领用
     */
    private String state;

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
     * 发票编号
     */
    private String invoiceCode;

}
