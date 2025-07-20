package com.zeroone.star.project.dto.j6.contractmanagement.contracttype;

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
public class ContractTypeTemplateDTO {
    /**
     * 合同类型ID
     */
    @ApiModelProperty(value = "合同类型编号", example = "1")
    @JsonProperty("contractTypeId")
    private String contractTypeId;

    /**
     * 模板内容
     */
    @ApiModelProperty(value = "合同模板内容", example = "<p>#甲方##乙方##合同名称##签订时间#<br></p>")
    @JsonProperty("context")
    private String context;

    @ApiModelProperty(value = "合同模板id", example = "2222222")
    @JsonProperty("templateId")
    private String templateId;
}
