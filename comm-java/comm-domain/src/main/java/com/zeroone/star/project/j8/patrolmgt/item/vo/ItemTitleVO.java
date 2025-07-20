package com.zeroone.star.project.j8.patrolmgt.item.vo;

import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;

import java.time.LocalDateTime;

/**
 * <p>
 *  描述: 巡检题目视图模型
 * </p>
 * @author  panzhire
 * @version 1.0.0
 */
@ApiModel("巡检题目视图模型")
@Data
public class ItemTitleVO {
    @ApiModelProperty(value = "巡检题目编号", example = "102025051235020211")
    private String titleId;
    
    @ApiModelProperty(value = "巡检题目名称", example = "空调")
    private String itemTitle;
    
    @ApiModelProperty(value = "题目类型", example = "1001")
    private String titleType;
    
    @ApiModelProperty(value = "题目顺序", example = "1")
    private String seq;
    
    @ApiModelProperty(value = "题目创建时间", example = "2025-05-12 09:16:37")
    private LocalDateTime createTime;
}
