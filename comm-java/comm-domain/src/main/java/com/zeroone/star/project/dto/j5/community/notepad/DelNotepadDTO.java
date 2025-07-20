package com.zeroone.star.project.dto.j5.community.notepad;

import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;

import javax.validation.constraints.NotBlank;
import javax.validation.constraints.Pattern;

@ApiModel("添加业主反馈模型")
@Data
public class DelNotepadDTO {

    @NotBlank(message = "反馈id不能为空")
    @ApiModelProperty(value = "反馈id", example = "1928022151462490114",required = true)
    @Pattern(regexp= "^[0-9]+$",message = "反馈id必需是数字")
    private String noteId;

    @NotBlank(message = "业主id不能为空")
    @ApiModelProperty(value = "业主id",example = "102022082133420005",required = true)
    @Pattern(regexp= "^[0-9]+$",message = "业主id必需是数字")
    private String objId;
}
