package com.zeroone.star.project.query.j6.contractmanagement.draftcontract;

import com.fasterxml.jackson.annotation.JsonProperty;
import com.zeroone.star.project.query.PageQuery;
import io.swagger.annotations.ApiModelProperty;
import lombok.Getter;
import lombok.Setter;
import lombok.ToString;


@ToString
@Getter
@Setter
public class ContractQuery extends PageQuery {

    @ApiModelProperty(value = "合同id", example = "812025051694590145")
    @JsonProperty("contractId")
    private String contractId;

    @ApiModelProperty(value = "合同名称", example = "测试合同")
    @JsonProperty("contractName")
    private String contractName;

    @ApiModelProperty(value = "合同编号", example = "23")
    @JsonProperty("contractCode")
    private String contractCode;

    @ApiModelProperty(value = "合同类型", example = "812025051689920006")
    @JsonProperty("contractType")
    private String contractType;
}
