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
@TableName("building_room")
public class BuildingRoom implements Serializable {

    private static final long serialVersionUID = 1L;

    /**
     * 房屋ID
     */
    @TableId(value = "room_id", type = IdType.ASSIGN_ID)
    private String roomId;

    /**
     * 业务ID
     */
    @TableField("b_id")
    private String bId;

    /**
     * 房屋编号
     */
    @TableField("room_num")
    private String roomNum;

    /**
     * 单元ID
     */
    @TableField("unit_id")
    private String unitId;

    /**
     * 层数
     */
    @TableField("layer")
    private String layer;

    /**
     * 室
     */
    @TableField("section")
    private Integer section;

    /**
     * 户型
     */
    @TableField("apartment")
    private String apartment;

    /**
     * 建筑面积
     */
    @TableField("built_up_area")
    private BigDecimal builtUpArea;

    /**
     * 算费系数
     */
    @TableField("fee_coefficient")
    private BigDecimal feeCoefficient;

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
     * 数据状态，详细参考c_status表，S 保存，0, 在用 1失效
     */
    @TableField("status_cd")
    private String statusCd;

    /**
     * 房屋状态，如房屋出售等，请查看state 表
     */
    @TableField("state")
    private String state;

    /**
     * 小区ID
     */
    @TableField("community_id")
    private String communityId;

    /**
     * 房屋类型
     */
    @TableField("room_type")
    private String roomType;

    /**
     * 房屋类型 110 住宅房屋，119 办公室 120 宿舍
     */
    @TableField("room_sub_type")
    private String roomSubType;

    /**
     * 室内面积
     */
    @TableField("room_area")
    private BigDecimal roomArea;

    /**
     * 租金
     */
    @TableField("room_rent")
    private BigDecimal roomRent;
}
