package com.zeroone.star.parkmanage.entity;

import com.baomidou.mybatisplus.annotation.FieldFill;
import com.baomidou.mybatisplus.annotation.TableField;
import com.baomidou.mybatisplus.annotation.TableName;
import java.io.Serializable;
import java.time.LocalDateTime;
import lombok.Getter;
import lombok.Setter;

/**
 * <p>
 * 
 * </p>
 *
 * @author daimon
 * @since 2025-06-02
 */
@Getter
@Setter
@TableName("business_owner_car")
public class BusinessOwnerCar implements Serializable {

    private static final long serialVersionUID = 1L;

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
    @TableField(fill = FieldFill.INSERT)
    private LocalDateTime createTime;

    /**
     * 数据状态，添加ADD，修改MOD 删除DEL
     */
    private String operate;

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
