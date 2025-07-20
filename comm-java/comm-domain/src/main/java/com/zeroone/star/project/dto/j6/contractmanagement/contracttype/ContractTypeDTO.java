package com.zeroone.star.project.dto.j6.contractmanagement.contracttype;

import com.fasterxml.jackson.annotation.JsonFormat;
import com.fasterxml.jackson.annotation.JsonProperty;
import io.swagger.annotations.ApiModelProperty;
import lombok.AllArgsConstructor;
import lombok.Data;
import lombok.NoArgsConstructor;
import javax.validation.constraints.NotBlank;
import java.util.Date;

/**
 * @author 张帅
 * @version 1.0
 */
@Data
@AllArgsConstructor
@NoArgsConstructor
public class ContractTypeDTO {

    @ApiModelProperty(value = "审计号", example = "1001")
    @JsonProperty("audit")
    private String audit;

    @ApiModelProperty(value = "审计名", example = "审核")
    @NotBlank(message = "审计名不能为空")
    @JsonProperty("auditName")
    private String auditName;

    @ApiModelProperty(value = "合同类型号", example = "812025051807070581")
    // @NotBlank(message = "合同类型号不能为空")
    @JsonProperty("contractTypeId")
    private String contractTypeId;

    @ApiModelProperty(value = "合同类型创建时间", example = "2025-05-18 16:27:08")
    @JsonFormat(pattern = "yyyy-MM-dd HH:mm:ss", timezone = "GMT+8")
    @JsonProperty("createTime")
    private Date createTime;

    @ApiModelProperty(value = "描述", example = "xxxxxxxzszs2")
    @JsonProperty("remark")
    private String remark;

    @ApiModelProperty(value = "合同类型名", example = "zszs")
    @NotBlank(message = "合同类型名不能为空")
    @JsonProperty("typeName")
    private String typeName;
}
