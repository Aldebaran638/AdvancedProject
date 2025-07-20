package com.zeroone.star.project.query.j7.propertymanage.invoice;

import com.zeroone.star.project.query.PageQuery;
import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;

/**
 * <p>
 * 描述: 查询发票信息
 * </p>
 * @author ermali
 * @version 1.0
 */
@ApiModel("发票信息查询模型")
@Data
public class InvoiceQuery extends PageQuery {
    @ApiModelProperty(value = "发票编号",example = "123789" )
    private String invoiceCode;
    @ApiModelProperty(value = "发票类型  1001个人 2002 企业",example = "1001" )
    private String invoiceType;
    @ApiModelProperty(value = "业主名称",example = "孙悟空" )
    private String ownerName;
    @ApiModelProperty(value = "申请人",example = "asd" )
    private String createUserName;
    @ApiModelProperty(value = "申请人电话",example = "123456" )
    private String applyTel;
}
