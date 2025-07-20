package com.zeroone.star.project.vo.j1.menumana.menugroup;

import com.fasterxml.jackson.annotation.JsonProperty;
import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;

/**
 * <p>
 * 菜单组名称
 * </p>
 *
 * @author AMG007
 * @since 2025-05-20
 */
@ApiModel("菜单组名称")
@Data
public class MenuGroupNameVO {
    @ApiModelProperty(value = "菜单组编号", example = "800201904004")
    private String gid;
    @ApiModelProperty(value = "菜单组名称", example = "小区")
    private String name;
}
