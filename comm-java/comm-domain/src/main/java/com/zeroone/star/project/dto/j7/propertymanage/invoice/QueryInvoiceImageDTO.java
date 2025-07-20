package com.zeroone.star.project.dto.j7.propertymanage.invoice;

import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;

/**
 * @author 任彦屹
 * @version 1.0
 */

@ApiModel("查询发票照片领域模型")
@Data
public class QueryInvoiceImageDTO {

    @ApiModelProperty(value = "文件储存名称“）", example = "group1/M00/00/00/oYYBAGg5eCCABE2FABNMTaw1WE8256.jpg")
    private String fileSaveName;
}
