package com.zeroone.star.project.query.j6.contractmanagement.contracttype;

import com.fasterxml.jackson.annotation.JsonProperty;
import com.zeroone.star.project.query.PageQuery;
import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;
import lombok.EqualsAndHashCode;

/**
 * 用于接收前端传来的分页查询条件
 * @author 张帅
 * @version 1.0
 */
@EqualsAndHashCode(callSuper = true)
@Data
@ApiModel("合同扩展信息对象")
public class ContractTypeSpecQuery extends PageQuery {

    @ApiModelProperty(value = "合同类型拓展名", example = "eee")
    @JsonProperty("specName")
    private String specName;

    @ApiModelProperty(value = "规格是否展示", example = "是")
    @JsonProperty("specShow")
    private String specShow;

    @ApiModelProperty(value = "合同类型号", example = "812025051815360031")
    @JsonProperty("contractTypeId")
    private String contractTypeId;

    @ApiModelProperty(value = "规格ID", example = "822020101329660070")
    @JsonProperty("specCd")
    private String specCd;
}
