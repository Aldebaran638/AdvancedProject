package com.zeroone.star.project.dto.j3.reportconfiguration.group;

import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;

@ApiModel("表报组数据传输对象")
@Data
public class GroupDTO extends AddGroupDTO{
    @ApiModelProperty(value = "组ID", example = "102021111007300001", required = true)
    private String groupId;
}
