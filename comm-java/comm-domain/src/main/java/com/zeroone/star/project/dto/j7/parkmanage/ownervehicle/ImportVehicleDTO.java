package com.zeroone.star.project.dto.j7.parkmanage.ownervehicle;

import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;


/**
 * @author 岚图
 * #Description：导入车辆模型
 * #Date：2025/5/20 15:05
 */
@ApiModel("导入车辆模型")
@Data
public class ImportVehicleDTO {


    @ApiModelProperty(value = "车牌号", example = "AW2222")
    private String carNumber;

    @ApiModelProperty(value = "业主名称", example = "张三")
    private String ownerName;

    @ApiModelProperty(value = "手机号", example = "19168091922")
    private String phoneNumber;

    @ApiModelProperty(value = "车辆品牌", example = "保时捷")
    private String carBrand;

    @ApiModelProperty(value = "车辆类型", example = "家用小汽车")
    private String carType;

    @ApiModelProperty(value = "颜色", example = "黄黑色")
    private String color;

    @ApiModelProperty(value = "停车场", example = "1")
    private String parkingLot;

    @ApiModelProperty(value = "车位", example = "1-2")
    private String parkingSpace;

    @ApiModelProperty(value = "起租时间", example = "2025-05-16")
    private String startTime;

    @ApiModelProperty(value = "截止时间", example = "2050-01-01")
    private String endTime;

    @ApiModelProperty(value = "停车场类型", example = "1001")
    private String parkingLotType;

    @ApiModelProperty(value = "车位状态", example = "S")
    private String parkingSpaceStatus;

    @ApiModelProperty(value = "车牌类型", example = "主车辆")
    private String carTypeName;

    @ApiModelProperty(value = "车辆主副类型编码", example = "1001")
    private String carTypeCd;

    @ApiModelProperty(value = "车辆主副类型名称", example = "主车辆")
    private String carTypeCdName;

    @ApiModelProperty(value = "成员车辆", example = "0")
    private String memberVehicle;

    @ApiModelProperty(value = "车位ID", example = "792025052831400031")
    private String psId;

    @ApiModelProperty(value = "停车场ID", example = "102025052889140002")
    private String paId;

    @ApiModelProperty(value = "业主ID", example = "772025051567660099")
    private String ownerId;

    @ApiModelProperty(value = "成员ID", example = "802025052806150067")
    private String memberId;

    @ApiModelProperty(value = "租赁类型", example = "S")
    private String leaseType;

    @ApiModelProperty(value = "租赁类型名称", example = "出售车")
    private String leaseTypeName;

    @ApiModelProperty(value = "车位类型", example = "1")
    private String parkingType;

    @ApiModelProperty(value = "车辆状态", example = "1001")
    private String state;

    @ApiModelProperty(value = "车辆状态名称", example = "正常")
    private String stateName;

    @ApiModelProperty(value = "社区ID", example = "2025051572820031")
    private String communityId;

    @ApiModelProperty(value = "身份证号", example = "4141411111445656")
    private String idCard;

    @ApiModelProperty(value = "备注", example = "备注信息")
    private String remark;

    @ApiModelProperty(value = "用户ID", example = "-1")
    private String userId;

    @ApiModelProperty(value = "业务ID", example = "202025052832650069")
    private String bId;
} 