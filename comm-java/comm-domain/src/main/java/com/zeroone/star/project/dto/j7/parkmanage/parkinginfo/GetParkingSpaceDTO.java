package com.zeroone.star.project.dto.j7.parkmanage.parkinginfo;

import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;

import java.math.BigDecimal;

@ApiModel("车位查询DTO")
@Data
public class GetParkingSpaceDTO extends ParkingSpaceDTO{
    @ApiModelProperty(value = "停车场编号", example = "PA001")
    private String paNum;

    @ApiModelProperty(value = "车位状态", example = "F")
    private String state;

    @ApiModelProperty(value = "创建时间", example = "2025-05-20 15:37:05")
    private String createTime;

}
