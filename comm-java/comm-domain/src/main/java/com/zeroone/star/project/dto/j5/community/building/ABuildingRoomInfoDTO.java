package com.zeroone.star.project.dto.j5.community.building;


import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Getter;
import lombok.Setter;
import lombok.ToString;

import javax.validation.constraints.NotBlank;
import javax.validation.constraints.NotNull;
import java.math.BigDecimal;



@Getter
@Setter
@ToString
@ApiModel("BuildingRoomInfo数据传输对象")
public class ABuildingRoomInfoDTO {

    @ApiModelProperty(value = "业主ID", example = "772025051466271142")
    String ownerId;

    @ApiModelProperty(value = "业主名字", example = "张三")
    @NotBlank(message = "业主名字不能为空")
    String ownerName;

    @ApiModelProperty(value = "身份证号", example = "15211111111111111")
    String idCard;

    @ApiModelProperty(value = "联系人手机号", example = "17709711234")
    String link;

    @ApiModelProperty(value = "房间ID", example = "752025051440581138")
    @NotBlank(message = "房间ID不能为空")
    String roomId;

    @ApiModelProperty(value = "房间类型", example = "1010301")
    @NotBlank(message = "房间类型不能为空")
    String roomType;

    @ApiModelProperty(value = "房间编号", example = "101")
    @NotBlank(message = "房间编号不能为空")
    String roomNum;

    @ApiModelProperty(value = "房间面积", example = "78.00")
    @NotNull(message = "房间面积不能为空")
    BigDecimal roomArea;

    @ApiModelProperty(value = "房间租金", example = "0.00")
    @NotNull(message = "房间租金不能为空")
    BigDecimal roomRent;

    @ApiModelProperty(value = "房间子类型 110 住宅房屋，119 办公室 120 宿舍", example = "110")
    @NotBlank(message = "房间子类型不能为空")
    String roomSubType;

    @ApiModelProperty(value = "楼层", example = "1")
    @NotBlank(message = "楼层不能为空")
    String layer;

    @ApiModelProperty(value = "建筑面积", example = "88.00")
    @NotNull(message = "建筑面积不能为空")
    BigDecimal builtUpArea;

    @ApiModelProperty(value = "费用系数", example = "1.00")
    @NotNull(message = "费用系数不能为空")
    BigDecimal feeCoefficient;

    @ApiModelProperty(value = "公寓名称", example = "10102")
    @NotBlank(message = "公寓名称不能为空")
    String apartment;

    @ApiModelProperty(value = "创建时间", example = "2025-05-14 15:19:52")
    @NotBlank(message = "创建时间不能为空")
    String createTime;

    @ApiModelProperty(value = "数据状态", example = "0")
    @NotBlank(message = "数据状态不能为空")
    String statusCd;

    @ApiModelProperty(value = "状态", example = "2002")
    @NotBlank(message = "状态不能为空")
    String state;

    @ApiModelProperty(value = "分区编号", example = "1")
    @NotNull(message = "分区编号不能为空")
    Integer section;

    @ApiModelProperty(value = "社区ID", example = "2025041251140067")
    @NotBlank(message = "社区ID不能为空")
    String communityId;

    @ApiModelProperty(value = "单元id", example = "742025051425621137")
    @NotBlank(message = "单元id不能为空")
    String unitId;


    @ApiModelProperty(value = "单元编号", example = "1")
    @NotBlank(message = "单元编号不能为空")
    String unitNum;

    @ApiModelProperty(value = "楼id", example = "732023120568080332")
    @NotBlank(message = "楼id不能为空")
    String floorId;

    @ApiModelProperty(value = "楼编号", example = "1")
    @NotBlank(message = "楼编号不能为空")
    String floorNum;

    @ApiModelProperty(value = "欠费", example = "10800.00")
    BigDecimal oweAmount;

    @ApiModelProperty(value = "状态名称", example = "未出售")
    @NotBlank(message = "状态名称不能为空")
    String stateName;

    //新增分页字段
    @ApiModelProperty(value = "页码", example = "1")
    Integer page;

    @ApiModelProperty(value = "每页条数", example = "10")
    Integer row;

    @ApiModelProperty(value = "总页数", example = "1")
    Integer total;

    @ApiModelProperty(value = "总记录数", example = "1")
    Integer records;
}
