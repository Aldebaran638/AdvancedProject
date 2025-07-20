package com.zeroone.star.project.vo.j7.parkmanage.ownervehicle;

import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;

import java.io.Serializable;
import java.time.LocalDateTime;

@ApiModel("获取车辆列表视图模型")
@Data
public class OwnerCarInfoVO implements Serializable {

    private static final long serialVersionUID = 1L;

    @ApiModelProperty(value = "车牌号", example = "渝A12112")
    private String carNum;

    @ApiModelProperty(value = "成员车辆统计", example = "2")
    private String memberCarNum;

    @ApiModelProperty(value = "单元ID", example = "1")
    private String unitId;

    @ApiModelProperty(value = "层数", example = "1")
    private String layer;

    @ApiModelProperty(value = "房屋编号", example = "1001")
    private String roomNum;

    @ApiModelProperty(value = "车牌类型 H 月租车，S 出售车，I 内部车，NM 免费车", example = "H")
    private String leaseType;

    @ApiModelProperty(value = "9901 家用小汽车，9902 客车，9903 货车，9904 电动车，9905 三轮车，9906 信用期车辆", example = "9901")
    private String carType;

    @ApiModelProperty(value = "车颜色", example = "珍珠白")
    private String carColor;

    @ApiModelProperty(value = "业主名称", example = "一刀")
    private String name;

    @ApiModelProperty(value = "联系人手机号", example = "15044108708")
    private String link;

    @ApiModelProperty(value = "停车场编号", example = "01star")
    private String areaNum;

    @ApiModelProperty(value = "车位编号", example = "A01")
    private String spaceNum;

    @ApiModelProperty(value = "起租时间", example = "2025-05-20 01:01:01")
    private LocalDateTime startTime;

    @ApiModelProperty(value = "结组时间", example = "2050-05-20 00:00:00")
    private LocalDateTime endTime;

    @ApiModelProperty(value = "状态 1001 正常状态，2002 车位释放欠费状态，3003 车位释放", example = "1001")
    private String state;

    @ApiModelProperty(value = "备注", example = "测试")
    private String remark;

    @ApiModelProperty(value = "成员id", example = "802024022527393986")
    private String memberId;

    @ApiModelProperty(value = "社区id", example = "2023052267100146",required = true)
    private String communityId;

    @ApiModelProperty(value = "车辆id", example = "802024022527393986")
    private String CarId;

    @ApiModelProperty(value = "业主id", example = "772024022641420195")
    private String OwnerId;
}