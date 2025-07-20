package com.zeroone.star.project.dto.j4.orgmanager;

import io.swagger.annotations.ApiModelProperty;
import javax.validation.constraints.NotBlank;
import io.swagger.annotations.ApiModel;
import lombok.*;


@ApiModel("修改组织")
@Data
@AllArgsConstructor
@NoArgsConstructor
public class ModifyOrganizationDTO {
    @ApiModelProperty(value = "组织名称", example = "成都总部", required = true)
    @NotBlank(message = "组织名称不能为空")
    private String orgname;              // 组织名称（必填）

    @ApiModelProperty(value = "上级组织", example = "运维团队")
    private String parentOrgId;

    @ApiModelProperty(value = "描述", example = "修改组织")
    private String description;

}
