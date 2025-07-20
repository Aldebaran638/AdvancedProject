package com.zeroone.star.project.dto.j1.dashboard.data;

import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.AllArgsConstructor;
import lombok.Builder;
import lombok.Data;
import lombok.NoArgsConstructor;

@Data
@AllArgsConstructor
@NoArgsConstructor
@Builder
@ApiModel(value = "小区信息传输对象" , description = "小区信息数据")
public class BusinessCommunityDTO {


    @ApiModelProperty(value = "楼宇数量", example = "0")
    private Integer buildingCount;   // 楼宇数量

    @ApiModelProperty(value = "房屋数量", example = "0")
    private Integer houseCount;      // 房屋数量

    @ApiModelProperty(value = "商铺数量", example = "0")
    private Integer shopCount;       // 商铺数量

    @ApiModelProperty(value = "车位数量", example = "0")
    private Integer parkingCount;    // 车位数量

    @ApiModelProperty(value = "登记住户数量", example = "0")
    private Integer residentCount;   // 登记住户数量

    @ApiModelProperty(value = "车辆数量", example = "0")
    private Integer vehicleCount;    // 车辆数量
}