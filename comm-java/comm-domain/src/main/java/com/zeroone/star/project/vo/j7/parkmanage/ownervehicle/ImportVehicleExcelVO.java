package com.zeroone.star.project.vo.j7.parkmanage.ownervehicle;

import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;

@ApiModel("车辆导入Excel模板VO")
@Data
public class ImportVehicleExcelVO {
    @ApiModelProperty(value = "车牌号", example = "AW2222")
    private String carNumber;

    @ApiModelProperty(value = "业主名称", example = "张三")
    private String ownerName;

    @ApiModelProperty(value = "手机号", example = "19168091922")
    private String phoneNumber;

    @ApiModelProperty(value = "车辆品牌", example = "保时捷")
    private String carBrand;

    @ApiModelProperty(value = "车辆类型", example = "9901")
    private String carType;

    @ApiModelProperty(value = "颜色", example = "黄黑色")
    private String color;

    @ApiModelProperty(value = "停车场", example = "1")
    private String parkingLot;

    @ApiModelProperty(value = "车位", example = "3")
    private String parkingSpace;

    @ApiModelProperty(value = "起租时间", example = "2025/5/15")
    private String startTime;

    @ApiModelProperty(value = "截止时间", example = "2025/5/16")
    private String endTime;

    @ApiModelProperty(value = "停车场类型", example = "1001")
    private String parkingLotType;

    @ApiModelProperty(value = "车位状态", example = "S")
    private String status;
} 