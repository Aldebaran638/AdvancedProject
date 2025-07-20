package com.zeroone.star.communitymanage.entity.notepad;

import com.baomidou.mybatisplus.annotation.*;
import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;

import java.time.LocalDateTime;


@ApiModel("业务受理-跟进记录主表")
@TableName("notepad")
@Data
public class NotePad {

    @ApiModelProperty(value = "业务受理进度主表Id", example = "2023052267100146", required = true)
    @TableId(value = "note_id", type = IdType.ASSIGN_ID)
    private String noteId;

    @ApiModelProperty(value = "业务类型", example = "1", required = true)
    @TableField(value ="note_type")
    private String noteType;

    @ApiModelProperty(value = "受理内容", example = "定好受理时间....", required = true)
    private String title;

    @ApiModelProperty(value = "反馈业主房屋Id", example = "752021012579820037", required = true)
    @TableField(value ="room_id")
    private String roomId;

    @ApiModelProperty(value = "反馈业主房屋名称", example = "1-1-2", required = true)
    @TableField(value ="room_name")
    private String roomName;

    @ApiModelProperty(value = "反馈业主角色", example = "3309-对应业主 3308-员工", required = true)
    @TableField(value ="obj_type")
    private String objType;

    @ApiModelProperty(value = "业主Id", example = "752021012579820037", required = true)
    @TableField(value ="obj_id")
    private String objId;

    @ApiModelProperty(value = "业主名字", example = "张三", required = true)
    @TableField(value ="obj_name")
    private String objName;

    @ApiModelProperty(value = "受理人Id", example = "752021012579820037", required = true)
    @TableField(value ="create_user_id",fill = FieldFill.INSERT)
    private String createUserId; // 登记人

    @ApiModelProperty(value = "受理人名称", example = "东北雨姐", required = true)
    @TableField(value ="create_user_name",fill = FieldFill.INSERT)
    private String createUserName; // 登记人名称

    @ApiModelProperty(value = "其他关联ID（例如报修ID）", example = "822022082293540003", required = true)
    @TableField(value ="thrid_id")
    private String thridId;

    @ApiModelProperty(value = "业务状态（W跟进中，F完成）", example = "W", required = true)
    private String state;

    @ApiModelProperty(value = "创建时间", example = "2025-04-05 10:00:00", required = true)
    @TableField(value ="create_time" , fill = FieldFill.INSERT)
    private LocalDateTime createTime;

    @ApiModelProperty(value = "数据状态（S保存，0在用，1失效）", example = "0", required = true)
    @TableField(value ="status_cd")
    private String statusCd;

    @ApiModelProperty(value = "联系电话", example = "52013146666", required = true)
    private String link;


}