package com.zeroone.star.systemmanage.entity;

import com.baomidou.mybatisplus.annotation.TableName;
import lombok.Data;

import java.math.BigDecimal;
import java.time.LocalDateTime;

@Data
@TableName("building_room")
public class BuildingRoomDO {
    private String roomId;          // 房屋ID
    private String bId;             // 业务ID
    private String roomNum;         // 房屋编号
    private String unitId;          // 单元ID
    private String layer;           // 层数
    private Integer section;        // 室
    private String apartment;       // 户型
    private BigDecimal builtUpArea; // 建筑面积
    private BigDecimal feeCoefficient; // 算费系数
    private String userId;          // 用户ID
    private String remark;          // 备注
    private LocalDateTime createTime;   // 创建时间
    private String statusCd;        // 数据状态
    private String state;           // 房屋状态
    private String communityId;     // 小区ID
    private String roomType;        // 房屋类型
    private String roomSubType;     // 房屋类型 110 住宅房屋，119 办公室 120 宿舍
    private BigDecimal roomArea;    // 室内面积
    private BigDecimal roomRent;    // 租金
}
