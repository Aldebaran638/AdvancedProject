package com.zeroone.star.project.dto.j5.community.notepad;

import com.baomidou.mybatisplus.annotation.FieldFill;
import com.baomidou.mybatisplus.annotation.TableField;
import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;

import javax.validation.constraints.NotBlank;
import javax.validation.constraints.NotNull;
import javax.validation.constraints.Pattern;
import java.time.LocalDateTime;

/**
 * <p>
 * 添加业主反馈模型
 * </p>
 *
 * @author 人间理想
 * @since 2023-07-04
 */
@ApiModel("添加业主反馈模型")
@Data
public class AddNotepadDTO {

    @ApiModelProperty(value="房间id",example = "752022082030880010",required = true)
    @Pattern(regexp= "^[0-9]+$",message = "房间id必需是数字")
    private String roomId;

    @ApiModelProperty(value="房间名称",example = "D-1-1001",required = true)
    private String roomName;

    @ApiModelProperty(value="业主id",example = "102022082133420005",required = true)
    @Pattern(regexp= "^[0-9]+$",message = "业主id必需是数字")
    private String objId;

    @ApiModelProperty(value="业主名称",example = "张三",required = true)
    private String objName;

    @ApiModelProperty(value="联系方式",example = "18909711447",required = true)
    @Pattern(regexp= "^[0-9]+$",message = "联系方式必需是数字")
    private String link;

    @NotBlank(message = "类型不能为空")
    @ApiModelProperty(value="反馈类型(1,其他)",example = "1",required = true)
    private String noteType;

    @NotBlank(message ="内容信息不能为空不能为空")
    @ApiModelProperty(value="内容",example = "W",required = true)
    private String content;

    @ApiModelProperty( value = "小区id",example = "102022082133420005",required = true)
    @Pattern( regexp = "^[0-9]+$",  message = "小区id必须是数字")
    private String communityId;



}
