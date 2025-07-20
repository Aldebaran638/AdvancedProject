package com.zeroone.star.project.dto.j5.community.notepad;


import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;

import javax.validation.constraints.NotBlank;

@ApiModel("查询报修类型Return DTO")
@Data
public class RepairTypeDTO {

    @ApiModelProperty(value = "设置主ID", example = "102024021885971825", required = true)
    @NotBlank(message = "类型ID不能为空")
    private String settingId;

    @ApiModelProperty(value = "社区ID", example = "2023052267100146" , required = true)
    @NotBlank(message = "社区ID不能为空")
    private String communityId;

    @ApiModelProperty(value = "维修类型编号", example = "102024021885971825", required = true)
    private String repairType;

    @ApiModelProperty(value = "维修类型名称", example = "下水道堵塞" , required = true)
    private String repairTypeName;

    @ApiModelProperty(value = "是否显示  Y 是  N 否", example = "Y" , required = true)
    private String isShow;

    /*@ApiModelProperty(value = "创建时间", example = "2024-02-18 17:51:05")
    private String createTime;*/


    /*@ApiModelProperty(value = "通知方式，SMS 短信 WECHAT 微信", example = "SMS")
    private String notifyWay;
    
    @ApiModelProperty(value = "是否收费标识  T为是 F为否", example = "F")
    private String payFeeFlag;

    @ApiModelProperty(value = "收费范围，如30元至50元", example = "不收费")
    private String priceScope;*/

    /*@ApiModelProperty(value = "公共区域标识", example = "F")
    private String publicArea;
    

    @ApiModelProperty(value = "备注", example = "")
    private String remark;

    @ApiModelProperty(value = "报修设置类型", example = "200")
    private String repairSettingType;

    @ApiModelProperty(value = "报修类型名称", example = "维修单")
    private String repairSettingTypeName;*/



   /* @ApiModelProperty(value = "派单方式 t_dict 100 抢单 200 指派 300 轮训", example = "200")
    private String repairWay;

    @ApiModelProperty(value = "派单方式名称", example = "指派")
    private String repairWayName;

    @ApiModelProperty(value = "回访标识 001-都不回访  002-已评价不回访  003-都回访", example = "003")
    private String returnVisitFlag;

    @ApiModelProperty(value = "回访标识名称", example = "都回访")
    private String returnVisitFlagName;


    @ApiModelProperty(value = "状态代码", example = "0")
    private String statusCd;*/

}