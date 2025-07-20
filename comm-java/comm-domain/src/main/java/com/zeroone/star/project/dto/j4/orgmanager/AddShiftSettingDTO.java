package com.zeroone.star.project.dto.j4.orgmanager;

import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;

import javax.validation.constraints.NotBlank;
import java.util.List;

/**
 * @Author:zzw3867
 */
@ApiModel("添加班次数据传输对象")
@Data
public class AddShiftSettingDTO {
    @ApiModelProperty(value = "班次名称", example = "早班1",required = true)
    private String name;
    @ApiModelProperty(value = "工作时间段", example = "[\"4:30~11:30\"]",required = true)
    private List<String> workTime;
    @ApiModelProperty(value = "备注说明", example = "早班加点油",required = true)
    private String remark;
}
