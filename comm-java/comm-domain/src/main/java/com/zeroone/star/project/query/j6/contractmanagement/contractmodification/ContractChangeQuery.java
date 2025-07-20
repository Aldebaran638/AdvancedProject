package com.zeroone.star.project.query.j6.contractmanagement.contractmodification;

import com.fasterxml.jackson.annotation.JsonProperty;
import com.zeroone.star.project.query.PageQuery;
import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;
import lombok.EqualsAndHashCode;


/**
 * <p>
 * 合同变更查询对象
 * </p>
 * @author RC
 * @since 2025-5-18
 */
@EqualsAndHashCode(callSuper = true)
@Data
@ApiModel("查询合同变更对象")
public class ContractChangeQuery extends PageQuery {
    @ApiModelProperty(value = "合同名称", example = "RC")
    @JsonProperty("contractNameLike")
    private String contractNameLike;
}
