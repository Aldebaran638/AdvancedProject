package com.zeroone.star.project.j8.housemgt.committee.dto;

import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;

import javax.validation.constraints.NotBlank;

/**
 * 业委会数据传输模型
 */
@ApiModel("业委会模型")
@Data
public class CommitteeDTO extends AddCommitteeDTO {

    @ApiModelProperty(value = "业委会编号", example = "102025025155370004", required = true)
    @NotBlank(message = "业委会编号不能为空")
    private String ocId;
}
