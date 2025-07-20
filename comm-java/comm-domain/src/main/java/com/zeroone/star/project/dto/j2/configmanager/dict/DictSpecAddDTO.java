package com.zeroone.star.project.dto.j2.configmanager.dict;


import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Getter;
import lombok.Setter;
import lombok.ToString;

import javax.validation.constraints.NotNull;
import javax.validation.constraints.Pattern;

@Getter
@Setter
@ToString
@ApiModel("字典类型数据传输对象")
public class DictSpecAddDTO {

    @ApiModelProperty(value = "字典类型名称", example = "员工岗位",required = true)
    @NotNull(message = "不能为空")
    private String specName;

    @ApiModelProperty(value = "状态,0-正常，1-停用", example = "0", required = true)
    @Pattern(regexp = "[01]", message = "状态只能是0或1")
    private String statusCd;

}
