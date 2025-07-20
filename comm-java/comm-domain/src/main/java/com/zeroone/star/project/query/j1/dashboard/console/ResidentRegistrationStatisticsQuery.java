package com.zeroone.star.project.query.j1.dashboard.console;

import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.AllArgsConstructor;
import lombok.Data;
import lombok.NoArgsConstructor;


@Data
@NoArgsConstructor
@AllArgsConstructor
@ApiModel("住户注册统计查询对象")
public class ResidentRegistrationStatisticsQuery{

    @ApiModelProperty(value = "未注册的住户数量", example = "0")
    private Integer unregisteredCount;

    @ApiModelProperty(value = "已注册的住户数量", example = "0")
    private Integer registeredCount;

    @ApiModelProperty(value = "未绑定房屋的住户数量", example = "0")
    private Integer unboundHouseCount;

    @ApiModelProperty(value = "已绑定房屋的住户数量", example = "0")
    private Integer boundHouseCount;
}
