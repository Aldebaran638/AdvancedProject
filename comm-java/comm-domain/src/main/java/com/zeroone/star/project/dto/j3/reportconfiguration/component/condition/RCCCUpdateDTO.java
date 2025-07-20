package com.zeroone.star.project.dto.j3.reportconfiguration.component.condition;

import com.baomidou.mybatisplus.annotation.*;
import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Getter;
import lombok.Setter;
import org.hibernate.validator.constraints.Length;

import javax.validation.constraints.*;
import java.io.Serializable;
import java.time.LocalDateTime;

/**
 * RCCC 数据库映射对象（DO）
 *
 * 该类用于映射数据库表 `report_custom_component_condition` 的字段，
 * 表示“报表自定义组件条件”的持久化数据对象。
 * 包含条件ID、组件ID、名称、提示信息、参数、类型、描述、创建时间、状态和排序等字段。
 * 使用 Lombok 注解生成 Getter 和 Setter 方法，提升开发效率。
 * 实现 Serializable 接口以支持序列化操作。
 *
 * @author 丁香与醋栗
 * @version 1.0
 * @date 2025-05-19
 */
@Getter
@Setter
@ApiModel("报表自定义组件条件DO")
public class RCCCUpdateDTO implements Serializable {
    /**
     * 条件唯一标识符
     * 用于标识每一条条件记录的唯一ID
     */
    @NotBlank (message = "条件ID不能为空")
    @Length(min=18,max = 18,message = "条件ID长度为18位")
    @ApiModelProperty(value = "条件唯一标识符", example = "102021111302592101",required = true)
    private String conditionId;

    /**
     * 组件ID
     * 关联的组件唯一标识，用于区分不同组件的条件配置
     */
    @NotBlank (message = "组件ID不能为空")
    @Length(min=18,max = 18,message = "组件ID长度为18位")
    @ApiModelProperty(value = "序号", example = "102023070480690007",required = true)
    private String componentId;
    /**
     * 条件名称
     * 显示在前端的条件字段名或标签
     */
     @NotBlank (message = "条件名称不能为空")
    @ApiModelProperty(value = "条件名称", example = "开始时间",required = true)
    private String name;

    /**
     * 提示文本
     * 输入框中显示的占位符说明文字
     */
     @NotBlank (message = "提示文本不能为空")
     //TODO formate  校验
    @ApiModelProperty(value = "提示文本", example = "请输入开始时间YYYY-MM-DD格式",required = true)
    private String holdpace;

    /**
     * 参数值
     * 保存条件对应的参数表达式或配置值
     */
     @NotBlank (message = "参数不能为空")
    @ApiModelProperty(value = "参数值", example = "startTime",required = true)
    private String param;

    /**
     * 条件类型
     * 如 input 输入框、select 下拉选择等，用于控制前端渲染方式
     */
     @NotBlank (message = "类型不能为空")
      @Pattern(regexp = "text|date", message = "类型必须为 text 或 date")
    @ApiModelProperty(value = "类型", example = "date",required = true, allowableValues = "text,date")
    private String type;

    /**
     * 描述信息
     * 对当前条件的详细说明，可为空
     */
    @ApiModelProperty(value = "描述信息", example = "用于筛选特定用户的数据",required = false)
    private String remark;

    /**
     * 排序字段
     * 控制前端展示顺序，默认值为1，
     */
    @NotNull(message = "排序不能为空")
    //TODO　ｍｉｎ／／ｍａｘ
     @Min(0)
     @Max(1)
    @ApiModelProperty(value = "排序字段", example = "1",required = true)
    private Integer seq = 1;







}
