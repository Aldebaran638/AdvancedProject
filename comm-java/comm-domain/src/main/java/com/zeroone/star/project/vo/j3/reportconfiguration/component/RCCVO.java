package com.zeroone.star.project.vo.j3.reportconfiguration.component;

import io.swagger.annotations.ApiModelProperty;
import lombok.Data;

@Data
public class RCCVO {


    /*
     * 组件名称
     * */
    @ApiModelProperty(value = "组件名称",example = "房屋入驻报表")
    private String name;

    /*
     * 组件类型
     * */
    @ApiModelProperty(value = "组件类型",example = "表格")
    private String componentType;

    /*
      * 组件类型
      *  组件组为C 1001 表格，2002 饼状图 等等
         组件组为Q 3003 input 4004 select 5005 日期
      * */
    @ApiModelProperty(value = "组件类型",example ="表格")
    private String componentTypeText;

    /*
     * 查询方式
     * */
    @ApiModelProperty(value = "查询方式",example = "1")
    private String queryModel;

    /*
     * 描述
     * */
    @ApiModelProperty(value = "描述",example = "1")
    private String remark;

}
