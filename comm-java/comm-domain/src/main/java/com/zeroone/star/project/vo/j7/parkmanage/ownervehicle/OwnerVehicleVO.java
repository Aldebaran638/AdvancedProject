package com.zeroone.star.project.vo.j7.parkmanage.ownervehicle;

import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;
import java.io.Serializable;

/**
 * @author 岚图
 * #Description：车辆基础信息模型
 * #Date: 2025/5/19 17:30
 */
@ApiModel("车辆基础信息视图对象")
@Data
public class OwnerVehicleVO implements Serializable {

    private static final long serialVersionUID = 1L;

    @ApiModelProperty(value = "车牌号", example = "AW2222")
    private String carNumber;

    @ApiModelProperty(value = "车辆品牌", example = "保时捷")
    private String carBrand;

    @ApiModelProperty(value = "车牌类型（出售车/月租车等）", example = "出售车")
    private String leaseTypeName;

    @ApiModelProperty(value = "颜色", example = "黄黑色")
    private String carColor;

    @ApiModelProperty(value = "起租时间", example = "2025-05-16 00:00:00")
    private String startTime;

    @ApiModelProperty(value = "结租时间", example = "2050-01-01 00:00:00")
    private String endTime;

    @ApiModelProperty(value = "备注", example = "www1241")
    private String remark;

    @ApiModelProperty(value = "车位编号", example = "2")
    private String parkingSpaceNum;

    @ApiModelProperty(value = "车辆状态", example = "车位释放")
    private String status;

    @ApiModelProperty(value = "关联房屋", example = "1号楼-101")
    private String room;

    @ApiModelProperty(value = "车辆类型", example = "家用小汽车")
    private String carTypeName;

    @ApiModelProperty(value = "停车场名称", example = "东区停车场")
    private String paName;

} 