package com.zeroone.star.patrolmgt.entity;

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
 * @author panzhire
 * @since 2025-05-29
 */
@Getter
@Setter
@TableName("inspection_item_title")
public class TangSenQuan_InspectionItemTitle implements Serializable {

    private static final long serialVersionUID = 1L;
    
    /**
     * 主键ID
     */
    @TableId(value = "title_id", type = IdType.ASSIGN_ID)
    private String titleId;
    
    /**
     * 项目编号
     */
    @TableField(value = "item_id", fill = FieldFill.INSERT)
    private String itemId;
    
    /**
     * 名称
     */
    @TableField("item_title")
    private String itemTitle;
    
    /**
     * 题目类型 1001 单选 2002 多选 3003 简答题
     */
    @TableField("title_type")
    private String titleType;
    
    /**
     * 小区ID
     */
    @TableField("community_id")
    private String communityId;
    
    /**
     * 显示顺序
     */
    private Integer seq;
    
    /**
     * 创建时间
     */
    @TableField(value = "create_time", fill = FieldFill.INSERT)
    private LocalDateTime createTime;
    
    /**
     * 数据状态，详细参考c_status表，S 保存，0, 在用 1失效
     */
    @TableField("status_cd")
    private String statusCd;
    
}
