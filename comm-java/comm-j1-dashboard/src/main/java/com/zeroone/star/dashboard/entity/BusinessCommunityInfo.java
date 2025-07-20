package com.zeroone.star.dashboard.entity;

import com.baomidou.mybatisplus.annotation.TableField;
import io.swagger.annotations.ApiModelProperty;
import lombok.AllArgsConstructor;
import lombok.Data;
import lombok.NoArgsConstructor;


@Data
@NoArgsConstructor
@AllArgsConstructor
public class BusinessCommunityInfo {

    /**
     * 楼宇数量
     */
    @ApiModelProperty(value = "楼宇数量", example = "0")
    @TableField("building_count")
    private Integer buildingCount;

    /**
     * 房屋数量
     */
    @ApiModelProperty(value = "房屋数量", example = "0")
    @TableField("house_count")
    private Integer houseCount;

    /**
     * 商铺数量
     */
    @ApiModelProperty(value = "商铺数量", example = "0")
    @TableField("shop_count")
    private Integer shopCount;

    /**
     * 车位数量
     */
    @ApiModelProperty(value = "车位数量", example = "0")
    @TableField("parking_count")
    private Integer parkingCount;

    /**
     * 登记住户数量
     */
    @ApiModelProperty(value = "登记住户数量", example = "0")
    @TableField("resident_count")
    private Integer residentCount;

    /**
     * 车辆数量
     */
    @ApiModelProperty(value = "车辆数量", example = "0")
    @TableField("vehicle_count")
    private Integer vehicleCount;
}
