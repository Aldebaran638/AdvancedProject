package com.zeroone.star.project.dto.j5.community.publicity;

import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;

/**
 * ClassName: PublicityDetailsDTO
 * Package: com.zeroone.star.project.query.j5.community.publicity
 * Description:
 *
 * @Author wuguanfengyue
 * @Create 2025/5/20 21:16
 * @Version 1.0
 */
@ApiModel("公示详情模型")
@Data
public class PublicityDetailDTO {
    @ApiModelProperty(value="公示ID", example = "102023040772260002",required = true)
    private  String pubId;

    @ApiModelProperty(value="公示标题", example = "财务公开1",required = true)
    private  String title;

    @ApiModelProperty(value="公示类型 公共收益=100 规章制度=2000 政策相关=3000", example = "1000",required = true)
    private  Integer pubType;

    @ApiModelProperty(value="头部照片",
            example = "https://java110.oss-cn-beijing.aliyuncs.com/hc/img/20230407/cce91692-430f-444c-8e8b-365f231ea090.jpg",
            required = true)
    private  String headerImg;

    @ApiModelProperty(value="小区id", example = "2023052267100146",required = true)
    private  String communityId;

    @ApiModelProperty(value="活动内容", example = "<p>大刀的</p>",required = true)
    private  String context;

    @ApiModelProperty(value="发布人", example = "HC演示物业2",required = true)
    private  String createUserName;

    @ApiModelProperty(value="公示时间", example = "2024-02-20 17:18:51",required = true)
    private  String createTime;






}
