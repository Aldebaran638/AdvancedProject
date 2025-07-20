package com.zeroone.star.project.dto.j3.systemmanage.communitysetting;

import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.AllArgsConstructor;
import lombok.Data;
import lombok.NoArgsConstructor;


@Data
@AllArgsConstructor
@NoArgsConstructor
@ApiModel("修改小区相关设置项")
public class UpdateCommunitySettingItemDTO {
    @ApiModelProperty(value = "主键ID",  example = "112023082032880001", required = true)
    private String csId;

    @ApiModelProperty(value = "设置值",  example = "0", required = true)
    private String settingValue;
}
