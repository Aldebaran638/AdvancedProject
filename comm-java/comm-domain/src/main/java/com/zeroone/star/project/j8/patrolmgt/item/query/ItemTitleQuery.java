package com.zeroone.star.project.j8.patrolmgt.item.query;

import com.zeroone.star.project.query.PageQuery;
import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;

/**
 * <p>
 *  描述: 巡检题目查询模型
 * </p>
 * @author  panzhire
 * @version 1.0.0
 */
@ApiModel("巡检题目查询模型")
@Data
public class ItemTitleQuery extends PageQuery {
    @ApiModelProperty(value = "巡检题目编号", example = "102024022154496823", required = false)
    private String titleId;
    
    @ApiModelProperty(value = "巡检题目名称", example = "地面是否干净", required = false)
    private String itemTitle;
    
    @ApiModelProperty(value = "题目类型", example = "1001", required = false)
    private String titleType;
    
    @ApiModelProperty(value = "小区编号", example = "2024022692080516", required = true)
    private String communityId;
    
    @ApiModelProperty(value = "巡检项目编号", example = "102025051235020211", required = true)
    private String itemId;
}
