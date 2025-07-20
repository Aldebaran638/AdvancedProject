package com.zeroone.star.project.j8.patrolmgt.route.dto;

import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.AllArgsConstructor;
import lombok.Data;
import lombok.NoArgsConstructor;

import java.util.Date;

@ApiModel("巡检路线数据传输模型")
@AllArgsConstructor
@NoArgsConstructor
@Data
/**
 * 巡检路线数据传输模型
 *
 * @author: zhangyvsen
 *
 */
public class zhangyvsen_RouteDTO {


    // 线路ID
    @ApiModelProperty(value = "路线id", example = "502025051446110007")
    private String inspectionRouteId;

    // 路线名称
    @ApiModelProperty(value = "路线名称", example = "沈工大路线")
    private String routeName;

    // 巡检顺序
    @ApiModelProperty(value = "路线顺序", example = "1")
    private String seq;

    // 创建时间
    @ApiModelProperty(value = "创建时间", example = "2025-05-19 15:40:44")
    private Date createTime;

    // 备注
    @ApiModelProperty(value = "备注", example = "无")
    private String remark;


}
