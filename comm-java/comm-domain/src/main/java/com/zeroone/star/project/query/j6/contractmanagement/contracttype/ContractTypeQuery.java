package com.zeroone.star.project.query.j6.contractmanagement.contracttype;

import com.fasterxml.jackson.annotation.JsonProperty;
import com.zeroone.star.project.query.PageQuery;
import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;
import lombok.EqualsAndHashCode;

/*
 * 描述 ：
 * Author:28768
 */
@Data
@ApiModel("获取合同类型列表分页对象")
public class ContractTypeQuery extends PageQuery  {

    /**
     * 合同类型名称
     */
    @ApiModelProperty(value = "合同类型名称", example = "kunge8")
    @JsonProperty("typeName")
    private String typeName;

    /**
     * 是否需要审核，1001 需要审核 2002 不需要审核 3003 需要admin审核  4004 需要 代理商审核
     */
    @ApiModelProperty(value = "审核状态", example = "1001")
    @JsonProperty("audit")
    private String audit;
}
