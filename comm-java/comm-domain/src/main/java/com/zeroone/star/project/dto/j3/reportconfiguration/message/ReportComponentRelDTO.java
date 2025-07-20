package com.zeroone.star.project.dto.j3.reportconfiguration.message;

import com.fasterxml.jackson.annotation.JsonFormat;
import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;

import java.time.LocalDateTime;

@ApiModel("报表组件关系删除")
@Data
public class ReportComponentRelDTO {


    @ApiModelProperty(value = "组件ID", example = "102022040879310012", required = true)
    private String componentId;

    @ApiModelProperty(value = "报表编号", example = "1020211112807918355", required = true)
    private String customId;

    @ApiModelProperty(value = "组件关系编号", example = "102025051509590009", required = true)
    private String relId;
}
