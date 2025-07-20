package com.zeroone.star.project.dto.j7.propertymanage.invoice;

import cn.hutool.core.date.DateTime;
import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;

import java.sql.Date;
import java.sql.Timestamp;

/**
 * @author ermali
 * @version 1.0
 */

@ApiModel("查询发票详情-----开票明细领域模型")
@Data
public class InvoiceDetailsDTO {
    @ApiModelProperty(value = "项目ID",example = "112321212312122132")
    private String itemId;
    @ApiModelProperty(value = "发票申请ID",example = "111111111111111111")
    private String applyId;

    @ApiModelProperty(value = "小区ID",example = "2024022647620054")
    private String communityId;

    @ApiModelProperty(value = "发票金额",example = "1000.00")
    private String itemAmount;

    @ApiModelProperty(value = "缴费名称",example = "物业费")
    private String itemName;

    @ApiModelProperty(value = "缴费对象ID",example ="987456789789456123" )
    private String itemObjId;

    @ApiModelProperty(value = "缴费类型  1001账户预存   2002物业缴费",example = "1001")
    private String itemType;

    @ApiModelProperty(value = "缴费时间",example = "2022-02-02")
    private Date payTime;

    @ApiModelProperty(value = "备注",example = "无")
    private String remark;

    @ApiModelProperty(value = "发票状态  详细参考c_status表， 0在用  1失效",example = "1")
    private String statusCd;

}
