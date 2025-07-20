package com.zeroone.star.project.dto.j4.orgmanager;
import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.*;

import javax.validation.constraints.NotBlank;

@ApiModel("添加组织")
@Data
@AllArgsConstructor
@NoArgsConstructor
public class AddOrganizationDTO {
    @ApiModelProperty(value = "组织名称", example = "三国物业", required = true)
    @NotBlank(message = "组织名称不能为空")
    private String orgname;              // 组织名称（必填）

    @ApiModelProperty(value = "上级组织", example = "物业")
    private String parentOrgId;

    @ApiModelProperty(value = "描述", example = "添加组织")
    private String description;

}
