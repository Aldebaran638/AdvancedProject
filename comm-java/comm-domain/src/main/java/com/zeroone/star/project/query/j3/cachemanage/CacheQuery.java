package com.zeroone.star.project.query.j3.cachemanage;

import com.zeroone.star.project.query.PageQuery;
import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import io.swagger.models.auth.In;
import lombok.Data;

import javax.validation.constraints.Min;
import javax.validation.constraints.NotBlank;
import java.io.Serializable;

/**
 * 前端穿过来我们后端需要的参数
 * 查询需要分页信息和属性参数
 */
@Data
@ApiModel("获取缓存操作列表数据对象")
public class CacheQuery extends PageQuery  implements Serializable {
    @ApiModelProperty(value="缓存ID",example = "1")
    private Integer id;
    @ApiModelProperty(value="缓存编码",example="1001")
    @Min(1001)
    private String cacheCode;
    @ApiModelProperty(value="前台显示名称",example = "映射缓存（c_mapping表）")
    private String name;

}
