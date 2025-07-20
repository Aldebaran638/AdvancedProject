package com.zeroone.star.project.dto.j1.dashboard.data;

import com.fasterxml.jackson.annotation.JsonFormat;
import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.AllArgsConstructor;
import lombok.Data;
import lombok.NoArgsConstructor;

import java.io.Serializable;
import java.util.Date;



@Data
@ApiModel(value = "住户注册统计数据传输对象" , description = "住户注册统计数据传输对象")
@AllArgsConstructor
@NoArgsConstructor
public class ResidentRegistrationStatisticDTO{

    @ApiModelProperty(value = "未注册的住户数量", example = "0")
    private Integer unregisteredCount;

    @ApiModelProperty(value = "已注册的住户数量", example = "0")
    private Integer registeredCount;

    @ApiModelProperty(value = "未绑定房屋的住户数量", example = "0")
    private Integer unboundHouseCount;

    @ApiModelProperty(value = "已绑定房屋的住户数量", example = "0")
    private Integer boundHouseCount;
}