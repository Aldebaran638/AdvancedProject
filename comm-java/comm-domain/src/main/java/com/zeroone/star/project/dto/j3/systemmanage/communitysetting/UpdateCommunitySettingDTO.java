package com.zeroone.star.project.dto.j3.systemmanage.communitysetting;

import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.AllArgsConstructor;
import lombok.Data;
import lombok.NoArgsConstructor;

import java.util.List;

@Data
@AllArgsConstructor
@NoArgsConstructor
@ApiModel("提交配置项修改值模型")
public class UpdateCommunitySettingDTO {

    @ApiModelProperty(value = "修改小区相关设置项",  required = true)
    private List<UpdateCommunitySettingItemDTO> settingItems;
}
