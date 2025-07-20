package com.zeroone.star.project.vo.j5.community.parking;

import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;

import java.math.BigDecimal;

@Data
@ApiModel("车位结构图显示对象")
public class ParkingVO {

    @ApiModelProperty(value = "停车场编码", example = "1")
    private String areaNum;

    @ApiModelProperty(value = "车牌号", example = "4561")
    private String carNum;

    @ApiModelProperty(value = "楼编号", example = "1")
    private String floorNum;



   /* @ApiModelProperty(value = "身份证号码", example = "")
    private String idCard;*/

    /*@ApiModelProperty(value = "联系人手机号", example = "17709711234")
    private String link;*/

    /*@ApiModelProperty(value = "业主成员id", example = "112024032207740008")
    private String memberId;*/

    @ApiModelProperty(value = "车位编号", example = "A10")
    private String num;

    /*@ApiModelProperty(value = "车位编号", example = "")
    private String records;*/

    @ApiModelProperty(value = "欠费金额", example = "0.00")
    private BigDecimal oweAmount;

    /*@ApiModelProperty(value = "业主id", example = "772023120586090338")
    private String ownerId;*/

    @ApiModelProperty(value = "用户名字", example = "吴学文")
    private String ownerName;

    @ApiModelProperty(value = "房屋编号", example = "1001")
    private String roomNum;

    /*@ApiModelProperty(value = "房屋状态", example = "2001")
    private String state;*/

   /* @ApiModelProperty(value = "状态数据", example = "0")
    private String statusCd;*/

    /*@ApiModelProperty(value = "", example = "0")
    private String total;*/

    @ApiModelProperty(value = "单元id", example = "742023120517690335")
    private String unitId;

    @ApiModelProperty(value = "单元编号", example = "1")
    private String unitNum;

    /*@ApiModelProperty(value = "", example = "false")
    private String withOwner;*/

}
