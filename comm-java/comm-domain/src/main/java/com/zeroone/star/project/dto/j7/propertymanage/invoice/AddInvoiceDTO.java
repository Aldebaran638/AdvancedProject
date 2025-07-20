package com.zeroone.star.project.dto.j7.propertymanage.invoice;

import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import io.swagger.annotations.ApiOperation;
import lombok.Data;

/**
 * <p>
 * 添加发票信息模型
 * </p>
 *
 * @author douya266
 * @since 2025-05-19
 */
@ApiModel("新增发票领域模型")
@Data
public class AddInvoiceDTO {

    @ApiModelProperty(value = "业主发票id(发票抬头id）", example = "102025051675600015")
    private String oiId;
    @ApiModelProperty(value = "发票类型1001 个人 2002 企业", example = "1001", required = true)
    private String invoiceType;
    @ApiModelProperty(value = "业主", example = "233", required = true)
    private String ownerName;
    @ApiModelProperty(value = "申请人", example = "douya")
    private String createUserName;
    @ApiModelProperty(value = "申请人电话", example = "18899995566")
    private String applyTel;
    @ApiModelProperty(value = "申请金额", example = "233.00")
    private double invoiceAmount;
    @ApiModelProperty(value = "社区id", example = "2025051506460033")
    private String communityId;
    @ApiModelProperty(value = "用户id", example = "302025051540540017")
    private String createUserId;
    @ApiModelProperty(value = "审核状态，W待审核 U 待上传 F 审核失败 G 带领用 C 已领用", example = "W")
    private String state;
    @ApiModelProperty(value = "备注", example = "无")
    private String remark;
    @ApiModelProperty(value = "开票内容1001 账户预存 2002 物业缴费", example = "1001",  required = true)
    private String itemName;
    @ApiModelProperty(value = "缴费时间", example = "2025-05-14 19:40:51")
    private String payTime;
     @ApiModelProperty(value = "收据ID或缴费id(账户预存为收据id，物业缴费为缴费id)", example = "112025052002260028")
    private String itemObjId;
}
