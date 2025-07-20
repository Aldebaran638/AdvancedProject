package com.zeroone.star.project.dto.j5.community.publicity;
import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;

import javax.validation.constraints.NotBlank;

/**
 * @description: 修改公示dto
 * @author: yu
 * @data 2025年05月20日 09:20
 */


@ApiModel(description = "修改公示DTO")
@Data
public class UpdatePublicityDTO extends PublicityBaseDTO {

    @NotBlank
    @ApiModelProperty(value = "公示ID", required = true, example = "102024022092656182")
    private String pubId;
}

