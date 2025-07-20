package com.zeroone.star.datamanager.entity;


import com.baomidou.mybatisplus.annotation.*;
import lombok.Getter;
import lombok.Setter;
import java.io.Serializable;
import java.util.Date;

/**
 * <p>
 * 菜单组表
 * </p>
 *
 * @author zhangdashuai
 * @since 2025-06-13
 */
@Getter
@Setter
@TableName("m_menu_group")
public class MMenuGroup implements Serializable {

    private static final long serialVersionUID = 1L;

    /**
     * 菜单组ID
     */
    @TableId(type = IdType.ASSIGN_ID)
    private String gId;

    /**
     * 菜单组名称
     */
    private String name;

    /**
     * 菜单图片
     */
    private String icon;

    /**
     * 菜单标签
     */
    private String label;

    /**
     * 列顺序
     */
    private Integer seq;

    /**
     * 菜单描述
     */
    private String description;

    /**
     * 创建时间
     */
    @TableField(fill = FieldFill.INSERT)
    private Date createTime;

    /**
     * 数据状态，详细参考c_status表，0在用，1失效
     */
    private String statusCd;

    /**
     * 菜单类型
     */
    private String groupType;

    /**
     * 商户类型
     */
    private String storeType;
}
