package com.zeroone.star.project.vo.j3.reportconfiguration.message;

import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;

@Data
@ApiModel(value="报表信息")
public class MessageVo {
    @ApiModelProperty(value = "报表编号", example = "102021111204870302")
    private String customId;

    @ApiModelProperty(value = "组编号对应的组名称")
    private String groupName;

    @ApiModelProperty(value = "选项标题", example = "投诉咨询")
    private String title;

    @ApiModelProperty(value = "排序序号", example = "1")
    private Integer seq;

    @ApiModelProperty(value = "描述信息", example = "本报表展示每月销售数据汇总")
    private String remark;
}
