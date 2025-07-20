package com.zeroone.star.project.dto.j4.orgmanager;


import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.AllArgsConstructor;
import lombok.Builder;
import lombok.Data;
import lombok.NoArgsConstructor;

import java.io.Serializable;
import java.util.List;

/**
 * @Author:zzw3867
 */
@ApiModel("班次设置传输数据对象")
@Data
@Builder
@AllArgsConstructor
@NoArgsConstructor
public class ShiftSettingDTO implements Serializable {
    private static final long serialVersionUID = 1L;

    @ApiModelProperty(value = "班次编号", example = "102025051399570080")
    private String classesId;
    @ApiModelProperty(value = "班次名称", example = "早班1")
    private String name;
    @ApiModelProperty(value = "工作时间段", example = "[\"4:30~11:30\"]", required = true)
    private List<String> workTime;

}
