package com.zeroone.star.project.dto.j4.datamanager;

import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;

/**
 * <p>
 * 限制物业登录
 * </p>
 *
 * @author 叶落孤城
 * @since 2023-05-29
 */
@ApiModel(value = "限制物业登录")
@Data
public class LimitLoginCompanyDTO {
    @ApiModelProperty(value = "物业公司id", example = "10202305221014333605000192")
    private String storeId;
    @ApiModelProperty(value = "状态", example = "S 启用，0 禁用")
    private String state;
    @ApiModelProperty(value = "物业公司名称", example = "坤坤物业")
    private String storeName;
}
