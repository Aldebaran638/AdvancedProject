package com.zeroone.star.merchantmanage.entity;

/**
 * s_store_attr
 *
 * @author wyr on 2025/5/24
 */

import com.baomidou.mybatisplus.annotation.FieldFill;
import com.baomidou.mybatisplus.annotation.TableField;
import com.baomidou.mybatisplus.annotation.TableId;
import com.baomidou.mybatisplus.annotation.TableName;
import lombok.Data;

import java.time.LocalDateTime;

@Data
@TableName("s_store_attr")
public class SStoreAttrDO {
    // 属性id
    @TableId
    private String attrId;
    // 业务ID
    private String bId;
    // 用户ID
    private String storeId;
    // 规格id,参考spec表
    private String specCd;
    // 属性值
    private String value;
    // 创建时间
    private LocalDateTime createTime;
    // 数据状态，详细参考c_status表，S 保存，0, 在用 1失效
    private String statusCd;
}
