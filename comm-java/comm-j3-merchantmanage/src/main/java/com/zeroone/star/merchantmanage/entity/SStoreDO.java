package com.zeroone.star.merchantmanage.entity;

import com.baomidou.mybatisplus.annotation.FieldFill;
import com.baomidou.mybatisplus.annotation.TableField;
import com.baomidou.mybatisplus.annotation.TableId;
import com.baomidou.mybatisplus.annotation.TableName;
import lombok.Data;

import java.time.LocalDateTime;

/**
 * s_store表
 *
 * @author wyr on 2025/5/24
 */

@TableName("s_store")
@Data
public class SStoreDO {

    // 商店ID
    @TableId
    private String storeId;
    // 业务ID
    private String bId;
    // 用户ID
    private String userId;
    // 店铺名称
    private String name;
    // 店铺地址
    private String address;
    // 电话
    private String tel;
    // 店铺类型
    private String storeTypeCd;
    // 地标，如王府井北60米
    private String nearbyLandmarks;
    // 地区 x坐标
    private String mapX;
    // 地区 y坐标
    private String mapY;
    // 创建时间
    private LocalDateTime  createTime;
    // 数据状态，详细参考c_status表，S 保存，0, 在用 1失效(提示信息)
    private String statusCd;
    // 数据状态, 40081 正常登录 40082 限制登录
    private String state;

}
