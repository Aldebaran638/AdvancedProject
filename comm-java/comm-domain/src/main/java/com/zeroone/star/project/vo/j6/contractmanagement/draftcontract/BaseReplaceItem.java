package com.zeroone.star.project.vo.j6.contractmanagement.draftcontract;

import com.fasterxml.jackson.annotation.JsonProperty;
import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;

import java.io.Serializable;

/**
 * 基础替换字段项
 */
@Data
@ApiModel(value = "基础替换字段项")
public class BaseReplaceItem implements Serializable {

    @ApiModelProperty(value = "所属域", example = "STORE.CONTRACT")
    @JsonProperty("domain")
    private String domain;

    @ApiModelProperty(value = "ID", example = "0")
    @JsonProperty("id")
    private Long id;

    @ApiModelProperty(value = "字段键", example = "partyA")
    @JsonProperty("key")
    private String key;

    @ApiModelProperty(value = "字段名称", example = "甲方")
    @JsonProperty("name")
    private String name;

    @ApiModelProperty(value = "备注")
    @JsonProperty("remark")
    private String remark;

    @ApiModelProperty(value = "字段值", example = "partyA")
    @JsonProperty("value")
    private String value;
}
