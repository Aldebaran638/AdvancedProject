package com.zeroone.star.project.dto.j5.community.property;

import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import io.swagger.annotations.ApiParam;
import lombok.Data;

/**
 * <p>
 * 描述：
 * </p>
 *
 * @author Jungle
 * @version 1.0.0
 */
@ApiModel("审核房屋产权数据对象")
@Data
public class PropertyCheckDTO {

    @ApiModelProperty(value = "产权登记Id", example = "1929925019366985728", required = true)
    private String prrId;

    @ApiModelProperty(value = "审核状态", example = "1", required = true)
    private String state;

    @ApiModelProperty(value = "备注", example = "房屋产权")
    private String remark;

    @ApiModelProperty(value = "房屋编号",example = "1001", required = true)
    private String roomNum;
}
