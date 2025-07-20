package com.zeroone.star.project.query.j4.orgmanager;

import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.*;

/**
 * <p>
 * 描述：排班查询条件数据传输对象（含分页参数）
 * </p>
 * <p>版权：&copy;01星球</p>
 * <p>地址：01星球总部</p>
 * @author 阿伟学长
 * @version 1.0.0
 */
@Data
@AllArgsConstructor
@NoArgsConstructor
@ApiModel("排班查询条件数据传输对象（含分页参数）")
public class ScheduleQuery {
    @ApiModelProperty(value = "班次名称（模糊查询）", example = "123123", notes = "支持模糊匹配，留空则不筛选")
    private String name; // 班次名称（模糊查询）

    @ApiModelProperty(value = "状态", example = "1001", notes = "可选值根据业务定义，留空则不筛选")
    private String state; // 状态

    @ApiModelProperty(value = "页码（从1开始）", example = "1", notes = "默认值1，留空时取1",required = true)
    private Integer pageIndex = 1; // 页码（当前页）

    @ApiModelProperty(value = "每页数量", example = "10", notes = "默认值10，留空时取10",required = true)
    private Integer pageSize = 10; // 每页显示数量
}