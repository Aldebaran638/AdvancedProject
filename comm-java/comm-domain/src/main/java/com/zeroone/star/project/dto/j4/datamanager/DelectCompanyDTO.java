package com.zeroone.star.project.dto.j4.datamanager;

import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;

import java.util.List;

/**
 * 删除物业公司
 * @author: 叶落孤城
 */
@ApiModel("删除物业公司")
@Data
public class DelectCompanyDTO {

    @ApiModelProperty(value = "公司名称")
    private String corporation;

    @ApiModelProperty(value = "用户名称")
    private String name;

    @ApiModelProperty(value = "状态")
    private String state;

    @ApiModelProperty(value = "物业公司ID")
    private String storeId;

    @ApiModelProperty(value = "用户ID")
    private String userId;
}
