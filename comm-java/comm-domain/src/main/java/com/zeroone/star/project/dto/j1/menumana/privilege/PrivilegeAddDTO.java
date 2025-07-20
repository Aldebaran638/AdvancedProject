package com.zeroone.star.project.dto.j1.menumana.privilege;

import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;
import lombok.ToString;

import javax.validation.constraints.NotBlank;
import java.time.LocalDateTime;

/**
 * \* @author cv
 * \* Time: 2025/5/20 + 15:34
 * \* Description:
 * \
 */

@Data
@ToString
@ApiModel("添加数据传输对象")
public class PrivilegeAddDTO {
    @ApiModelProperty(value="权限名称",example = "员工信息",required=true)
    private String name;
    @ApiModelProperty(value="权限描述",example = "员工信息",required = true)
    private String description;
    @ApiModelProperty(value="资源路径",example = "/staff",required = true)
    private String resource;
    @ApiModelProperty(value="菜单商户ID",example = "700201904008",required = true)
    @NotBlank(message = "菜单Id不能为空")
    private String mid;
    @ApiModelProperty(value="商户类型ID",example = "80090000003",required = true)
    private String domain;
    @ApiModelProperty(value="商户类型名称",example = "运营团队")
    private String storeTypeName;
}
