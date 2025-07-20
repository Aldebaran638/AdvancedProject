package com.zeroone.star.project.query.j5.community.notepad;


import com.zeroone.star.project.query.PageQuery;
import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;

import javax.validation.constraints.NotBlank;

@ApiModel("查询跟进记录Query (条件 + 分页)")
@Data
public class ListNotepadDetailQuery extends PageQuery {


    @ApiModelProperty(value = "社区id" , example = "2023052267100146" , required = true)
    @NotBlank(message = "社区id不能为空")
    private String communityId;

    @ApiModelProperty(value = "业务反馈主表Id" , example = "102025051439860020" , required = true)
    @NotBlank(message = "业务反馈主表Id不能为空")
    private String noteId;

}
