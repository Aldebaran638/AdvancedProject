package com.zeroone.star.project.query.j4.orgmanager;

import com.zeroone.star.project.query.PageQuery;
import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;

@Data
@ApiModel("获取人员排班列表（条件+分页）")
public class PersonnelScheduleQuery extends PageQuery {

    @ApiModelProperty(value = "姓名", example = "李四")
    private String name;

    @ApiModelProperty(value = "班次名称", example = "早班")
    private String shiftName;

    @ApiModelProperty(value = "查询年份", example = "2025")
    private Integer year;

    @ApiModelProperty(value = "查询月份", example = "6")
    private Integer month;
}
