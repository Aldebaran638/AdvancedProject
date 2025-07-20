package com.zeroone.star.project.dto.j3.cachemanage;

import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;

import java.io.Serializable;

/**
 * 根据缓存类别进行刷新
 */
@Data
@ApiModel(value = "刷新缓存数据")
public class CacheDTO implements Serializable {
    @ApiModelProperty(value="用户ID",example = "30520751775595118592",required = true)
    private String userId;
    @ApiModelProperty(value="缓存类别",example = "MAPPING",required = true)
    private String cache;
}