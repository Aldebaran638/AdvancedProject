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
@TableName("inspection_item")
public class InspectionItem implements Serializable {

    private static final long serialVersionUID = 1L;

    /**
     * 主键ID
     */
    @TableId(value = "item_id", type = IdType.ASSIGN_ID)
    private String itemId;

    /**
     * 巡检项目
     */
    private String itemName;

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
    @TableField(fill = FieldFill.INSERT)
    private LocalDateTime createTime;

    /**
     * 数据状态，详细参考c_status表，S 保存，0, 在用 1失效
     */
    private String statusCd;


}
