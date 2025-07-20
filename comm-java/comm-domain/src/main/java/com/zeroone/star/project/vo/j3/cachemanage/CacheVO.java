package com.zeroone.star.project.vo.j3.cachemanage;

import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;

import javax.validation.constraints.Min;
import java.io.Serializable;
@Data
@ApiModel(value="返回的缓存数据信息")
public class CacheVO implements Serializable {
    @ApiModelProperty(value="缓存ID",example = "1")
    private int id;
    @ApiModelProperty(value="缓存编码",example="1001")
    @Min(1001)
    private String cacheCode;
    @ApiModelProperty(value="前台显示名称",example = "映射缓存（c_mapping表）")
    private String name;
}
