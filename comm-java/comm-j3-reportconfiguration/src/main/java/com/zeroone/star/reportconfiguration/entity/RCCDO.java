package com.zeroone.star.reportconfiguration.entity;



import com.baomidou.mybatisplus.annotation.*;
import com.fasterxml.jackson.annotation.JsonFormat;
import lombok.Data;
import lombok.Getter;
import lombok.Setter;
import lombok.ToString;


import java.io.Serializable;
import java.time.LocalDateTime;

/**
 * 对应表 report_custom_component
 */

@Data
@TableName("report_custom_component")
@ToString
public class RCCDO implements Serializable {

    /**
     * 组件ID
     * 关联的组件唯一标识，用于区分不同组件的条件配置
     */
    @TableId(value = "component_id", type = IdType.ASSIGN_ID)
    private String componentId;

    /**
     * 报表组件名称
     */
    private String name;

    /**
     * 组件组 C是普通组件 Q 查询条件组件
     */
    private String componentGroup;

    /**
     * 组件类型,组件组 为C时 1001 表格，2002 饼状图 等等 组件组为Q 3003 input 4004 select 5005 日期 等等
     */
    private String componentType;

    /**
     * 查询方式 1、sql,2、java
     */
    private String queryModel;

    /**
     *执行java脚本代码
     */
    private String javaScript;

    /**
     *描述
     */
    private String remark;


    /**
     * 创建时间
     */
    @TableField(fill = FieldFill.INSERT)
    @JsonFormat(pattern = "yyyy-MM-dd HH:mm:ss")
    private LocalDateTime createTime;

    /**
     *数据状态，详细参考c_status表，S 保存，0, 在用 1失效
     */
    private String statusCd;

    /**
     *执行sql
     */
    private String componentSql;



}

