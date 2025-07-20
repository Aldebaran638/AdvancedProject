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
 * 车位申请记录表
 * </p>
 *
 * @author zhangjiaqi
 * @since 2025-05-25
 */
@Getter
@Setter
@TableName("parking_space_apply")
public class ParkingApply implements Serializable {

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
     * 汽车品牌
     */
    private String carBrand;

    /**
     * 车辆类型
     */
    private String carType;

    /**
     * 颜色
     */
    private String carColor;

    /**
     * 起租时间
     */
    private LocalDateTime startTime;

    /**
     * 结束时间
     */
    private LocalDateTime endTime;

    /**
     * 申请人
     */
    private String applyPersonName;

    /**
     * 申请人电话
     */
    private String applyPersonLink;

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
