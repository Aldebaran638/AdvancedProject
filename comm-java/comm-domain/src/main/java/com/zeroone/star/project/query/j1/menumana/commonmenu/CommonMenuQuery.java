package com.zeroone.star.project.query.j1.menumana.commonmenu;

import com.zeroone.star.project.query.PageQuery;
import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.AllArgsConstructor;
import lombok.Data;
import lombok.NoArgsConstructor;

@Data
@AllArgsConstructor
@NoArgsConstructor
@ApiModel("获取常用菜单模型")
public class CommonMenuQuery extends PageQuery {

    @ApiModelProperty(value = "编号",example = "102022030737501028")
    private String muId;

    @ApiModelProperty(value = "菜单名称",example = "我的小区")
    private String name;

    @ApiModelProperty(value = "列顺序",example = "1")
    private int seq;

}
