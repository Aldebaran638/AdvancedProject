package com.zeroone.star.project.query.j7.parkmanage.ownervehicle;

import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;


/**
 * @author 岚图
 * @date 2025/5/20 15:30
 */
@ApiModel("车辆基础信息查询对象")
@Data
public class OwnerVehicleQuery {

    @ApiModelProperty(value = "车辆ID", example = "802025052521740010", required = true)
    private String carId;

} 