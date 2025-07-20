package com.zeroone.star.project.j8.housemgt.committee.dto;

import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;

import javax.validation.constraints.NotBlank;
import javax.validation.constraints.Pattern;

@ApiModel("紧急联系人")
@Data
public class CommitteeContactDTO {
    @ApiModelProperty(value = "联系人姓名", example = "李四", required = true)
    @NotBlank(message = "联系人姓名不能为空")
    private String name;

    @ApiModelProperty(value = "与业委会成员关系", example = "父子", required = true)
    @NotBlank(message = "与业委会成员关系不能为空")
    private String relName;

    @ApiModelProperty(value = "联系电话", example = "13888888888", required = true)
    @NotBlank(message = "联系电话不能为空")
    @Pattern(regexp = "\\d{11}", message = "联系电话必须是11位数字")
    private String link;

    @ApiModelProperty(value = "地址", example = "01社区01栋", required = true)
    @NotBlank(message = "地址不能为空")
    private String address;

//    @ApiModelProperty(value = "备注", example = "老父亲", required = false)
//    private String remark;

}
