package com.zeroone.star.project.dto.j5.info.communityinfo;

import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;

@ApiModel("小区数据传输模型")
@Data
public class CommunityDTO extends AddCommunityDTO{
    @ApiModelProperty(value = "小区ID", example = "2024022692080516", required = true)
    private String communityId;
}
