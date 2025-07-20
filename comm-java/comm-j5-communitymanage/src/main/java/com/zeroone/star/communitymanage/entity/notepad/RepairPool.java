package com.zeroone.star.communitymanage.entity.notepad;

import com.baomidou.mybatisplus.annotation.*;
import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;
import java.time.LocalDateTime;

@Data
@TableName("r_repair_pool")
@ApiModel(value = "RepairPool", description = "报修业务具体信息")
public class RepairPool {
    // 示例数据：822024022663000249	202024022655180250	2023052267100146	102024021885971825	UBUHU	19212535322	疏通下水道
    // 2024-02-26 17:36:54	1000	0	004	752024022246330013	2栋1单元111室	2024-02-26 17:35:51		T

    @ApiModelProperty(value = "报修ID", example = "822024022663000249", required = true)
    @TableId(value = "repair_id", type = IdType.ASSIGN_ID)
    private Long repairId;


    @ApiModelProperty(value = "业务ID，默认值为-1", example = "202024022655180250", required = true)
    private String bId;

    @ApiModelProperty(value = "小区ID", example = "2023052267100146", required = true)
    private String communityId;

    @ApiModelProperty(value = "报修类型", example = "102024021885971825", required = true)
    private String repairType;

    @ApiModelProperty(value = "报修人姓名", example = "UBUHU", required = true)
    private String repairName;

    @ApiModelProperty(value = "手机号", example = "19212535322", required = true)
    private String tel;

    @ApiModelProperty(value = "报修内容", example = "疏通下水道", required = true)
    private String context;

    @ApiModelProperty(value = "创建时间", example = "2024-02-26 17:36:54", required = true)
    @TableField(fill = FieldFill.INSERT)
    private LocalDateTime createTime;

    @ApiModelProperty(value = "报修状态，请查看state表", example = "1000", required = true)
    private String state;

    @ApiModelProperty(value = "数据状态，默认值为0", example = "0", required = true)
    private String statusCd;

    @ApiModelProperty(value = "报修对象类型 001 小区 002 楼栋 003 单元 004 房屋", example = "004", required = true)
    private String repairObjType;

    @ApiModelProperty(value = "报修对象ID", example = "752024022246330013", required = true)
    private String repairObjId;

    @ApiModelProperty(value = "报修对象名称", example = "2栋1单元111室", required = true)
    private String repairObjName;

    @ApiModelProperty(value = "预约时间", example = "2024-02-26 17:35:51", required = true)
    private LocalDateTime appointmentTime;

    @ApiModelProperty(value = "维修类型 1001有偿服务 1002无偿服务", example = "1001", required = true)
    private String maintenanceType;

    @ApiModelProperty(value = "报修渠道 D员工代客报修 T电话报修 Z业主自主保修", example = "T", required = true)
    private String repairChannel;

    @ApiModelProperty(value = "维修物料", example = "", required = true)
    private String repairMaterials;

    @ApiModelProperty(value = "费用明细：单价*数量=总价", example = "", required = true)
    private String repairFee;

    @ApiModelProperty(value = "支付方式 1现金 2微信转账 3微信公众号 4支付宝", example = "", required = true)
    private String payType;
}