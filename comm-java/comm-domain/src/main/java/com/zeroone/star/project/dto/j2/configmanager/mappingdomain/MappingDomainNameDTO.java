package com.zeroone.star.project.dto.j2.configmanager.mappingdomain;

import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;

/**
 * <p>
 * 描述：数据传输对象
 * </p>
 * <p>版权：&copy;01星球</p>
 * <p>地址：01星球总部</p>
 * @author hubery
 * @version 1.0.0
 */
@Data
@ApiModel("配置项名称传输数据对象")
public class MappingDomainNameDTO {
    @ApiModelProperty(value = "编号",example = "464684684688")
    private String id;
    @ApiModelProperty(value = "名称",example = "系统开关")
    private String domainName;
    @ApiModelProperty(value = "描述",example = "主要用于系统图片等存储使用，请您购买阿里云OSS，获取一下参数配置，请注意前后空格，并且阿里云OSS账户授权oss存储权限")
    private String remark;
}
