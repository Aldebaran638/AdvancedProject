package com.zeroone.star.communitymanage.entity.notepad;

import com.baomidou.mybatisplus.annotation.TableField;
import com.baomidou.mybatisplus.annotation.TableName;
import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;

import java.time.LocalDateTime;

@ApiModel("报修类型表")
@TableName("r_repair_setting")
@Data
public class RepairType {
    @ApiModelProperty(value = "工单设置ID", example = "102024021885971825", required = true)
    @TableField("setting_id")
    private String settingId;

    @ApiModelProperty(value = "业务ID", example = "-1", required = true)
    @TableField("b_id")
    private String bId;

    @ApiModelProperty(value = "报修类型", example = "200", required = true)
    @TableField("repair_type")
    private String repairType;

    @ApiModelProperty(value = "报修类型名称", example = "下水道堵塞", required = true)
    @TableField("repair_type_name")
    private String repairTypeName;

    @ApiModelProperty(value = "派单方式 t_dict 100 抢单 200 指派 300 轮训", example = "200", required = true)
    @TableField("repair_way")
    private String repairWay;

    @ApiModelProperty(value = "小区分片ID", example = "2023052267100146", required = true)
    @TableField("community_id")
    private String communityId;

    @ApiModelProperty(value = "备注", example = "", required = true)
    @TableField("remark")
    private String remark;

    @ApiModelProperty(value = "数据状态", example = "0", required = true)
    @TableField("status_cd")
    private String statusCd;

    @ApiModelProperty(value = "创建时间", example = "2024-02-18 17:51:05", required = true)
    @TableField("create_time")
    private LocalDateTime createTime;

    @ApiModelProperty(value = "是否为公共区域", example = "F", required = true)
    @TableField("public_area")
    private String publicArea;

    @ApiModelProperty(value = "是否收费 T为是 F为否", example = "F", required = true)
    @TableField("pay_fee_flag")
    private String payFeeFlag;

    @ApiModelProperty(value = "收费范围，如30元至50元", example = "不收费", required = true)
    @TableField("price_scope")
    private String priceScope;

    @ApiModelProperty(value = "回访标识 001-都不回访  002-已评价不回访  003-都回访", example = "003", required = true)
    @TableField("return_visit_flag")
    private String returnVisitFlag;

    @ApiModelProperty(value = "报修设置类型", example = "200", required = true)
    @TableField("repair_setting_type")
    private String repairSettingType;

    @ApiModelProperty(value = "业主端是否展示  Y 是  N 否", example = "Y", required = true)
    @TableField("is_show")
    private String isShow;

    @ApiModelProperty(value = "通知方式，SMS 短信 WECHAT 微信", example = "SMS", required = true)
    @TableField("notify_way")
    private String notifyWay;
}