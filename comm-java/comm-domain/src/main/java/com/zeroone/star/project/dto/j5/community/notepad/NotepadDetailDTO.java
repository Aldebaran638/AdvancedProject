package com.zeroone.star.project.dto.j5.community.notepad;

import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;
import java.time.LocalDateTime;

@ApiModel("业务受理-详细内容表DTO")
@Data
public class NotepadDetailDTO  {

    @ApiModelProperty(value = "跟进进度表Id", example = "102022082131680011" , required = true)
    private String detailId;

    @ApiModelProperty(value = "业务反馈主表Id", example = "102022082170410008" , required = true)
    private String noteId;

    @ApiModelProperty(value = "跟进内容", example = "已处理完成 爱你" ,required = true)
    private String content;

    @ApiModelProperty(value = "登记人(受理人)ID", example = "302022081574590429" ,required = true)
    private String createUserId;

    @ApiModelProperty(value = "登记人(受理人)名称", example = "wuxw" ,required = true)
    private String createUserName;

    @ApiModelProperty(value = "创建时间", example = "2022-08-21 18:07:01" ,required = true)
    private LocalDateTime createTime;

    @ApiModelProperty(value = "数据状态，详细参考c_status表，S 保存，0 在用，1 失效", example = "1")
    private String statusCd;

}