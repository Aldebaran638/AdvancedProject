package com.zeroone.star.project.dto.j5.community.notepad;


import com.zeroone.star.project.dto.PageDTO;
import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;

import javax.validation.constraints.NotBlank;

@ApiModel("删除跟进进度DTO")
@Data
public class DeleteNotepadDetailDTO  {
    @ApiModelProperty(value = "社区Id" , example = "102025051439860020" , required = true)
    @NotBlank(message = "社区Id不可为空")
    private String communityId;
    @ApiModelProperty(value = "业务反馈主表Id" , example = "102025051439860020" , required = true)
    @NotBlank(message = "业务反馈主表Id不能为空")
    private String noteId;
    @ApiModelProperty(value = "反馈业务受理进度表Id" , example = "102025051439860020",required = true)
    @NotBlank(message = "反馈业务详细受理进度表Id不能为空")
    private String detailId;
/*
    @ApiModelProperty(value = "反馈业务受理进度内容" , example = "已确定业务受理日期...")
    private String content;
    @ApiModelProperty(value = "进度受理时间" , example = "2025-05-14 20:06:16")
    private String createTime;
    @ApiModelProperty(value = "受理人人Id" , example = "30202305221014327189000174")
    private String createUserId;
    @ApiModelProperty(value = "受理人姓名" , example = "HC演示物业2")
    private String createUserName;
    @ApiModelProperty(value = "数据状态 (S-保存 0-在用 1-失效)")
    private String stateCd;
*/

}
