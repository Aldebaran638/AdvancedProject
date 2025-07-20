package com.zeroone.star.project.query.j7.propertymanage.invoice;

import com.zeroone.star.project.query.PageQuery;
import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;

/**
 * @author ermali
 * @version 1.0
 */

@ApiModel("发票信息详情查询模型")
@Data
public class InvoiceDetailsQuery extends PageQuery {

    @ApiModelProperty(value = "发票申请ID",example = "111111111111111111", required = true)
    private String applyId;

    @ApiModelProperty(value = "小区ID",example = "2024022647620054", required = true)
    private String communityId;
}
