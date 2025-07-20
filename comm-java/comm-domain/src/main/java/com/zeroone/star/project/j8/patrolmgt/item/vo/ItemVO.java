package com.zeroone.star.project.j8.patrolmgt.item.vo;

import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;

import java.time.LocalDateTime;

/**
 * <p>
 *  描述: 巡检项目视图模型
 * </p>
 * @author  panzhire
 * @version 1.0.0
 */
@ApiModel("巡检项目视图模型")
@Data
public class ItemVO {
    @ApiModelProperty(value = "巡检项目编号", example = "102025051235020211")
    private String itemId;
    
    @ApiModelProperty(value = "巡检项目名称", example = "空调")
    private String itemName;
    
    @ApiModelProperty(value = "项目创建时间", example = "2025-05-12 09:16:37")
    private LocalDateTime createTime;
    
    @ApiModelProperty(value = "巡检项目备注", example = "专项巡视开启与关闭")
    private String remark;
}
