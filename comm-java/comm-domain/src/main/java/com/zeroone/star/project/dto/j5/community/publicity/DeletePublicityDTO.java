package com.zeroone.star.project.dto.j5.community.publicity;

import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;

import javax.validation.constraints.NotBlank;

/**
 * @description: 删除公示dto
 * @author: yu
 * @data 2025年05月20日 09:21
 */

@ApiModel(description = "删除公示DTO")
@Data
public class DeletePublicityDTO {

    @NotBlank
    @ApiModelProperty(value = "公示ID", required = true, example = "102024022092656182")
    private String pubId;

    @NotBlank
    @ApiModelProperty(value = "小区ID", required = true, example = "2023052267100146")
    private String communityId;

}

