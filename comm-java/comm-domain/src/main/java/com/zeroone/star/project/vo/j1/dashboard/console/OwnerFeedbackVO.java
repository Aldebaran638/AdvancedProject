package com.zeroone.star.project.vo.j1.dashboard.console;

import com.fasterxml.jackson.annotation.JsonFormat;
import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.AllArgsConstructor;
import lombok.Builder;
import lombok.Data;
import lombok.NoArgsConstructor;

import java.time.LocalDateTime;

/**
 * 业主反馈视图对象
 */
@Data
@NoArgsConstructor
@AllArgsConstructor
@Builder
@ApiModel("业主反馈视图对象")
public class OwnerFeedbackVO {

    @ApiModelProperty(value = "用户名称", example = "张三")
    private String objName;

    @ApiModelProperty(value = "反馈内容", example = "这里需要改进...")
    private String title;

    @ApiModelProperty(value = "创建时间", example = "2025-05-04T20:37:28")
    @JsonFormat(pattern = "yyyy-MM-dd HH:mm:ss")
    private String createTime;


    @ApiModelProperty(value = "状态描述", example = "跟进中")
    private String state;


    @ApiModelProperty(value = "房屋编号", example = "752022082030880010")
    private String roomName;
}