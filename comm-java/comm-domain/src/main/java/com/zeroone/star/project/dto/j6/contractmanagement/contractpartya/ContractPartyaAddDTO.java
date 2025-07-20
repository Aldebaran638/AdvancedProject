package com.zeroone.star.project.dto.j6.contractmanagement.contractpartya;

import com.fasterxml.jackson.annotation.JsonProperty;
import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Getter;
import lombok.Setter;
import lombok.ToString;

import javax.validation.constraints.NotBlank;
import javax.validation.constraints.Pattern;

/**
 * <p>
 * 描述：添加合同甲方数据传输对象
 * </p>
 */
@Getter
@Setter
@ToString
@ApiModel("添加合同甲方数据传输对象")
public class ContractPartyaAddDTO {

    @ApiModelProperty(value = "合同甲方名称", example = "爱情物业公司1")
    @NotBlank(message = "合同甲方名称不能为空")
    @JsonProperty("partyA")
    private String partyA;

    @ApiModelProperty(value = "合同甲方联系人名称", example = "张菲菲")
    @NotBlank(message = "联系人名称不能为空")
    @JsonProperty("aContacts")
    private String aContacts;

    @ApiModelProperty(value = "合同甲方联系人联系电话", example = "18909711443")
    @NotBlank(message = "联系电话不能为空")
    @Pattern(regexp = "^1[3-9]\\d{9}$", message = "联系电话格式不正确")
    @JsonProperty("aLink")
    private String aLink;

    @ApiModelProperty(value = "商户ID", example = "18909711443")
    @JsonProperty("storeId")
    private String storeId;

    @ApiModelProperty(value = "甲方ID", example = "3339711443")
    @JsonProperty("partyaId")
    private String partyaId;

}
