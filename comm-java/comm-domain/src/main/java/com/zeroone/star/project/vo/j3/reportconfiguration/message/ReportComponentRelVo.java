package com.zeroone.star.project.vo.j3.reportconfiguration.message;

import com.fasterxml.jackson.annotation.JsonFormat;
import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;
import java.time.LocalDateTime;

@ApiModel("报表组件关系")
@Data
public class ReportComponentRelVo {

    @ApiModelProperty(value = "组件组", example = "C")
    private String componentGroup;

    @ApiModelProperty(value = "组件ID", example = "102022040879310012")
    private String componentId;

    @ApiModelProperty(value = "组件名称", example = "业主房屋费用统计")
    private String componentName;

    @ApiModelProperty(value = "组件类型", example = "1001")
    private String componentType;

    @ApiModelProperty(value = "创建时间", example = "2025-05-15 13:24:14")
    @JsonFormat(pattern = "yyyy-MM-dd HH:mm:ss")
    private LocalDateTime createTime;

    @ApiModelProperty(value = "报表编号", example = "1020211112807918355")
    private String customId;

    @ApiModelProperty(value = "查询模型", example ="1")
    private String queryModel;

    @ApiModelProperty(value = "组件关系编号", example = "102025051509590009")
    private String relId;

    @ApiModelProperty(value = "序号", example = "1")
    private int seq;

    @ApiModelProperty(value = "状态", example = "0")
    private String statusCd;
}
