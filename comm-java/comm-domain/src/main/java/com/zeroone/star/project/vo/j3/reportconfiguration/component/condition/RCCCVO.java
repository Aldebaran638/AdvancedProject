package com.zeroone.star.project.vo.j3.reportconfiguration.component.condition;

import com.zeroone.star.project.dto.j3.reportconfiguration.component.condition.RCCCDTO;
import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.AllArgsConstructor;
import lombok.Data;
import lombok.NoArgsConstructor;

import java.io.Serializable;

/**
 * RCCC视图对象（VO）
 *
 * 该类用于向前端返回“报表自定义组件条件”的数据，作为后端数据模型的展示形式。
 * 包含条件ID、组件ID、名称、提示信息、参数、类型和描述等字段。
 * 使用 Lombok 注解生成 Getter 和 Setter 方法，提升开发效率。
 *
 * @author 丁香与醋栗
 * @version 1.0
 * @date 2025/5/19
 */
@AllArgsConstructor
@NoArgsConstructor
@Data
@ApiModel("报表自定义组件条件VO")
public class RCCCVO implements Serializable {

    private static final long serialVersionUID = 1L;
    /**
     * 条件唯一标识符
     * 用于标识每一条条件记录的唯一ID
     */
    @ApiModelProperty(value = "条件唯一标识符", example = "102021111302592101")
    private String conditionId;

    /**
     * 组件ID
     * 关联的组件唯一标识，用于区分不同组件的条件配置
     */
    @ApiModelProperty(value = "组件ID", example = "1")
    private String componentId;

    /**
     * 名称
     * 显示在前端的条件字段名或标签
     */
    @ApiModelProperty(value = "名称", example = "开始时间")
    private String name;

    /**
     * 提示文本
     * 输入框中显示的占位符说明文字
     */
    @ApiModelProperty(value = "提示文本", example = "请填写开始时间YYYY-MM-DD格式")
    private String holdpace;

    /**
     * 参数值
     * 保存条件对应的参数表达式或配置值
     */
    @ApiModelProperty(value = "参数", example = "startTime")
    private String param;

    /**
     * 条件类型
     */
    @ApiModelProperty(value = "条件类型", example = "date")
    private String type;

    /**
     * 描述信息
     * 对当前条件的详细说明，可为空
     */
    @ApiModelProperty(value = "描述信息", example = "可为空")
    private String remark;


}
