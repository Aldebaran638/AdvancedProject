package com.zeroone.star.project.dto.j7.propertymanage.invoice;

import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;

/**
 * @author ermali
 * @version 1.0
 */

@ApiModel("查询发票领域模型")
@Data
public class QueryInvoiceDTO extends InvoiceDTO{

    @ApiModelProperty(value = "申请时间",  example = "2023-01-01 00:00:00")
    private String createTime;

    @ApiModelProperty(value = "发票号",  example = "123789")
    private String invoiceCode;

    @ApiModelProperty(value = "发票名头",  example = "asd")
    private String invoiceName;

    @ApiModelProperty(value = "纳税人识别号",  example = "123456789")
    private String invoiceNum;

    @ApiModelProperty(value = "地址，电话",  example = "上海")
    private String invoiceAddress;

}
