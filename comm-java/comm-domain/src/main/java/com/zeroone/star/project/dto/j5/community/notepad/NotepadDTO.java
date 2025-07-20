package com.zeroone.star.project.dto.j5.community.notepad;

import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;

import javax.validation.constraints.NotBlank;
import javax.validation.constraints.Pattern;
import java.time.LocalDateTime;

/**
 * <p>
 * 描述： 业主反馈数据传输模型
 * </p>
 *
 * @author 人间理想
 * @since 2023/5/23 14:05
 */
@ApiModel("业主反馈传输模型")
@Data
public class NotepadDTO extends AddNotepadDTO{

    @ApiModelProperty(value = "反馈id", example = "102022082133420005",required = true)
    @NotBlank( message = "反馈id不能为空")
    @Pattern(regexp= "^[0-9]+$",message = "反馈id必需是数字")
    private String noteId;

    @ApiModelProperty(value="创建的时间",example = "2023-05-23 14:05:05",required = true)
    private LocalDateTime createTime;

    @ApiModelProperty(value="登记人",example = "张三",required = true)
    private String createUserName;

    @ApiModelProperty(value="其他关联ID（例如报修ID）",example = "822022082293540003")
    @Pattern(regexp= "^[0-9]+$",message = "反馈id必需是数字")
    private String thirdId;

    @ApiModelProperty(value="创建人id",example = "302022081574590429",required = true)
    private String createUserId;

    @ApiModelProperty(value="反馈类型的值",example = "其他")
    private String noteTypeValue;

    @ApiModelProperty(value="反馈状态(W,跟进中),(F,完成),(如果有第三方id,(跟进中 (已转报修单)))",example = "W",required = true)
    private String state;


}
