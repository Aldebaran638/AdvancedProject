package com.zeroone.star.project.dto.j1.dashboard.center;

import com.zeroone.star.project.dto.j1.menumana.commonmenu.CommonMenuDTO;
import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.AllArgsConstructor;
import lombok.Data;
import lombok.NoArgsConstructor;

@Data
@AllArgsConstructor
@NoArgsConstructor
@ApiModel("查询常用菜单")
public class CenterCommonDTO extends CommonMenuDTO {
    /**
     * 菜单链接
     */
    @ApiModelProperty(value = "菜单链接",example = "http://192.168.1.1/",required = true)
    private String url;
}
