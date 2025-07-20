package com.zeroone.star.parkmanage.entity;

import com.baomidou.mybatisplus.annotation.FieldFill;
import com.baomidou.mybatisplus.annotation.IdType;
import com.baomidou.mybatisplus.annotation.TableField;
import com.baomidou.mybatisplus.annotation.TableId;
import com.baomidou.mybatisplus.annotation.TableName;
import java.io.Serializable;
import java.time.LocalDateTime;

import lombok.Getter;
import lombok.Setter;

/**
 * <p>
 * 会员车辆信息表
 * </p>
 *
 * @author yourName
 * @since 2025-06-04
 */
@Getter
@Setter
@TableName("owner_car")
public class MemberVehicle implements Serializable {

    private static final long serialVersionUID = 1L;

    /**
     * 主键ID
     */
    @TableId(value = "id", type = IdType.ASSIGN_ID)
    private String id;

    /**
     * 车牌号
     */
    private String carNum;

    /**
     * 房屋号
     */
    private String roomNum;

    /**
     * 车辆品牌
     */
    private String carBrand;

    /**
     * 车辆类型
     */
    private String carType;

    /**
     * 车辆颜色
     */
    private String carColor;

    /**
     * 业主名字
     */
    private String name;

    /**
     * 业主电话
     */
    private String tel;

    /**
     * 车场编号
     */
    private String psNum;

    /**
     * 车位编号
     */
    private String paNum;

    /**
     * 有效期
     */
    private String validityPeriod;

    /**
     * 状态
     */
    private String status;

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
     * 更新时间
     */
    @TableField(fill = FieldFill.UPDATE)
    private LocalDateTime updateTime;

}
