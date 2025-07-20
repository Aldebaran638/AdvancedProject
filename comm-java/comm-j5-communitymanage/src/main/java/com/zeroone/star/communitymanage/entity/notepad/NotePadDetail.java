package com.zeroone.star.communitymanage.entity.notepad;

import com.baomidou.mybatisplus.annotation.*;
import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;

import java.time.LocalDateTime;


@ApiModel("业务受理-详细内容表")
@TableName("notepad_detail")
@Data
public class NotePadDetail {

    @TableField("detail_id")
    @ApiModelProperty(value = "id", example = "102022082131680011", required = true)
    @TableId(type = IdType.ASSIGN_ID)
    private String detailId;

    @TableField("note_id")
    @ApiModelProperty(value = "业务反馈主表Id", example = "102022082170410008", required = true)
    private String noteId;

    @TableField("content")
    @ApiModelProperty(value = "跟进内容", example = "已处理完成 爱你", required = true)
    private String content;

    @TableField(value = "create_user_id" , fill = FieldFill.INSERT)
    @ApiModelProperty(value = "登记人(受理人)ID", example = "302022081574590429", required = true)
    private String createUserId;

    @TableField(value = "create_user_name" , fill = FieldFill.INSERT)
    @ApiModelProperty(value = "登记人(受理人)名称", example = "wuxw", required = true)
    private String createUserName;

    @TableField(value = "create_time" , fill = FieldFill.INSERT)
    @ApiModelProperty(value = "创建时间", example = "2022-08-21 18:07:01", required = true)
    private LocalDateTime createTime;

    @TableField("status_cd")
    @ApiModelProperty(value = "数据状态，详细参考c_status表，S 保存，0 在用，1 失效", example = "1", required = true)
    private String statusCd;
}
