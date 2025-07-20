package com.zeroone.star.project.j8.patrolmgt.point.query;

import com.zeroone.star.project.query.PageQuery;
import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Getter;
import lombok.Setter;
import lombok.ToString;

@Getter
@Setter
@ToString(callSuper = true) //确保调用父类的toString方法
@ApiModel("可选巡检点查询参数")
public class SelectPointQuery extends PageQuery { // 继承 PageQuery

    @ApiModelProperty(value = "巡检点名称 (模糊查询)", example = "库房")
    private String inspectionName;
}