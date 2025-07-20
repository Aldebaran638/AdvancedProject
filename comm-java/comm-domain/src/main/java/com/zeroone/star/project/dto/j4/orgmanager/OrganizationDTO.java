package com.zeroone.star.project.dto.j4.orgmanager;

import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.AllArgsConstructor;
import lombok.Data;
import lombok.NoArgsConstructor;

@ApiModel("组织信息")
@Data
@AllArgsConstructor
@NoArgsConstructor
public class OrganizationDTO {

    @ApiModelProperty(value = "组织id", example = "102022113014730026")
    private String orgId;

    @ApiModelProperty(value = "组织名称", example = "三国物业")
    private String orgName;
}
