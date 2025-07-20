package com.zeroone.star.project.vo.j5.info.communityinfo;

import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;

/**
 * <p>
 * 描述：数据管理——获取未入驻物业的小区名称列表接口 响应模型
 * </p>
 * @author yuezi
 * @version 1.0.0
 */
@ApiModel("获取未入驻物业的小区名称列表接口响应模型")
@Data
public class CommunityNameVO {
    @ApiModelProperty(value = "小区ID", example = "2023052267100146")
    private String communityId;
    @ApiModelProperty(value = "小区名称", example = "HC演示小区3")
    private String name;
}
