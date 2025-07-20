package com.zeroone.star.project.dto.j6.contractmanagement.contracttype;

import com.fasterxml.jackson.annotation.JsonProperty;
import io.swagger.annotations.ApiModelProperty;
import lombok.AllArgsConstructor;
import lombok.Data;
import lombok.NoArgsConstructor;

import java.util.List;

/**
 * @author 张帅
 * @version 1.0
 */
@Data
@AllArgsConstructor
@NoArgsConstructor
public class ContractTypeSpecDTO {
    @ApiModelProperty(value = "合同类型号", example = "812025051827870055")
    @JsonProperty("contractTypeId")
    private String contractTypeId;

    @ApiModelProperty(value = "总页数", example = "100")
    @JsonProperty("records")
    private Integer records;

    @ApiModelProperty(value = "是否查询显示", example = "Y")
    @JsonProperty("listShow")
    private String listShow;

    @ApiModelProperty(value = "规格是否显示", example = "Y")
    @JsonProperty("specShow")
    private String specShow;

    @ApiModelProperty(value = "是否必填", example = "Y")
    @JsonProperty("required")
    private String required;

    @ApiModelProperty(value = "总条数", example = "100000")
    @JsonProperty("total")
    protected Long total;

    @ApiModelProperty(value = "规格ID", example = "822020101329660070")
    @JsonProperty("specCd")
    private String specCd;

    @ApiModelProperty(value = "数据状态，详细参考c_status表，0：在用，1:失效")
    @JsonProperty("statusCd")
    private String statusCd;

    @ApiModelProperty(value = "说明", example = "123")
    @JsonProperty("specHoldplace")
    private String specHoldplace;

    @ApiModelProperty(value = "规格名称", example = "zszs")
    @JsonProperty("specName")
    private String specName;

    @ApiModelProperty(value = "规格类型", example = "3344")
    @JsonProperty("specType")
    private String specType;

    @ApiModelProperty(value = "规格值类型", example = "2002")
    @JsonProperty("specValueType")
    private String specValueType;

    @ApiModelProperty(value = "商户号", example = "102024022637410237")
    @JsonProperty("storeId")
    private String storeId;

    @ApiModelProperty(value = "当前页码数", example = "1")
    @JsonProperty("page")
    protected Long page;
}
