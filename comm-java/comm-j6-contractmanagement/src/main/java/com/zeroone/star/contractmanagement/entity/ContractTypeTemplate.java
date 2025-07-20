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
 * @author kunge
 * @since 2025-06-03
 */
@Getter
@Setter
@TableName("contract_type_template")
public class ContractTypeTemplate implements Serializable {

    private static final long serialVersionUID = 1L;

    /**
     * 模板ID
     */
    @TableId(value = "template_id",type = IdType.ASSIGN_ID)
    private String templateId;

    /**
     * 合同类型ID
     */
    private String contractTypeId;

    /**
     * 商户ID
     */
    private String storeId;

    /**
     * 模板内容
     */
    private String context;

    /**
     * 创建时间
     */
    @TableField(fill = FieldFill.INSERT)
    private LocalDateTime createTime;

    /**
     * 状态值
     */
    @TableLogic(value = "0",delval = "1")
    private String statusCd;


}
