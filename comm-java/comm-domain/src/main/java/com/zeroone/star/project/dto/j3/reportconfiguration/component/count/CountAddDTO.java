package com.zeroone.star.project.dto.j3.reportconfiguration.component.count;

import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Getter;
import lombok.Setter;
import lombok.ToString;
import org.hibernate.validator.constraints.Range;
import javax.validation.constraints.NotBlank;
import javax.validation.constraints.Pattern;

@Getter
@Setter
@ToString
@ApiModel("添加报表统计传输对象")
public class CountAddDTO {
    @ApiModelProperty(value = "当前底层统计所属的组件编号", example = "102023070480690007",required = true)
    @NotBlank(message = "组件编号不能为空")
    private String componentId;
    
    @ApiModelProperty(value = "名称", example = "报表统计测试-1",required = true)
    @NotBlank(message = "必填，请填写名称")
    private String name;
    
    @ApiModelProperty(value = "查询方式", example = "1",required = true)
    @NotBlank(message = "必填，请填写查询方式")
    @Pattern(regexp = "[sql,java]", message = "只能是sql或者java")
    private String queryModel;
    
    @ApiModelProperty(value = "描述", example = "这是一个测试...")
    private String footerDescription;
    
}
