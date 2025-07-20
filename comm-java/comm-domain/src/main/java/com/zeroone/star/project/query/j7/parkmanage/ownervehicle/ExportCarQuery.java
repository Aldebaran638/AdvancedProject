package com.zeroone.star.project.query.j7.parkmanage.ownervehicle;

import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;

@Data
@ApiModel("导出车辆查询模型")
public class ExportCarQuery {
    @ApiModelProperty(value = "车牌号", example = "渝A12112")
    private String carNum;

    @ApiModelProperty(value = "车位编号", example = "A1")
    private String num;

    @ApiModelProperty(value = "车位状态", example = "1")
    private Integer valid;

    @ApiModelProperty(value = "业主名称", example = "一刀")
    private String name;

    @ApiModelProperty(value = "联系方式", example = "15044108708")
    private String link;

    @ApiModelProperty(value = "成员车牌号", example = "青A88567")
    private String memberCarNum;

    @ApiModelProperty(value = "租赁类型", example = "H")
    private String leaseType;

    @ApiModelProperty(value = "主车辆", example = "1001", required = true)
    private String carTypeCd;

    @ApiModelProperty(value = "社区id", example = "2024022643710121", required = true)
    private String communityId;
} 