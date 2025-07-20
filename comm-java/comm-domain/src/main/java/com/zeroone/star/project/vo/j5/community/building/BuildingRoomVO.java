package com.zeroone.star.project.vo.j5.community.building;

import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Getter;
import lombok.Setter;
import lombok.ToString;

import javax.validation.constraints.NotNull;
import java.math.BigDecimal;
@Getter
@Setter
@ToString
@ApiModel("BuildingRoomVO数据传输对象")
public class BuildingRoomVO {

//    @ApiModelProperty(value = "小区ID", example = "2023052267100146")
//    private String communityId;
//
//    @ApiModelProperty(value = "楼层ID", example = "732024022724560551")
//    private String floorId;
//
//    @ApiModelProperty(value = "楼层编号", example = "001")
//    private String floorNum;

    @ApiModelProperty(value = "层数", example = "1")
    private String layer;

    @ApiModelProperty(value = "欠费", example = "10800.00")
    BigDecimal oweAmount;

    @ApiModelProperty(value = "房间ID", example = "752024022767530558")
    private String roomId;

    @ApiModelProperty(value = "房间编号", example = "001")
    private String roomNum;


    @ApiModelProperty(value = "房子状态编码", example = "2001")
    private String state;

    @ApiModelProperty(value = "房子状态名称", example = "已入住")
    private String stateName;

//    @ApiModelProperty(value = "单元ID", example = "742024022745010554")
//    private String unitId;
//
//    @ApiModelProperty(value = "单元编号", example = "001")
//    private String unitNum;

    //业主字段
    @ApiModelProperty(value = "业主ID", example = "772025051466271142")
    String ownerId;

    @ApiModelProperty(value = "业主名字", example = "张三")
    String ownerName;

}