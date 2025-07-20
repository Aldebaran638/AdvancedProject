package com.zeroone.star.systemmanage.entity;

import com.baomidou.mybatisplus.annotation.TableName;
import lombok.Data;

import java.time.LocalDateTime;

/**
 * 业主车辆实体类
 */
@Data
@TableName("owner_car")
public class OwnerCarDO {
    /**
     * 汽车ID
     */
    private String carId;

    /**
     * 业主ID
     */
    private String ownerId;

    /**
     * 业务Id
     */
    private String bId;

    /**
     * 车牌号
     */
    private String carNum;

    /**
     * 汽车品牌
     */
    private String carBrand;

    /**
     * 9901 家用小汽车，9902 客车，9903 货车
     */
    private String carType;

    /**
     * 颜色
     */
    private String carColor;

    /**
     * 车位ID
     */
    private String psId;

    /**
     * 用户ID
     */
    private String userId;

    /**
     * 备注
     */
    private String remark;

    /**
     * 创建时间
     */
    private LocalDateTime createTime;

    /**
     * 数据状态，详细参考c_status表，0, 在用 1失效
     */
    private String statusCd;

    /**
     * 小区ID
     */
    private String communityId;

    /**
     * 起租时间
     */
    private LocalDateTime startTime;

    /**
     * 结租时间
     */
    private LocalDateTime endTime;

    /**
     * 状态，1001 正常状态，2002 车位释放欠费状态  3003 车位释放
     */
    private String state;

    /**
     * 1001 主车辆 1002 成员车辆
     */
    private String carTypeCd;

    /**
     * 成员ID
     */
    private String memberId;

    /**
     * 租赁类型，H 月租车 S 出售车 I 内部车 NM 免费车
     */
    private String leaseType;
}