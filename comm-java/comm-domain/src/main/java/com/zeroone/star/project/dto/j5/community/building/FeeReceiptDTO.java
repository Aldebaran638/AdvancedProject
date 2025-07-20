package com.zeroone.star.project.dto.j5.community.building;

import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Getter;
import lombok.Setter;
import lombok.ToString;

import java.math.BigDecimal;
@Getter
@Setter
@ToString
@ApiModel("FeeReceipt数据传输对象")
public class FeeReceiptDTO {
    @ApiModelProperty(value = "欠费", example = "10800.00")
    BigDecimal oweAmount;
}
