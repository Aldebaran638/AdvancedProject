package com.zeroone.star.datamanager.entity;

import com.baomidou.mybatisplus.annotation.FieldFill;
import com.baomidou.mybatisplus.annotation.TableField;
import com.baomidou.mybatisplus.annotation.TableName;
import java.io.Serializable;
import java.time.LocalDateTime;
import lombok.Getter;
import lombok.Setter;

/**
 * <p>
 * 
 * </p>
 *
 * @author zhangdashuai
 * @since 2025-05-21
 */
@Getter
@Setter
@TableName("s_community_attr")
public class SCommunityAttr implements Serializable {

    private static final long serialVersionUID = 1L;

    /**
     * 业务ID
     */
    private String bId;

    /**
     * 属性id
     */
    private String attrId;

    /**
     * 用户ID
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
