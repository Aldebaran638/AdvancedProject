package com.zeroone.star.project.dto.j4.orgmanager;

import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;

import java.util.List;

@Data
@ApiModel("修改班次信息对象")
public class ClassManagerDTO {
    //班次Id
    @ApiModelProperty(value = "班次ID", example = "102024022247010046", required = true)
    private String classId;
    //班次名称
    @ApiModelProperty(value = "班次名称", example = "正常班次", required = true)
    private String className;
    //工作时间段，以字符串形式存储，开始时间与结束时间之间以 ~ 隔开，时间的时与分之间以 : 隔开
    @ApiModelProperty(value = "工作时间段", example = "[\"15:43~16:42\"]", required = true)
    private List<String> timePeriods;
    //备注说明
    @ApiModelProperty(value = "备注说明", example = "xxx")
    private String remark;
}
