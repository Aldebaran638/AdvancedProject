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
 * @author 坤哥
 * @since 2025-05-18
 */
@Getter
@Setter
@TableName("contract_type")
public class ContractType implements Serializable {

    private static final long serialVersionUID = 1L;

    /**
     * ID
     */
    @TableId(value = "contract_type_id",type = IdType.ASSIGN_ID)
    private String contractTypeId;

    /**
     * 合同类型名称
     */
    private String typeName;

    /**
     * 是否需要审核，1001 需要审核 2002 不需要审核 3003 需要admin审核  4004 需要 代理商审核
     */
    private String audit;

    /**
     * T 默认 F 自定义
     */
    private String isDefault;

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
     * 数据状态，详细参考c_status表，S 保存，0, 在用 1失效
     */
    @TableLogic(value = "0", delval = "1")
    private String statusCd;

    /**
     * 备注
     */
    private String remark;


}
