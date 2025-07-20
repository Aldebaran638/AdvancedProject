package com.zeroone.star.project.dto.j6.contractmanagement.draftcontract;

import com.fasterxml.jackson.annotation.JsonProperty;
import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;

import javax.validation.constraints.NotNull;

@Data
@ApiModel(value = "合同打印数据传输对象")
public class ContractPrintDTO {

    @NotNull(message = "合同ID不能为空")
    @ApiModelProperty(value = "合同ID", example = "9988776", required = true)
    @JsonProperty("contractId")
    private String contractId;

    @ApiModelProperty(value = "合同类型id", example = "12122")
    @JsonProperty("contractTypeId")
    private String contractTypeId;
}
