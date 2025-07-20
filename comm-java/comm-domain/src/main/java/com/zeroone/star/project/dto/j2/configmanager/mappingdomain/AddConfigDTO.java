package com.zeroone.star.project.dto.j2.configmanager.mappingdomain;

import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;

/**
 * <p>
 * 描述：添加配置项模型
 * </p>
 * <p>版权：&copy;01星球</p>
 * <p>地址：01星球总部</p>
 * @author Laceration
 * @version 1.0.0
 */
@ApiModel("添加配置项模型")
@Data
public class AddConfigDTO {
    @ApiModelProperty(value = "名称", example = "阿里云OSS", required = true)
    private String domainName;
    @ApiModelProperty(value = "配置项", example = "OSS", required = true)
    private String domain;
    @ApiModelProperty(value = "排序", example = "11", required = true)
    private Integer seq;
    @ApiModelProperty(value = "描述", example = "主要用于系统图片等存储使用", required = true)
    private String remark;
}
