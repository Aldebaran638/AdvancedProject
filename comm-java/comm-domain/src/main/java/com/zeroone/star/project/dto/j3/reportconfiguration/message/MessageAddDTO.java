package com.zeroone.star.project.dto.j3.reportconfiguration.message;

import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Getter;
import lombok.Setter;
import lombok.ToString;
import javax.validation.constraints.NotBlank;
import javax.validation.constraints.NotNull;

import javax.validation.constraints.NotBlank;
import javax.validation.constraints.Size;

@Getter
@Setter
@ToString
@ApiModel("报表信息添加")
public class MessageAddDTO {
    @ApiModelProperty(value = " 报表组ID", example = "102021111007300001 报修报表 102022022795370086 营业报表 102022051141350637 巡检报表",required = true)
    @NotBlank(message = "报表组不能为空")
    private String groupId;

    @ApiModelProperty(value = "选项标题", example = "月度销售报表",required = true)
    @NotBlank(message = "选项标题不能为空")
    private String title;

    @ApiModelProperty(value = "排序", example = "1",required = true)
    @NotNull(message = "排序不能为空")
    private Integer seq;

    @ApiModelProperty(value = "描述", example = "这是2021年11月的销售报表")
    private String remark;

}