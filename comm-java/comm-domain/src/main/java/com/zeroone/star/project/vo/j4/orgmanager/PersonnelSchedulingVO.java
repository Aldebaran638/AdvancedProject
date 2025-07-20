package com.zeroone.star.project.vo.j4.orgmanager;

import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;

import java.util.Date;
import java.util.Map;

@Data
@ApiModel("获取人员排班列表（条件+分页）")
public class PersonnelSchedulingVO {
    @ApiModelProperty(value = "员工ID", example = "1001")
    private String staffId;

    @ApiModelProperty(value = "员工姓名", example = "张三")
    private String staffName;

    @ApiModelProperty(value = "排班详情（日期->排班信息映射）")
    private Map<String, String> scheduleDetails;

    @ApiModelProperty(value = "日期", example = "2025-06-01")
    private Date attendanceDate;

    @ApiModelProperty(value = "排班信息", example = "白班 09:00-18:00")
    private String scheduleTime;
}
