package com.zeroone.star.project.query.j1.dashboard.console;

import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.AllArgsConstructor;
import lombok.Data;
import lombok.NoArgsConstructor;

import java.time.LocalDateTime;

/**
 * 业主反馈视图对象
 */
@Data
@NoArgsConstructor
@AllArgsConstructor
@ApiModel("业主反馈查询对象")
public class OwnerFeedbackQuery {

    @ApiModelProperty(value = "用户名称", example = "张三")
    private String appraiseUserName;

    @ApiModelProperty(value = "反馈内容", example = "这里需要改进...")
    private String context;

    @ApiModelProperty(value = "创建时间", example = "2025-05-04T20:37:28")
    private LocalDateTime createTime;

    @ApiModelProperty(value = "状态描述", example = "跟进中")
    private String statusDesc;
}