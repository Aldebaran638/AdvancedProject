package com.zeroone.star.project.query.j7.propertymanage.Invoicetitle;

import com.zeroone.star.project.query.PageQuery;
import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;

@ApiModel("发票抬头查询模型")
@Data
public class InvoicetitleQuery extends PageQuery {
    @ApiModelProperty(value="业主名称",example = "xx24",required = false)
    private String ownerName;
    @ApiModelProperty(value="发票类型",example = "1001",required = false)
    private String invoiceType;
    @ApiModelProperty(value="发票名头",example = "学问大套袋公司1",required = false)
    private String invoiceName;
}
