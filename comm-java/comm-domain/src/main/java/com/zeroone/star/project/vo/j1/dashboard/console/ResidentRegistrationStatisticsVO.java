package com.zeroone.star.project.vo.j1.dashboard.console;

import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.AllArgsConstructor;
import lombok.Builder;
import lombok.Data;
import lombok.NoArgsConstructor;

import java.io.Serializable;



@Data
@NoArgsConstructor
@AllArgsConstructor
@Builder
@ApiModel("住户注册统计视图对象")
public class ResidentRegistrationStatisticsVO{

    @ApiModelProperty(value = "未注册的住户数量", example = "0")
    private Integer unregisteredCount;

    @ApiModelProperty(value = "已注册的住户数量", example = "0")
    private Integer registeredCount;

    @ApiModelProperty(value = "未绑定房屋的住户数量", example = "0")
    private Integer unboundHouseCount;

    @ApiModelProperty(value = "已绑定房屋的住户数量", example = "0")
    private Integer boundHouseCount;
}
