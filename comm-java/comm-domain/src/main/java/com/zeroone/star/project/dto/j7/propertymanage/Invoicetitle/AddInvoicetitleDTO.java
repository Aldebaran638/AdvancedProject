package com.zeroone.star.project.dto.j7.propertymanage.Invoicetitle;

import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;
@ApiModel("添加发票抬头模型")
@Data
public class AddInvoicetitleDTO {
    @ApiModelProperty(value="业主ID",example = "772023063013350054",required = true)
    private String ownerId;
    @ApiModelProperty(value="业主名称",example = "qq2",required = true)
    private String ownerName;
    @ApiModelProperty(value="发票类型 10001 个人 2002 企业",example = "1001",required = true)
    private String invoiceType;
    @ApiModelProperty(value="发票名头",example = "是是是",required = true)
    private String invoiceName;
    @ApiModelProperty(value="纳税人识别号",example = "是是是",required = true)
    private String invoiceNum;
    @ApiModelProperty(value="地址、电话",example = "水电费水电费",required = true)
    private String invoiceAddress;
    @ApiModelProperty(value="备注",example = "是的")
    private String remark;
}
