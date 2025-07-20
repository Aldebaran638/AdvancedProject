package com.zeroone.star.configmanager.entity;

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
 * @author hubery
 * @since 2025-05-16
 */
@Getter
@Setter
@TableName("c_mapping_domain")
public class CMappingDomain implements Serializable {

    private static final long serialVersionUID = 1L;

    /**
     * id
     */
    @TableId(type = IdType.ASSIGN_ID)
    private String id;

    /**
     * 域
     */
    private String domain;

    /**
     * 配置项
     */
    private String domainName;

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
     * 数据状态，详细参考c_status表，0在用，1失效
     */
    private String statusCd;


}
