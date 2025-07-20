package com.zeroone.star.datamanager.entity;

import com.baomidou.mybatisplus.annotation.*;
import lombok.Getter;
import lombok.Setter;

import java.io.Serializable;
import java.util.Date;
import java.util.List;

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
@TableName("s_store")
public class SStore implements Serializable {

    private static final long serialVersionUID = 1L;

    /**
     * 商店ID
     */
    @TableId(type = IdType.ASSIGN_ID)
    private String storeId;

    /**
     * 业务ID
     */
    private String bId;

    /**
     * 用户ID
     */
    private String userId;

    /**
     * 店铺名称
     */
    private String name;

    /**
     * 店铺地址
     */
    private String address;

    /**
     * 电话
     */
    private String tel;

    private String storeTypeCd;

    /**
     * 地标，如王府井北60米
     */
    private String nearbyLandmarks;

    /**
     * 地区 x坐标
     */
    private String mapX;

    /**
     * 地区 y坐标
     */
    private String mapY;

    /**
     * 创建时间
     */
    @TableField(fill = FieldFill.INSERT)
    private Date createTime;

    /**
     * 数据状态，详细参考c_status表，S 保存，0, 在用 1失效
     */
    private String statusCd;

    /**
     * 48001 商户正常状态 48002 限制商户登录
     */
    private String state;

    /**
     * 关联的小区名字
     */
    @TableField(exist = false)
    private String openCommunityName;

    /**
     * 功能权限（逗号分隔的字符串）
     */
    @TableField(exist = false)
    private List<String> functions;


}
