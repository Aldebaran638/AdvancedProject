package com.zeroone.star.project.vo.j7.parkmanage.ownervehicle;

import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;
import java.io.Serializable;

/**
 * @author 岚图
 * #Description：车辆导出视图对象
 * #Date: 2025/5/19 17:30
 */
@ApiModel("车辆导出视图对象")
@Data
public class OwnerVehicleExportVO implements Serializable {

    private static final long serialVersionUID = 1L;

    @ApiModelProperty(value = "车牌号", example = "AW2222")
    private String carNumber;

    @ApiModelProperty(value = "成员车辆", example = "0")
    private String memberVehicle;

    @ApiModelProperty(value = "房屋号", example = "1号楼-101")
    private String room;

    @ApiModelProperty(value = "车辆品牌", example = "保时捷")
    private String carBrand;

    @ApiModelProperty(value = "车辆类型", example = "家用小汽车")
    private String carType;

    @ApiModelProperty(value = "颜色", example = "黑色")
    private String color;

    @ApiModelProperty(value = "业主", example = "张三")
    private String ownerName;

    @ApiModelProperty(value = "车位", example = "A-101")
    private String parkingSpace;

    @ApiModelProperty(value = "有效期", example = "2025-05-16 00:00:00 - 2050-01-01 00:00:00")
    private String validityPeriod;

    @ApiModelProperty(value = "状态", example = "正常")
    private String status;

    @ApiModelProperty(value = "备注", example = "www1241")
    private String remark;
} 