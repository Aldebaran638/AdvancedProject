package com.zeroone.star.project.dto.j3.reportconfiguration.component.condition;


import com.baomidou.mybatisplus.annotation.IdType;
import java.io.Serializable;
import java.time.LocalDateTime;

import com.baomidou.mybatisplus.annotation.*;

import io.swagger.annotations.ApiModelProperty;
import lombok.Data;
import lombok.Getter;
import lombok.Setter;
import org.hibernate.validator.constraints.Length;

import javax.validation.constraints.*;

/**
 * RCCC数据传输对象（DTO）
 *
 * 该类用于前后端数据传输。
 * 名称、提示信息、参数、类型、描述、状态和排序等字段。
 * 使用 Lombok 注解生成 Getter 和 Setter 方法，提升开发效率。
 * 实现 Serializable 接口以支持序列化操作。
 *
 * @author 丁香与醋栗
 * @version 1.0
 * @date 2025-05-19
 */
@Getter
@Setter
@Data
@TableName("report_custom_component_condition")
public class RCCCDTO implements Serializable {

    @NotBlank( message = "条件名称不能为空")
    @ApiModelProperty(value = "条件名称", example = "开始时间", required = true)
    private String name;

    /**
     * 提示文本
     * 用于在输入框中显示占位提示信息
     */
     @NotBlank( message = "提示文本不能为空")
    @ApiModelProperty(value = "提示文本", example = "请填写开始时间YYYY-MM-DD格式", required = true)
    private String holdpace;

    /**
     * 参数值
     * 保存条件对应的参数表达式或配置值
     */
    @NotBlank(message = "类型不能为空")
    @ApiModelProperty(value = "参数", example = "startTime", required = true)
    private String param;

    /**
     * 条件类型
     *
     */
    @NotBlank(message = "类型不能为空")
    @Pattern(regexp = "text|date", message = "类型必须为 text 或 date")
    @ApiModelProperty(value = "类型", example = "text", required = true, allowableValues = "text,date",notes = "只接受text和date两个值")
    private String type;
    /**
     * 排序字段
     * 控制前端展示顺序
     */
    @NotNull(message = "排序不能为空")
    @Min(0)
    @Max(1)
    @ApiModelProperty(value = "排序字段", example = "1", required = true)
    private Integer seq;

    /**
     * 描述信息
     * 对当前条件的详细说明
     */
    @ApiModelProperty(value = "描述信息", example = "阿巴啊吧啊吧", required = false)
    private String remark;

    /**
     * 组件ID
     * 关联的组件唯一标识，用于区分不同组件的条件配置
     */
    @NotBlank(message = "组件ID不能为空")
    @Length(min=18,max = 18,message = "组件ID长度为18位")
    @ApiModelProperty(value = "序号", example = "102023070480690007", required = true)
    private String componentId;


}


