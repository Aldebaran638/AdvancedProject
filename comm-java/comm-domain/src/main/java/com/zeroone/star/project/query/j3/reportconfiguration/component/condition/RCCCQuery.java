package com.zeroone.star.project.query.j3.reportconfiguration.component.condition;

import com.zeroone.star.project.query.PageQuery;
import io.swagger.annotations.ApiModelProperty;
import lombok.AllArgsConstructor;
import lombok.Data;
import lombok.NoArgsConstructor;
import org.hibernate.validator.constraints.Length;

import javax.validation.constraints.NotBlank;

/**
 * RCCC查询条件数据对象
 *
 * 该类用于接收前端传递的查询参数，主要用于分页和排序控制。
 * 目前仅包含分页参数（pageNum, pageSize）和排序字段 seq，
 * 后续可根据实际业务需求扩展更多查询条件。
 *
 * @author 丁香与醋栗
 * @version 1.0
 * @date 2025/5/19
 */

@Data
@AllArgsConstructor
public class RCCCQuery extends PageQuery {

//用于拓展

    /**
     * 组件ID
     * 关联的组件唯一标识，用于区分不同组件的条件配置
     */
    @NotBlank(message = "组件名称不能为空")
    //@Length(min=18,max = 18,message = "组件ID长度为18位")
    @ApiModelProperty(value = "组件ID", example = "102023070480690007",required = true)
    private String componentId;

    @ApiModelProperty(value = "排序字段,默认为1", example = "1",required = true)
    private Integer seq = 1;
}
