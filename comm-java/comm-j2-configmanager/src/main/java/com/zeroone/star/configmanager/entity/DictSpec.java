package com.zeroone.star.configmanager.entity;

import com.baomidou.mybatisplus.annotation.*;

import java.io.Serializable;
import java.time.LocalDateTime;

import lombok.Data;
import lombok.Getter;
import lombok.Setter;

/**
 * <p>
 * 
 * </p>
 *
 * @author fish
 * @since 2025-05-19
 */
@Data
@TableName("t_dict_spec")
public class DictSpec implements Serializable {

    private static final long serialVersionUID = 1L;

    /**
     * 规格ID
     */
    @TableId(value = "spec_id", type = IdType.ASSIGN_ID)
    private String specId;

    /**
     * 规格名称
     */
    @TableField("spec_name")
    private String specName;

    /**
     * 表名称
     */
    @TableField("table_name")
    private String tableName = " ";

    /**
     * 类名称
     */
    @TableField("table_columns")
    private String tableColumns = " ";

    /**
     * 创建时间
     */
    @TableField(fill = FieldFill.INSERT)
    private LocalDateTime createTime;

    /**
     * 数据状态，详细参考c_status表，S 保存，0, 在用 1失效
     */
    private String statusCd = "0";


}
