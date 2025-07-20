package com.zeroone.star.project.dto.j7.propertymanage.Invoicetitle;

import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;
@ApiModel("发票抬头数据传输模型")
@Data
public class InvoicetitleDTO extends AddInvoicetitleDTO{
    @ApiModelProperty(value="ID",example = "102023100981180008",required = true)
    private String oiId;
}
