package com.zeroone.star.reportconfiguration.entity;

import com.baomidou.mybatisplus.annotation.*;

import java.io.Serializable;
import java.time.LocalDateTime;

import io.swagger.annotations.ApiModelProperty;
import lombok.Getter;
import lombok.Setter;

/**
 * <p>
 * 
 * </p>
 *
 * @author 丁香与醋栗
 * @since 2025-06-10
 */
@Getter
@Setter
@TableName("report_custom_component_condition")
public class ReportCustomComponentCondition implements Serializable {

    private static final long serialVersionUID = 1L;
    /**
     * 条件唯一标识符
     * 用于标识每一条条件记录的唯一ID
     */
    @ApiModelProperty(value = "条件唯一标识符", example = "102021111302592101")
    @TableId(value = "condition_id", type = IdType.ASSIGN_ID)
    private String conditionId;
    /**
     * 组件ID
     * 关联的组件唯一标识，用于区分不同组件的条件配置
     * 默认1
     */
    @ApiModelProperty(value = "序号", example = "102023070480690007")
    private String componentId;

    /**
     * 条件名称
     * 显示在前端的条件字段名或标签
     */
    @ApiModelProperty(value = "条件名称", example = "开始时间")
    private String name;

    /**
     * 提示文本
     * 输入框中显示的占位符说明文字
     */
    @ApiModelProperty(value = "提示文本", example = "请输入开始时间YYYY-MM-DD格式")
    private String holdpace;

    /**
     * 参数值
     * 保存条件对应的参数表达式或配置值
     */
    @ApiModelProperty(value = "参数值", example = "startTime")
    private String param;

    /**
     * 条件类型
     * 如 input 输入框、select 下拉选择等，用于控制前端渲染方式
     */
    @ApiModelProperty(value = "类型", example = "日期")
    private String type;

    /**
     * 描述信息
     * 对当前条件的详细说明，可为空
     */
    @ApiModelProperty(value = "描述信息", example = "用于筛选特定用户的数据")
    private String remark;

    /**
     * 创建时间
     * 记录该条数据的创建时间
     */
    @TableField(fill = FieldFill.INSERT)
    @ApiModelProperty(value = "创建时间", example = "2025-05-19T10:00:00")
    private LocalDateTime createTime;


    /**
     * 数据状态，详细参考c_status表，S 保存，0, 在用 1失效
     */
    private String statusCd;

    /**
     * 排序字段
     * 控制前端展示顺序，默认值为1，
     */
    @ApiModelProperty(value = "排序字段", example = "1")
    private Integer seq = 1;









}
