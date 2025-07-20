package com.zeroone.star.parkmanage.entity;

import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.AllArgsConstructor;
import lombok.Data;
import lombok.NoArgsConstructor;

import java.io.Serializable;

@ApiModel("导入失败详情")
@Data
@AllArgsConstructor
@NoArgsConstructor
public class ImportFailureDetail implements Serializable {
    private static final long serialVersionUID = 1L;

    @ApiModelProperty(value = "行号 (从1开始)", example = "3")
    private Integer rowIndex;

    @ApiModelProperty(value = "错误信息", example = "车牌号格式不正确")
    private String errorMessage;


}