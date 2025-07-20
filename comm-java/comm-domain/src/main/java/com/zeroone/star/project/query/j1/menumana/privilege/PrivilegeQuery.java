package com.zeroone.star.project.query.j1.menumana.privilege;

import com.zeroone.star.project.query.PageQuery;
import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;
import lombok.EqualsAndHashCode;
import lombok.Getter;
import lombok.Setter;

import javax.validation.constraints.Min;
import javax.validation.constraints.NotBlank;

/**
 * \* @author cv
 * \* Time: 2025/5/20 + 15:31
 * \* Description:
 * \
 */

@EqualsAndHashCode(callSuper = true)
@Getter
@Setter
@ApiModel("权限查询对象")
public class PrivilegeQuery extends PageQuery {
    @ApiModelProperty(value="权限ID",example = "1fse51sdv684vd4rg1s3fe5")
    private String pid;

    @ApiModelProperty(value="菜单ID",example = "700201904008",required = true)
    @NotBlank
    private String mid;

    @ApiModelProperty(value="权限名称",example = "员工信息")
    private String name;

    @Min(value = 1, message = "页码最小值为1")
    @ApiModelProperty(value = "查询页码", example = "1",required = true)
    @NotBlank
    private long pageIndex;
    @Min(value = 1, message = "条数最小值为1")
    @ApiModelProperty(value = "查询条数", example = "10",required = true)
    @NotBlank
    private long pageSize;

}
