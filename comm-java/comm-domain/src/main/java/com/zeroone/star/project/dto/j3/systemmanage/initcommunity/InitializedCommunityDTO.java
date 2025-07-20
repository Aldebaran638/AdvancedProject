package com.zeroone.star.project.dto.j3.systemmanage.initcommunity;

import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;

/**
 * 初始化小区数据传输模型
 */
@ApiModel(value = "初始化小区数据传输模型")
@Data
public class InitializedCommunityDTO {
    public static final String AWAITING_REVIEW = "待审核";
    public static final String REVIEW_COMPLETED = "审核完成";
    public static final String REVIEW_REJECTED = "审核拒绝";

    @ApiModelProperty(value = "小区id", example = "2024021911282483",required = true)
    private String communityId;

    @ApiModelProperty(value = "小区名称", example = "万科森林公园",required = true)
    private String name;

    @ApiModelProperty(value = "附近地标", example = "森林公园",required = true)
    private String nearbyLandmarks;

    @ApiModelProperty(value = "城市编码", example = "340103",required = true)
    private String cityCode;

    @ApiModelProperty(value = "状态（说明：'业务状态 1000为待审核 1100审核完成 1200审核拒绝'）", example = "1100-审核完成",required = true)
    private String state;

    @ApiModelProperty(value = "状态对应中文",example = "审核完成")
    private String stateText;
}


