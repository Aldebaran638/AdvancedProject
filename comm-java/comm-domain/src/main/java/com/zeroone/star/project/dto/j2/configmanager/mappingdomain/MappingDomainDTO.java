package com.zeroone.star.project.dto.j2.configmanager.mappingdomain;


import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;

import javax.validation.constraints.NotBlank;

/**
 * <p>
 * 描述：添加数据传输对象
 * </p>
 * <p>版权：&copy;01星球</p>
 * <p>地址：01星球总部</p>
 * @author hubery
 * @version 1.0.0
 */
@Data
@ApiModel("配置项传输数据对象")
public class MappingDomainDTO extends MappingDomainAddDTO{
    @ApiModelProperty(value = "配置项id" ,example = "102023012925250008",required = true)
    @NotBlank(message = "id不能为空")
    private String id;
}
