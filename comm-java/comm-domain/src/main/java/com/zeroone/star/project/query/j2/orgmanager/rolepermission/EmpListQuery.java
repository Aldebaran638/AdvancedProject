package com.zeroone.star.project.query.j2.orgmanager.rolePermission;

import com.zeroone.star.project.query.PageQuery;
import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;

@Data
@ApiModel("员工列表数据查询模型")
public class EmpListQuery extends PageQuery {
    @ApiModelProperty(value = "员工名称")
    private String name;
    @ApiModelProperty(value = "权限组id")
    private String pgId;
    @ApiModelProperty(value = "数据状态")
    private char statusCd;
}
