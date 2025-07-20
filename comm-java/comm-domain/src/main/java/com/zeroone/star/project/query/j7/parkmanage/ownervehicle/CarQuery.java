package com.zeroone.star.project.query.j7.parkmanage.ownervehicle;

import com.zeroone.star.project.query.PageQuery;
import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;

@Data
@ApiModel("获取车辆列表查询模型")
public class CarQuery extends PageQuery {
    @ApiModelProperty(value = "车牌号", example = "渝A12112")
    private String carNum;

    @ApiModelProperty(value = "车位编号", example = "A1")
    private String num;

    @ApiModelProperty(value = "车位状态 1 正常状态，2 无车位，3 到期", example = "1")
    private Integer valid;

    @ApiModelProperty(value = "业主名称", example = "一刀")
    private String name;

    @ApiModelProperty(value = "联系方式", example = "15044108708")
    private String link;

    @ApiModelProperty(value = "成员车牌号", example = "青A88567")
    private String memberCarNum;

    @ApiModelProperty(value = "车牌类型 H 月租车，S 出售车，I 内部车，NM 免费车", example = "H")
    private String leaseType;

    @ApiModelProperty(value = "社区id", example = "2024022643710121", required = true)
    private String communityId;

}
