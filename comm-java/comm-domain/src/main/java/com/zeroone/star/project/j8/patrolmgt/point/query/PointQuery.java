package com.zeroone.star.project.j8.patrolmgt.point.query;

import com.zeroone.star.project.query.PageQuery;
import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;
import lombok.EqualsAndHashCode; // 引入 EqualsAndHashCode

/**
 * <p>
 * 描述：巡检点查询数据模型
 * </p>
 * <p>版权：&copy;01星球</p>
 * <p>地址：01星球总部</p>
 *
 * @author Susu
 * @version 1.0.0
 */
@EqualsAndHashCode(callSuper = true) // 继承父类的属性，生成 equals 和 hashCode 方法时考虑父类属性
@ApiModel("巡检点查询模型")
@Data
public class PointQuery extends PageQuery {

    @ApiModelProperty(value = "巡检点ID", example = "132025051426620008")
    private String inspectionId; // 对应 inspection_point 表的 inspection_id 字段

    @ApiModelProperty(value = "巡检点名称", example = "库房")
    private String inspectionName; // 对应 inspection_point 表的 inspection_name 字段

    @ApiModelProperty(value = "巡检点类型名称", example = "环境巡检")
    private String pointTypeName; // 新增字段，用于按名称模糊查询

}
