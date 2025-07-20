package com.zeroone.star.project.dto.j2.configmanager.mappingdomain;


import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;

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
@ApiModel("配置项添加传输数据对象")
public class MappingDomainAddDTO {
    @ApiModelProperty(value = "配置项" ,example = "SYSTEM_SWITCH",required = true)
    private String domain;
    @ApiModelProperty(value = "名称" ,example = "系统开关",required = true)
    private String domainName;
    @ApiModelProperty(value = "排序" ,example = "1",required = true)
    private String seq;
    @ApiModelProperty(value = "描述" ,example = "这是一个配置项",required = true)
    private String remark;

}
