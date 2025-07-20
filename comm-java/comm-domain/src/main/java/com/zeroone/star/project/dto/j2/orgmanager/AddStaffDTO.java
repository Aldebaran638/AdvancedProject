package com.zeroone.star.project.dto.j2.orgmanager;

import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;

/**
 * <p>
 * 添加关联员工数据传输模型
 * </p>
 *
 * @author wb
 * @since 2023-05-29
 */

@ApiModel(description = "添加关联员工数据传输模型")
@Data
public class AddStaffDTO{
    @ApiModelProperty(value = "数据权限ID", example = "102022092831060007", required = true)
    private String dpId;
    @ApiModelProperty(value = "员工ID数组", required = true)
    private String[] staffIds;
}
