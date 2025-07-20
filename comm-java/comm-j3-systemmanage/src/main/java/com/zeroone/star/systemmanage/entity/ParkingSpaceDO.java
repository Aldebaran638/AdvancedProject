package com.zeroone.star.systemmanage.entity;

import com.baomidou.mybatisplus.annotation.TableName;
import lombok.Data;

import java.math.BigDecimal;
import java.time.LocalDateTime;

/**
 * 车位实体类
 */
@Data
@TableName("parking_space")
public class ParkingSpaceDO {
    /**
     * 车位ID
     */
    private String psId;

    /**
     * 业务ID
     */
    private String bId;

    /**
     * 小区ID
     */
    private String communityId;

    /**
     * 车位编号
     */
    private String num;

    /**
     * 停车场ID
     */
    private String paId;

    /**
     * 车位状态 出售 S，出租 H ，空闲 F
     */
    private String state;

    /**
     * 车位面积
     */
    private BigDecimal area;

    /**
     * 备注
     */
    private String remark;

    /**
     * 创建时间
     */
    private LocalDateTime createTime;

    /**
     * 数据状态，详细参考c_status表，S 保存，0, 在用 1失效
     */
    private String statusCd;

    /**
     * 1：普通车位  2：子母车位  3：豪华车位
     */
    private String parkingType;
}