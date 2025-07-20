package com.zeroone.star.parkmanage.entity;

import lombok.Data;

import java.util.Date;

/**
 * @author 岚图
 * #Description：用于车辆导出查询结果的DO对象
 * #Date: 2025/5/22
 */
@Data
public class VehicleDO {

    private String carId; // 车辆ID
    private String carNumber; // 车牌号
    private String carTypeName; // 车辆类型名称
    private String carBrand; // 车辆品牌
    private String carColor; // 车辆颜色
    private String psId; // 车位ID
    private String parkingSpaceNum; // 车位编号 (从车位表获取)
    private String areaNum; // 车位区域号
    private String paId; // 停车场ID
    private String paName; // 停车场名称
    private String ownerId; // 业主ID
    private String ownerName; // 业主姓名
    private String ownerTel; // 业主手机号
    private Date startTime; // 有效期开始时间
    private Date endTime; // 有效期结束时间
    private String communityId; // 社区ID
    private String remark; // 备注
    private String status; // 状态名称 (从字典表获取)
    private String memberVehicle; // 成员车辆数量 (从子查询获取，可能需要转换为其他类型)
    private String room; // 房屋号
    private String bId; // building_owner_room_rel ID或其他用途
    private String idCard; // 业主身份证号
    private String carType; // 车辆类型编码
    private String carTypeCd; // 车辆主副类型编码
    private String carTypeCdName; // 车辆主副类型名称
    private String state; // 车辆状态编码
    private String statusCd;/// 状态编码
    private String memberId; // 车辆所属成员ID
    private String leaseType; // 租赁类型编码
    private String leaseTypeName; // 租赁类型名称
    private String parkingType; // 车位类型编码
    private String parkingTypeName; // 车位类型名称
    private String userId;//  用户ID
    private String createTime;//创建时间

} 