package com.zeroone.star.communitymanage.entity.mycommunity;

import com.baomidou.mybatisplus.annotation.*;
import lombok.AllArgsConstructor;
import lombok.Data;
import lombok.NoArgsConstructor;

import java.time.LocalDateTime;

@Data
@AllArgsConstructor
@NoArgsConstructor
@TableName("s_store")
public class SStore {
    /**
     * 商户id
     */
    @TableId(value = "store_id")
    private String storeId;
    /**
     * 业务id
     */
    private String bId;
    /**
     * 用户id
     */
    private String userId;
    /**
     * 商户名称
     */
    private String name;
    /**
     * 商户地址
     */
    private String address;
    /**
     * 电话
     */
    private String tel;
    private String storeTypeCd;
    /**
     * 地标
     */
    private String nearbyLandmarks;
    /**
     * 地区 x坐标
     */
    private String mapX;
    /**
     * 地区 Y坐标
     */
    private String mapY;
    /**
     * 创建时间
     */
    @TableField(fill = FieldFill.INSERT)
    private LocalDateTime createTime;
    /**
     * 数据状态
     */
    private String statusCd;
    /**
     * 48001 商户正常状态  48002 限制商户登录
     */
    private String state;

}
