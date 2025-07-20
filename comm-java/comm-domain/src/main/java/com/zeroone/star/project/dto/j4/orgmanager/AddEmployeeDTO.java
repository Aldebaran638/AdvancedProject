package com.zeroone.star.project.dto.j4.orgmanager;

import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.AllArgsConstructor;
import lombok.Data;
import lombok.NoArgsConstructor;

/**
 * <p>
 * 描述：添加员工类
 * </p>
 * @author heavydrink
 * @version 1.0.0
 */
@ApiModel("添加员工类")
@Data
@AllArgsConstructor
@NoArgsConstructor
public class AddEmployeeDTO extends EmployeeBaseDTO {
    /**
     * 关联组织
     */
    @ApiModelProperty(value = "关联组织", example = "甘肃省分公司", required = true)
    private String associatedOrg;
}
