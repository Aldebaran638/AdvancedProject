package com.zeroone.star.project.dto.j6.contractmanagement.contractmodification;

import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Getter;
import lombok.Setter;
import lombok.ToString;
import com.fasterxml.jackson.annotation.JsonProperty;


/**
 * <p>
 * 合同房间数据传输对象
 * </p>
 * @since 2025-5-19
 */
@Getter
@Setter
@ToString
@ApiModel("合同房间数据传输对象")
public class ContractRoomDTO {

    @ApiModelProperty(value = "房间ID", example = "752025042300391401")
    @JsonProperty("roomId")
    private String roomId;

    @ApiModelProperty(value = "房间名称", example = "7-0-11")
    @JsonProperty("roomName")
    private String roomName;

    @ApiModelProperty(value = "房间编号", example = "11")
    @JsonProperty("roomNum")
    private String roomNum;

    @ApiModelProperty(value = "合同ID", example = "812025052382310986")
    @JsonProperty("contractId")
    private String contractId;

    @ApiModelProperty(value = "小区ID", example = "2025041251140067")
    @JsonProperty("communityId")
    private String communityId;

    @ApiModelProperty(value = "单元ID", example = "742025042303981400")
    @JsonProperty("unitId")
    private String unitId;

    @ApiModelProperty(value = "单元编号", example = "0")
    @JsonProperty("unitNum")
    private String unitNum;

    @ApiModelProperty(value = "楼层ID", example = "732025042205851231")
    @JsonProperty("floorId")
    private String floorId;

    @ApiModelProperty(value = "楼层号", example = "7")
    @JsonProperty("floorNum")
    private String floorNum;

    @ApiModelProperty(value = "层（如地上、地下）", example = "1")
    @JsonProperty("layer")
    private String layer = "1";

    @ApiModelProperty(value = "板块/区域", example = "1")
    @JsonProperty("section")
    private String section = "1";

    @ApiModelProperty(value = "房号", example = "10101")
    @JsonProperty("apartment")
    private String apartment;

    @ApiModelProperty(value = "建筑面积", example = "2.00")
    @JsonProperty("builtUpArea")
    private String builtUpArea;

    @ApiModelProperty(value = "使用面积", example = "1.00")
    @JsonProperty("roomArea")
    private String roomArea;

    @ApiModelProperty(value = "单位面积租金", example = "1.00")
    @JsonProperty("roomRent")
    private String roomRent;

    @ApiModelProperty(value = "楼层总面积", example = "7200.00")
    @JsonProperty("floorArea")
    private String floorArea;

    @ApiModelProperty(value = "租金系数", example = "1.00")
    @JsonProperty("feeCoefficient")
    private String feeCoefficient = "1.00";

    @ApiModelProperty(value = "房间类型", example = "2020602")
    @JsonProperty("roomType")
    private String roomType;

    @ApiModelProperty(value = "房间子类型", example = "120")
    @JsonProperty("roomSubType")
    private String roomSubType;

    @ApiModelProperty(value = "房间子类型名称", example = "办公室")
    @JsonProperty("roomSubTypeName")
    private String roomSubTypeName = "办公室";

    @ApiModelProperty(value = "状态", example = "2002")
    @JsonProperty("state")
    private String state;

    @ApiModelProperty(value = "状态名称", example = "未销售")
    @JsonProperty("stateName")
    private String stateName = "未销售";

    @ApiModelProperty(value = "状态码（业务用）", example = "0")
    @JsonProperty("statusCd")
    private String statusCd;

    @ApiModelProperty(value = "店铺ID", example = "102025040775320034")
    @JsonProperty("storeId")
    private String storeId;

    @ApiModelProperty(value = "备注", example = "")
    @JsonProperty("remark")
    private String remark;

    @ApiModelProperty(value = "CR ID（可能用于扩展）", example = "282025052835970006")
    @JsonProperty("crId")
    private String crId;
}
