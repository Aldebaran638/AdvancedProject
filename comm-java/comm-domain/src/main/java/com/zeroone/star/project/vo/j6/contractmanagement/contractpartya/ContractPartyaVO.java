package com.zeroone.star.project.vo.j6.contractmanagement.contractpartya;

import com.fasterxml.jackson.annotation.JsonProperty;
import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;

import javax.validation.constraints.NotBlank;
import javax.validation.constraints.Pattern;

/**
 * <p>
 * 描述：合同甲方数据传输对象
 * </p>
 * @author kunge
 */
@Data
@ApiModel("合同甲方数据传输对象")
public class ContractPartyaVO {

    @ApiModelProperty(value = "合同甲方联系人名称", example = "张菲菲")
    @NotBlank(message = "合同甲方联系人名称不能为空")
    @JsonProperty("aContacts")
    private String aContacts;

    @ApiModelProperty(value = "联系人联系电话", example = "16732291923")
    @NotBlank(message = "联系人联系电话不能为空")
    @Pattern(regexp = "^1[3-9]\\d{9}$", message = "联系电话格式不正确")
    @JsonProperty("aLink")
    private String aLink;

    @ApiModelProperty(value = "合同甲方名称", example = "爱情物业公司1")
    @NotBlank(message = "合同甲方名称不能为空")
    @JsonProperty("partyA")
    private String partyA;

    @ApiModelProperty(value = "合同甲方ID", example = "282021042264940001")
    @NotBlank(message = "合同甲方ID不能为空")
    @JsonProperty("partyaId")
    private String partyaId;

    @ApiModelProperty(value = "合同甲方状态码", example = "0")
    @NotBlank(message = "合同甲方状态码不能为空")
    @JsonProperty("statusCd")
    private String statusCd;

    @ApiModelProperty(value = "合同甲方储存ID", example = "402019032924930007")
    @NotBlank(message = "合同甲方储存ID不能为空")
    @JsonProperty("storeId")
    private String storeId;
}
