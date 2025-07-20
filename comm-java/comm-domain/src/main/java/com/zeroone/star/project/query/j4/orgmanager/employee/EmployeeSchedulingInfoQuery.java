package com.zeroone.star.project.query.j4.orgmanager.employee;

import com.zeroone.star.project.query.PageQuery;
import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.AllArgsConstructor;
import lombok.Data;
import lombok.NoArgsConstructor;

/**
 * 员工排版信息查询数据模型
 */
@ApiModel("员工排版信息查询数据模型")
@Data
@AllArgsConstructor
@NoArgsConstructor
public class EmployeeSchedulingInfoQuery extends PageQuery {
    /**
     * 员工id
     */
    @ApiModelProperty(value = "员工编号", example = "302024022434513355")
    private String staffId;

    /**
     * 日期
     */
    @ApiModelProperty(value = "日期", example = "2025-8")
    private String curDate;
}
