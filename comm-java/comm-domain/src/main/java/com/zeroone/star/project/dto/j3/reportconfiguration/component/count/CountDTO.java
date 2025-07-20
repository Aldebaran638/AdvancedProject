package com.zeroone.star.project.dto.j3.reportconfiguration.component.count;

import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;

import javax.validation.constraints.NotBlank;

@Data
@ApiModel("报表统计传输对象，所属表：report_custom_component_footer")
public class CountDTO extends CountAddDTO{
    @ApiModelProperty(value = "底层统计编号", example = "102025052043900004",required = true)
    @NotBlank(message = "统计编号不能为空")
    private String footerId;
    
}
