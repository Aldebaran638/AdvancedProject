package com.zeroone.star.project.dto.j3.reportconfiguration.component;

import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;
import lombok.ToString;

import javax.validation.constraints.NotNull;
import java.time.LocalDateTime;


@ApiModel(value = "添加组件目录模型")
@Data
@ToString
public class RCCAddDTO {

    @NotNull
    @ApiModelProperty(value = "组件组",example = "组件组 C是普通组件 Q 查询条件组件",required = true)
    private String componentGroup;

    /*
     * 组件类型
     * */
    @NotNull
    @ApiModelProperty(value = "组件类型",example = "组件类型,组件组 为C时 1001 表格，2002 饼状图 等等 组件组为Q 3003 input 4004 select 5005 日期 等等",required = true)
    private String componentType;

    /*
     * 查询方式
     * */
    @ApiModelProperty(value = "查询方式",example =  "1 sql" +
            "2 java",required = true)
    private String queryModel;

    /*
     * 组件名称
     * */
    @NotNull
    @ApiModelProperty(value = "组件名称",example = "房屋入驻报表",required = true)
    private String name;


    /*
     * 描述
     * */
    @ApiModelProperty(value = "描述",example = "无")
    private String remark;

    /**
     * 创建时间
     * 记录该条数据的创建时间，默认插入时自动填充
     */
    private LocalDateTime createTime;

    /**
     * 数据状态
     * S 表示已保存，0 表示在用，1 表示失效
     */
    @NotNull
    @ApiModelProperty(value = "数据状态",example = "数据状态，详细参考c_status表，S 保存，0, 在用 1失效",required = true)
    private String statusCd;

    /**
     * 执行sql
     */
    @ApiModelProperty(value = "执行sql",example = "SELECT * FROM house_report WHERE status = 'occupied'")
    private String componentSql;

    /**
     * 执行java
     */
    @ApiModelProperty(value = "执行java",example = "HouseReportService.generateOccupancyReport()")
    private String javaScript;
}
