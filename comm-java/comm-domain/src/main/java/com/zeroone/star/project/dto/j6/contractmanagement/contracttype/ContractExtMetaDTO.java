package com.zeroone.star.project.dto.j6.contractmanagement.contracttype;

import com.fasterxml.jackson.annotation.JsonProperty;
import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;

import javax.validation.constraints.NotBlank;
import javax.validation.constraints.NotNull;

@Data
@ApiModel("合同扩展信息参数")
public class ContractExtMetaDTO {
    /**
     * 合同类型ID
     */
    @ApiModelProperty(value = "合同类型ID", example = "812025051612450095", required = true)
    @NotBlank(message = "合同类型ID不能为空")
    @JsonProperty("contractTypeId")
    private String contractTypeId;

    /**
     * 规格ID
     */
    @ApiModelProperty(value = "规格ID", example = "822025051998170008")
    @JsonProperty("specCd")
    private String specCd;

    /**
     * 规格名称（必填）
     */
    @ApiModelProperty(value = "规格名称（必填）", example = "装修保证金", required = true)
    @NotBlank(message = "规格名称不能为空")
    @JsonProperty("specName")
    private String specName;

    /**
     * 说明（选填）
     */
    @ApiModelProperty(value = "说明（选填）", example = "装修时需缴纳的押金")
    @JsonProperty("specHoldplace")
    private String specHoldplace;

    /**
     * 是否必填（必选）
     */
    @ApiModelProperty(value = "是否必填（必选）", example = "true", required = true)
    @NotNull(message = "必填状态不能为空")
    @JsonProperty("required")
    private Boolean required;

    /**
     * 是否展示（必选）
     */
    @ApiModelProperty(value = "是否展示（必选）", example = "true", required = true)
    @NotNull(message = "展示状态不能为空")
    @JsonProperty("specShow")
    private Boolean specShow;

    /**
     * 值类型（必选）
     */
    @ApiModelProperty(
            value = "值类型（必选）",
            example = "整数",
            allowableValues = "字符串, 整数, 金额, 日期, 时间",
            required = true
    )
    @NotNull(message = "值类型不能为空")
    @JsonProperty("specValueType")
    private String specValueType;

    /**
     * 规格类型（必选）
     */
    @ApiModelProperty(
            value = "规格类型（必选）",
            example = "input",
            allowableValues = "input, select",
            required = true
    )
    @NotNull(message = "规格类型不能为空")
    @JsonProperty("specType")
    private String specType;

    /**
     * 查询显示（必选）
     */
    @ApiModelProperty(value = "查询显示（必选）", example = "true", required = true)
    @NotNull(message = "查询显示状态不能为空")
    @JsonProperty("listShow")
    private Boolean listShow;
}
