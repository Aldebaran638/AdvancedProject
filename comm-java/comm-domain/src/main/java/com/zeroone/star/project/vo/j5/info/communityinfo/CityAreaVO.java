package com.zeroone.star.project.vo.j5.info.communityinfo;

import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;

/**
 * <p>
 * 描述：城市地名列表接口响应模型
 * </p>
 * @author yuezi
 * @version 1.0.0
 */
@ApiModel("城市地名列表接口响应模型")
@Data
public class CityAreaVO {
    @ApiModelProperty(value = "城市地名主键ID", example = "33")
    private Integer id;

    @ApiModelProperty(value = "城市编码", example = "120100")
    private String areaCode;

    @ApiModelProperty(value = "城市名称", example = "天津市")
    private String areaName;

    @ApiModelProperty(value = "城市级别（101 省级 202 市州 303 区县）", example = "202")
    private String areaLevel;

    @ApiModelProperty(value = "父级城市编码", example = "120000")
    private String parentAreaCode;

    @ApiModelProperty(value = "父级城市名称", example = "天津省")
    private String parentAreaName;
}
