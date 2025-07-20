package com.zeroone.star.dashboard.entity;

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
 * @author fayff
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
    @TableId(value = "store_id", type = IdType.ASSIGN_ID)
    private String storeId;

    /**
     * 业务ID
     */
    @TableField("b_id")
    private String bId;

    /**
     * 用户ID
     */
    @TableField("user_id")
    private String userId;

    /**
     * 店铺名称
     */
    @TableField("name")
    private String name;

    /**
     * 店铺地址
     */
    @TableField("address")
    private String address;

    /**
     * 电话
     */
    @TableField("tel")
    private String tel;

    @TableField("store_type_cd")
    private String storeTypeCd;

    /**
     * 地标，如王府井北60米
     */
    @TableField("nearby_landmarks")
    private String nearbyLandmarks;

    /**
     * 地区 x坐标
     */
    @TableField("map_x")
    private String mapX;

    /**
     * 地区 y坐标
     */
    @TableField("map_y")
    private String mapY;

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

    /**
     * 48001 商户正常状态 48002 限制商户登录
     */
    @TableField("state")
    private String state;


}
