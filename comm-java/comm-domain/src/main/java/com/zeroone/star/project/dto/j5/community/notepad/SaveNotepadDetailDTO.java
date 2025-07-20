package com.zeroone.star.project.dto.j5.community.notepad;

import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;

import javax.validation.constraints.NotBlank;

@ApiModel("添加跟进记录DTO")
@Data
public class SaveNotepadDetailDTO  {

    @ApiModelProperty(value = "社区Id" , example = "2023052267100146" ,required = true)
    @NotBlank(message = "社区Id不能为空")
    private String communityId;
    @ApiModelProperty(value = "反馈业务受理进度主表Id" , example = "102025051439860020" ,required = true)
    @NotBlank(message = "反馈业务受理进度主表Id不能为空")
    private String noteId;
    @ApiModelProperty(value = "反馈业务受理进度内容" , example = "已修理小区劳大雕像" ,required = true)
    private String content;
    @ApiModelProperty(value = "反馈是否完成 (W-完成 F-跟进中)" , example = "W" ,required = true)
    private String state;


}
