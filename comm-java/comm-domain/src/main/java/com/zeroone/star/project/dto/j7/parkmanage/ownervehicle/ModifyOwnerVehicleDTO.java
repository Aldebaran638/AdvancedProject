package com.zeroone.star.project.dto.j7.parkmanage.ownervehicle;

import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;

@ApiModel("修改成员车辆模型")
@Data
public class ModifyOwnerVehicleDTO {
    @ApiModelProperty(value = "车牌号",example = "京A411111")
    private String carNum;
    @ApiModelProperty(value = "车辆品牌",example = "宝马")
    private String carBrand;
    @ApiModelProperty(value = "车辆类型",example = "家用小汽车",required = true)
    private String carType;
    @ApiModelProperty(value = "车辆颜色",example = "白色")
    private String carColor;
    @ApiModelProperty(value = "备注", example = "长期停放")
    private String remark;
    @ApiModelProperty(value = "车辆id",example = "802023061661080002",required = true)
    private String id;
}
