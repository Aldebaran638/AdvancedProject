package com.zeroone.star.patrolmgt.entity;

import com.baomidou.mybatisplus.annotation.*;
import lombok.Getter;
import lombok.Setter;

import java.io.Serializable;
import java.time.LocalDateTime;

/**
 * <p>
 * 
 * </p>
 *
 * @author 唐森权
 * @since 2025-05-16
 */
@Getter
@Setter
@TableName("inspection_item_title_value")
public class InspectionItemTitleValue implements Serializable {

    private static final long serialVersionUID = 1L;

    /**
     * 主键ID
     */
    @TableId(value = "value_Id",type = IdType.ASSIGN_ID)
    private String valueId;

    /**
     * 题目ID
     */
    private String titleId;

    /**
     * 选项说明
     */
    private String itemValue;

    /**
     * 小区ID
     */
    @TableField(value = "community_id", insertStrategy = FieldStrategy.NOT_EMPTY)
    private String communityId;

    /**
     * 显示顺序
     */
    private Integer seq;

    /**
     * 创建时间
     */
    @TableField(fill = FieldFill.INSERT)
    private LocalDateTime createTime;

    /**
     * 数据状态，详细参考c_status表，S 保存，0, 在用 1失效
     */
    private String statusCd;


}
