package com.zeroone.star.project.vo.j4.datamanager;

import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;

/**
 * 展示加入小区列表
 * @author 玺朽
 */
@ApiModel("加入小区列表")
@Data
public class JoinCommunityVO {
    @ApiModelProperty(value = "小区id", example = "2023052267100146")
    private String communityId;
    @ApiModelProperty(value = "小区名称", example = "HC演示小区3")
    private String communityName;
    @ApiModelProperty(value = "小区地址", example = "青海省西宁市城中区无")
    private String communityAddress;
    @ApiModelProperty(value = "城市编码", example = "630103")
    private String cityCode;
    @ApiModelProperty(value = "状态", example = "1100")
    private String state;

}
