package com.zeroone.star.project.vo.j6.contractmanagement.draftcontract;

import com.fasterxml.jackson.annotation.JsonProperty;
import com.zeroone.star.project.query.PageQuery;
import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.*;

import java.util.List;

/*
 *描述 ：
 *Author:28768
 */
@Data
@ApiModel("选择合同列表数据传输对象")
public class SelectContractsVO extends PageQuery {
    @ApiModelProperty(value = "选择合同列表", example = "【】")
    @JsonProperty("contractSelect")
    private List<ContractSelectVO> contractSelect;
}
