package com.zeroone.star.parkmanage.entity;

import com.baomidou.mybatisplus.annotation.*;

import java.io.Serializable;
import java.time.LocalDateTime;

import lombok.AllArgsConstructor;
import lombok.Getter;
import lombok.NoArgsConstructor;
import lombok.Setter;

/**
 * <p>
 * 
 * </p>
 *
 * @author wuven
 * @since 2025-05-26
 */
@Getter
@Setter
@TableName("parking_area_attr")
@AllArgsConstructor
@NoArgsConstructor
public class ParkingAreaAttr implements Serializable {

    private static final long serialVersionUID = 1L;

    /**
     * 业务ID
     */
    private String bId;

    /**
     * 属性id 使用雪花算法新增id
     */
    @TableId(type = IdType.ASSIGN_ID)
    private String attrId;

    /**
     * 停车场ID
     */
    private String paId;

    /**
     * 小区ID
     */
    private String communityId;

    /**
     * 规格id,参考spec表
     */
    private String specCd;

    /**
     * 属性值
     */
    private String value;

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
