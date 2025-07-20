package com.zeroone.star.project.vo.j4.orgmanager;

import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;

import java.util.List;

@Data
@ApiModel("组织信息")
public class ClassOrganizationVO {
    @ApiModelProperty(value = "组织id", example = "857")
    private String orgId;
    @ApiModelProperty(value = "组织父级id", example = "857")
    private String parentOrgId;
    @ApiModelProperty(value = "组织名称", example = "运维团队")
    private String orgName;
    @ApiModelProperty(value = "该组织位于第几层", example = "1")
    private String orgLevel;
    @ApiModelProperty(value = "子节点")
    private List<ClassOrganizationVO> children;
}