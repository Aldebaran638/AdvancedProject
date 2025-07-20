package com.zeroone.star.project.dto.j2.orgmanager.rolePermission;

import com.zeroone.star.project.query.PageQuery;
import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import io.swagger.annotations.ApiParam;
import lombok.Data;

import java.util.List;


/**
 * 员工列表新增数据模型
 */
@Data
@ApiModel("员工列表新增数据模型")
public class AddEmpListDTO {
    @ApiModelProperty(value = "权限组ID",required = true)
    private String pgId;
    @ApiParam(value = "用户ID列表",required = true)
    private List<String> userIds;

}

