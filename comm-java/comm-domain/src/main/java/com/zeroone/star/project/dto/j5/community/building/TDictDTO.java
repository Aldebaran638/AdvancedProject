package com.zeroone.star.project.dto.j5.community.building;


import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Getter;
import lombok.Setter;
import lombok.ToString;

import javax.validation.constraints.NotBlank;

@Getter
@Setter
@ToString
@ApiModel("TDictDTO数据传输对象")
public class TDictDTO {
    @ApiModelProperty(value = "状态名称", example = "未出售")
    @NotBlank(message = "状态名称不能为空")
    String stateName;
}
