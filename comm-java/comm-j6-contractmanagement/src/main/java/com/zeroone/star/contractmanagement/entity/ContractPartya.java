package com.zeroone.star.contractmanagement.entity;

import com.baomidou.mybatisplus.annotation.*;

import java.io.Serializable;
import java.time.LocalDateTime;
import lombok.Getter;
import lombok.Setter;

/**
 * <p>
 *
 * </p>
 *
 * @author denghuo
 * @since 2025-05-25
 */
@Getter
@Setter
@TableName("contract_partya")
public class ContractPartya implements Serializable {

    private static final long serialVersionUID = 1L;

    /**
     * 甲方主键
     */
    @TableId(value = "partya_id",type = IdType.ASSIGN_ID)
    private String partyaId;

    /**
     * 甲方
     */
    private String partyA;

    /**
     * 甲方联系人
     */
    private String aContacts;

    /**
     * 甲方联系电话
     */
    private String aLink;

    /**
     * 创建时间
     */
    @TableField(fill = FieldFill.INSERT)
    private LocalDateTime createTime;

    /**
     * 数据状态，详细参考c_status表，S 保存，0, 在用 1失效
     */
    @TableLogic(value = "0", delval = "1")
    private String statusCd;

    /**
     * 商户ID
     */
    private String storeId;

}
