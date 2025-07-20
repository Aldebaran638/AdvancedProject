package com.zeroone.star.project.vo.j3.reportconfiguration.message;

import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;

import java.time.LocalDateTime;

@ApiModel("组件所有")
@Data
public class ReportComponentVo {
    @ApiModelProperty(value = "组件组", example = "C")
    private String componentGroup;

    @ApiModelProperty(value = "组件ID", example = "102022040879310012")
    private String componentId;

    @ApiModelProperty(value = "组件名称", example = "业主房屋费用统计")
    private String componentName;

    @ApiModelProperty(value = "组件类型", example = "1001")
    private String componentType;

    @ApiModelProperty(value = "查询模型", example ="1")
    private String queryModel;

    @ApiModelProperty(value = "状态", example = "0")
    private String statusCd;
}
