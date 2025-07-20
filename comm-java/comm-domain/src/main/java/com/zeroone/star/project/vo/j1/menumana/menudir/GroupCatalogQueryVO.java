package com.zeroone.star.project.vo.j1.menumana.menudir;

import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;

@ApiModel(value = "获取对应菜单组列表(条件+分页)响应参数")
@Data
public class GroupCatalogQueryVO {
    /**
     * 菜单组目录编号
     */
    @ApiModelProperty(value = "菜单组目录编号",example = "102022022662880029")
    private String gcId;
    /**
     * 商户类型编号
     */
    @ApiModelProperty(value = "菜单组编号",example = "802021031653410070")
    private String gid;
}
