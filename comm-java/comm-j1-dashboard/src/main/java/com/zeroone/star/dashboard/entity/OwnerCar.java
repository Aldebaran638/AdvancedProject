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
@TableName("owner_car")
public class OwnerCar implements Serializable {

    private static final long serialVersionUID = 1L;

    /**
     * 汽车ID
     */
    @TableId(value = "car_id", type = IdType.ASSIGN_ID)
    private String carId;

    /**
     * 业主ID
     */
    @TableField("owner_id")
    private String ownerId;

    /**
     * 业务Id
     */
    @TableField("b_id")
    private String bId;

    /**
     * 车牌号
     */
    @TableField("car_num")
    private String carNum;

    /**
     * 汽车品牌
     */
    @TableField("car_brand")
    private String carBrand;

    /**
     * 9901 家用小汽车，9902 客车，9903 货车
     */
    @TableField("car_type")
    private String carType;

    /**
     * 颜色
     */
    @TableField("car_color")
    private String carColor;

    /**
     * 车位ID
     */
    @TableField("ps_id")
    private String psId;

    /**
     * 用户ID
     */
    @TableField("user_id")
    private String userId;

    /**
     * 备注
     */
    @TableField("remark")
    private String remark;

    /**
     * 创建时间
     */
    @TableField(value = "create_time", fill = FieldFill.INSERT)
    private LocalDateTime createTime;

    /**
     * 数据状态，详细参考c_status表，0, 在用 1失效
     */
    @TableField("status_cd")
    private String statusCd;

    /**
     * 小区ID
     */
    @TableField("community_id")
    private String communityId;

    /**
     * 起租时间
     */
    @TableField("start_time")
    private LocalDateTime startTime;

    /**
     * 结租时间
     */
    @TableField("end_time")
    private LocalDateTime endTime;

    /**
     * 状态，1001 正常状态，2002 车位释放欠费状态  3003 车位释放
     */
    @TableField("state")
    private String state;

    /**
     * 1001 主车辆 1002 成员车辆
     */
    @TableField("car_type_cd")
    private String carTypeCd;

    /**
     * 成员ID
     */
    @TableField("member_id")
    private String memberId;

    /**
     * 租赁类型，H 月租车 S 出售车 I 内部车 NM 免费车
     */
    @TableField("lease_type")
    private String leaseType;
}
