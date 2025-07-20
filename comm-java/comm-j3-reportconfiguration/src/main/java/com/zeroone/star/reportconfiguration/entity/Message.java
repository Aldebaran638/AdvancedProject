package com.zeroone.star.reportconfiguration.entity;

import com.baomidou.mybatisplus.annotation.*;
import lombok.Getter;
import lombok.Setter;

import java.io.Serializable;
import java.time.LocalDateTime;

/**
 * <p>
 * 报表信息do,对应表 `report_custom`
 * </p>
 * @author maff
 * @since 2023-04-04
 */

@Getter
@Setter
@TableName("report_custom")
public class Message implements Serializable {

    private static final long serialVersionUID = 1L;

    /**
     * 报表编号
     */
    @TableId(value = "custom_id", type = IdType.ASSIGN_ID)
    private String customId;
    /**
     * 组编号
     */
    private String groupId;
    /**
     * 选项标题
     */
    private String title;
    /**
     * 排序
     */
    private Integer seq;
    /**
     * 描述
     */
    private String remark;
    /**
     * 创建时间
     */
    @TableField(fill = FieldFill.INSERT)
    private LocalDateTime createTime;

    /**
     * 数据状态，
     */
    private String statusCd;


}
