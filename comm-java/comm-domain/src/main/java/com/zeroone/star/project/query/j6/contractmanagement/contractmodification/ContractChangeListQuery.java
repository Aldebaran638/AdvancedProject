package com.zeroone.star.project.query.j6.contractmanagement.contractmodification;

import com.fasterxml.jackson.annotation.JsonProperty;
import com.zeroone.star.project.query.PageQuery;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;

@Data
public class ContractChangeListQuery extends PageQuery {

    @ApiModelProperty(value = "合同名称", example = "12123")
    @JsonProperty("contractName")
    private String contractName;

    @ApiModelProperty(value = "合同编号", example = "12345")
    @JsonProperty("contractCode")
    private String contractCode;

    @ApiModelProperty(value = "合同类型", example = "1001")
    @JsonProperty("contractType")
    private String contractType;
}
