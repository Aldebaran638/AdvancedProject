package com.zeroone.star.project.dto.j7.parkmanage.ownervehicle;

import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;
import java.io.Serializable;

@ApiModel("车辆信息模型")
@Data
public class OwnerCarDTO implements Serializable {
    private static final long serialVersionUID = 1L;

    @ApiModelProperty(value = "车牌号", example = "AW2222")
    private String carNum;

    @ApiModelProperty(value = "车辆品牌", example = "保时捷")
    private String carBrand;

    @ApiModelProperty(value = "车辆类型", example = "家用小汽车")
    private String carType;

    @ApiModelProperty(value = "车辆类型名称", example = "出售车")
    private String carTypeCdName;

    @ApiModelProperty(value = "车辆颜色", example = "黄黑色")
    private String carColor;

    @ApiModelProperty(value = "起租时间", example = "2025-05-16 00:00:00")
    private String startTime;

    @ApiModelProperty(value = "结束时间", example = "2050-01-01 00:00:00")
    private String endTime;

    @ApiModelProperty(value = "备注", example = "www1241")
    private String remark;

    @ApiModelProperty(value = "停车场ID", example = "1")
    private Integer psId;

    @ApiModelProperty(value = "车位编号", example = "2")
    private String parkingSpace;

    @ApiModelProperty(value = "车辆状态", example = "车位释放")
    private String state;

    @ApiModelProperty(value = "关联房屋", example = "1号楼-101")
    private String roomName;

    @ApiModelProperty(value = "业主姓名", example = "张三")
    private String ownerName;

    @ApiModelProperty(value = "业主手机号", example = "19168091922")
    private String ownerPhone;

} 