package com.zeroone.star.project.dto.j2.configmanager.sys.dictionary;

import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Getter;
import lombok.Setter;
import lombok.ToString;

@Getter
@Setter
@ToString
@ApiModel("修改菜单目录模型")
public class ModifyTDictDTO{
    //id
    @ApiModelProperty(value = "字典编号", example = "1")
    private Integer id;
    //类型
    @ApiModelProperty(value = "字典类型对应编号", example = "6")
    private String specId;
    //名称
    @ApiModelProperty(value = "名称", example = "商务拜访",
            required = false)
    private String name;
    //值
    @ApiModelProperty(value = "值", example = "3",
            required = false)
    private String statusCd;
    //描述
    @ApiModelProperty(value = "描述", example = "上门服务",
            required = false)
    private String description;
}
