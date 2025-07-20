package com.zeroone.star.project.dto.j5.community.publicity;
import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;

import javax.validation.constraints.NotBlank;

/**
 * @description: 公示增删改公共字段
 * @author: yu
 * @data 2025年05月20日 09:15
 */


@ApiModel(description = "公示基础字段")
@Data
public class PublicityBaseDTO {
    @NotBlank
    @ApiModelProperty(value = "小区ID", required = true, example = "2023052267100146")
    private String communityId;

    @NotBlank
    @ApiModelProperty(value = "公示标题", required = true, example = "这是一个 公示")
    private String title;

    @NotBlank
    @ApiModelProperty(value = "公示内容", required = true, example = "<p>大刀的</p>")
    private String context;

    @NotBlank
    @ApiModelProperty(value = "封面图片URL", required = true, example = "https://xxx.jpg")
    private String headerImg;

    @NotBlank
    @ApiModelProperty(value = "公示类型编码", required = true, example = "1000")
    private String pubType;

}

