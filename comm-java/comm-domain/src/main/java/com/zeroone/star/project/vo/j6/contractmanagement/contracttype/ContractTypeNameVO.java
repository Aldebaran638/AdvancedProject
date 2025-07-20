package com.zeroone.star.project.vo.j6.contractmanagement.contracttype;

import com.fasterxml.jackson.annotation.JsonProperty;
import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;

/*
 * 描述 ：合同类型名称对象
 * Author:kunge
 */
@ApiModel("合同类型名称对象")
@Data
public class ContractTypeNameVO {

    @ApiModelProperty(value = "合同类型编号", example = "1")
    @JsonProperty("contractTypeId")
    private String contractTypeId;

    @ApiModelProperty(value = "合同类型名称", example = "租房合同")
    @JsonProperty("typeName")
    private String typeName;
}
