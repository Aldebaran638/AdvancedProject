package com.zeroone.star.project.dto.j5.community.notepad;

import com.fasterxml.jackson.annotation.JsonFormat;
import com.zeroone.star.project.dto.PageDTO;
import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;

import javax.validation.constraints.NotBlank;
import javax.validation.constraints.Pattern;
import java.time.LocalDateTime;
import java.util.List;


@ApiModel("反馈受理任务转报修单DTO ")
@Data
public class ChangeToRepairDTO  {

    /*@ApiModelProperty(value = "报修ID", example = "822025051904210009")
    private String repairId;
*/


    @ApiModelProperty(value = "维修类型编号", example = "102024021885971825" , required = true)
    @NotBlank(message = "报修类型编号不能为空")
    private String repairType;

    @ApiModelProperty(value = "报修人姓名", example = "东北雨姐" , required = true)
    private String repairName;

    @ApiModelProperty(value = "联系电话", example = "18049392222" ,required = true)
    @Pattern(regexp = "^((13[0-9])|(14[5,7])|(15[^4,\\D])|(17[0,6-8])|(18[0-9]))\\d{8}$", message = "请输入正确的手机号")
    private String tel;

    @ApiModelProperty(value = "预约时间", example = "2025-05-19 11:21:07" , required = true)
    @JsonFormat(pattern = "yyyy-MM-dd HH:mm:ss" )
    private LocalDateTime appointmentTime;

    @ApiModelProperty(value = "内容描述", example = "====" , required = true)
    private String context;

    /*@ApiModelProperty(value = "报修对象类型 001 小区 002 楼栋 003 单元 004 房屋", example = "004" , required = true)
    private String repairObjType;*/

    @ApiModelProperty(value = "报修房间ID", example = "752024021954542993" , required = true)
    @NotBlank(message = "报修房间ID不能为空")
    private String repairObjId;

    @ApiModelProperty(value = "报修房间名称", example = "1-1-2" , required = true)
    private String repairObjName;

    @ApiModelProperty(value = "报修渠道 D员工代客报修  T电话报修 Z业主自主保修", example = "T" ,required = true)
    private String repairChannel;

    @ApiModelProperty(value = "业务反馈ID", example = "102025051439860020" , required = true)
    @NotBlank(message = "业务反馈ID不能为空")
    private String noteId;

    @ApiModelProperty(value = "社区ID", example = "2023052267100146" ,required = true)
    @NotBlank(message = "社区ID不能为空")
    private String communityId;
    /*@ApiModelProperty(value = "查询出的报修类型列表", example = "", required = true)
    private List<RepairTypeDTO> repairSettings;*/


}
