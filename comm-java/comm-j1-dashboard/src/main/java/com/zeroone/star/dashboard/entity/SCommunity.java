package com.zeroone.star.dashboard.entity;

import com.baomidou.mybatisplus.annotation.*;

import java.io.Serializable;
import java.math.BigDecimal;
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
@TableName("s_community")
public class SCommunity implements Serializable {

    private static final long serialVersionUID = 1L;

    /**
     * 小区ID
     */
    @TableId(value = "community_id", type = IdType.ASSIGN_ID)
    private String communityId;

    /**
     * 业务ID
     */
    @TableField("b_id")
    private String bId;

    /**
     * 小区名称
     */
    @TableField("name")
    private String name;

    /**
     * 小区地址
     */
    @TableField("address")
    private String address;

    /**
     * 地标，如王府井北60米
     */
    @TableField("nearby_landmarks")
    private String nearbyLandmarks;

    /**
     * 根据定位获取城市编码
     */
    @TableField("city_code")
    private String cityCode;

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
     * '业务状态 1000 为待审核 1200审核拒绝'
     */
    @TableField("state")
    private String state;

    /**
     * 小区面积
     */
    @TableField("community_area")
    private BigDecimal communityArea;

    /**
     * 联系方式
     */
    @TableField("tel")
    private String tel;

    /**
     * 缴费周期
     */
    @TableField("pay_fee_month")
    private Long payFeeMonth;

    /**
     * 缴费周期
     */
    @TableField("fee_price")
    private BigDecimal feePrice;

    /**
     * 客服二维码
     */
    @TableField("qr_code")
    private String qrCode;


}
