package com.zeroone.star.project.vo.j5.community.mycommunity;

import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;

@Data
@ApiModel("所有我的小区数据展示模型")
public class AllMyCommunityVO {
    @ApiModelProperty(value = "小区编码",example = "2023052267100146")
    private String communityId;
    @ApiModelProperty(value = "小区名称",example = "HC演示小区3")
    private String name;
    @ApiModelProperty(value = "小区地址",example = "青海省西宁市城中区无")
    private String address;
}
