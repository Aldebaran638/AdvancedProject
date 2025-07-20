package com.zeroone.star.project.dto.j5.community.property;

import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;

/**
 * <p>
 * 描述：
 * </p>
 *
 * @author Jungle
 * @version 1.0.0
 */
@ApiModel("房屋产权删除数据对象")
@Data
public class PropertyDeleteDTO {
    @ApiModelProperty(value = "产权登记Id",example = "1928681637822992384", required = true)
    String prrId;
}
