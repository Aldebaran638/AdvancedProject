package com.zeroone.star.project.vo.j5.community.mycommunity;

import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;

import java.io.Serializable;
import java.time.LocalDateTime;

@Data
@ApiModel("单个我的小区数据展示模型")
public class MyCommunityVO implements Serializable {
    @ApiModelProperty(value = "小区名称",example = "HC演示小区3")
    private String name;
    @ApiModelProperty(value = "小区编码",example = "2023052267100146")
    private String communityId;
    @ApiModelProperty(value = "小区所在的省份",example = "青海省")
    private String communityProvince;
    @ApiModelProperty(value = "小区所在的市",example = "西宁市")
    private String communityCity;
    @ApiModelProperty(value = "小区所在的区/县",example = "城中区")
    private String communityCounty;
    @ApiModelProperty(value = "小区面积",example = "0.00")
    private Double communityArea;
    @ApiModelProperty(value = "客服电话",example = "18909711443")
    private String tel;
    @ApiModelProperty(value = "开始时间",example = "2023-05-22T10:14:33")
    private LocalDateTime startTime;
    @ApiModelProperty(value = "结束时间",example = "2024-05-22T10:14:33")
    private LocalDateTime endTime;
    @ApiModelProperty(value = "状态 1000为待审核 1100为审核成功 1200为审核拒绝",example = "1100")
    private String state;

     @ApiModelProperty(value = "小区地标",example = "123")
     private  String nearbyLandmarks;
     @ApiModelProperty(value = "城市编码",example = "110102")
     private String cityCode;
     @ApiModelProperty(value = "小区地址",example = "青海省西宁市城中区")
     private String address;
     @ApiModelProperty(value = "地区X坐标",example = "101.33")
     private String mapX;
     @ApiModelProperty(value = "地区Y坐标",example = "101.33")
     private String mapY;
     @ApiModelProperty(value = "客服二维码",example = "https://www.baidu.com")
     private String qrCode;
}
