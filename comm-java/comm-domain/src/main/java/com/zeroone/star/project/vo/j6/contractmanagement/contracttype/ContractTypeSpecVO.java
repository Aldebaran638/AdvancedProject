package com.zeroone.star.project.vo.j6.contractmanagement.contracttype;

import com.fasterxml.jackson.annotation.JsonProperty;
import io.swagger.annotations.ApiModelProperty;
import lombok.AllArgsConstructor;
import lombok.Data;
import lombok.NoArgsConstructor;

/**
 * @author 张帅
 * @version 1.0
 */
@Data
@AllArgsConstructor
@NoArgsConstructor
public class ContractTypeSpecVO {

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

    @ApiModelProperty(value = "规格id", example = "888888333222")
    @JsonProperty("specCd")
    private String specCd;

    @ApiModelProperty(value = "数据状态，S 保存，0 在用 1失效", example = "S")
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
}
