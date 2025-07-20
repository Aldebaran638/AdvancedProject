package com.zeroone.star.project.dto.j7.propertymanage.invoice;

import io.swagger.annotations.ApiModelProperty;
import lombok.Data;

/**
 * <p>
 * 描述：发票领域模型
 * </p>
 *
 * @author douya266
 * @since 2025/5/19
 */
@Data
public class InvoiceDTO extends AddInvoiceDTO {
    @ApiModelProperty(value = "编号", example = "102025051675600015")
    private String applyId;
}
