package com.zeroone.star.project.query.j4.orgmanager.employee;

import com.zeroone.star.project.query.PageQuery;
import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.AllArgsConstructor;
import lombok.Data;
import lombok.NoArgsConstructor;

/**
 * 员工信息查询数据模型
 */
@ApiModel("员工信息查询数据模型")
@Data
@AllArgsConstructor
@NoArgsConstructor
public class EmployeeQuery extends PageQuery {

    /**
     * 员工id
     */
    @ApiModelProperty(value = "员工编号", example = "302024022434513355")
    private String userID;

    /**
     * 名称
     */
    @ApiModelProperty(value = "名称", example = "贾诩")
    private String name;

    /**
     * 手机号
     */
    @ApiModelProperty(value = "手机号", example = "1311101111")
    private String tel;

    /**
     * 组织id
     */
    @ApiModelProperty(value = "组织id", example = "842019101433980004")
    private String orgId;
}
