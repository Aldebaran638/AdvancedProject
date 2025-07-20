package com.zeroone.star.project.query.j2.configmanager;

import com.zeroone.star.project.query.PageQuery;
import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;

/**
 * <p>
 * 描述：配置项查询对象
 * </p>
 * <p>版权：&copy;01星球</p>
 * <p>地址：01星球总部</p>
 * @author hubery
 * @version 1.0.0
 */
@Data
@ApiModel("配置项查询对象")
public class MappingDomainQuery extends PageQuery {

    @ApiModelProperty(value = "配置项", example = "SYSTEM_SWITCH")
    private String domain;
    @ApiModelProperty(value = "配置项名称", example = "环境配置")
    private String domainName;

}
