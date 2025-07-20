package com.zeroone.star.project.j8.patrolmgt.item.query;

import com.zeroone.star.project.query.PageQuery;
import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;

/**
 * <p>
 *  描述: 巡检项目查询模型
 * </p>
 * @author  panzhire
 * @version 1.0.0
 */
@ApiModel("巡检项目查询模型")
@Data
public class ItemQuery extends PageQuery {
    @ApiModelProperty(value = "巡检项目编号", example = "102025051235020211", required = false)
    private String itemId;
    
    @ApiModelProperty(value = "巡检项目名称", example = "空调", required = false)
    private String itemName;
    
    @ApiModelProperty(value = "小区编号", example = "2024022692080516", required = true)
    private String communityId;
}
