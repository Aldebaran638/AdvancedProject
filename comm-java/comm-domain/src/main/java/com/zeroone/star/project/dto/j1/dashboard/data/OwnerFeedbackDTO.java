package com.zeroone.star.project.dto.j1.dashboard.data;

import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.AllArgsConstructor;
import lombok.Data;
import lombok.NoArgsConstructor;

import java.time.LocalDateTime;

/**
 * 业主反馈数据传输对象
 */
@Data
@NoArgsConstructor
@AllArgsConstructor
@ApiModel("业主反馈数据传输对象")
public class OwnerFeedbackDTO {

    @ApiModelProperty(value = "用户名称", example = "张三")
    private String appraiseUserName;

    @ApiModelProperty(value = "反馈内容", example = "这里需要改进...")
    private String context;

    @ApiModelProperty(value = "创建时间", example = "2025-05-04T20:37:28")
    private LocalDateTime createTime;

    @ApiModelProperty(value = "状态描述", example = "跟进中")
    private String statusDesc;

    @ApiModelProperty(value = "状态码", example = "001")
    private String statusCd;

    @ApiModelProperty(value = "用户ID", example = "user123")
    private String appraiseUserId;
}