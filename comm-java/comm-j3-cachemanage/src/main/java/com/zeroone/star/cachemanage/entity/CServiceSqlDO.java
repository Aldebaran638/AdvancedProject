package com.zeroone.star.cachemanage.entity;

import com.baomidou.mybatisplus.annotation.TableField;
import com.baomidou.mybatisplus.annotation.TableId;
import com.baomidou.mybatisplus.annotation.TableName;
import lombok.Data;

import java.sql.Timestamp;

@Data
@TableName("c_service_sql")
public class CServiceSqlDO {
    @TableId(value="id")
    private int id;
    @TableField(value="service_code")
    private String serviceCode;
    @TableField(value="name")
    private String name;
    @TableField(value="params")
    private String params;
    @TableField(value="query_model")
    private String queryModel;
    @TableField(value="sql")
    private String sql;
    @TableField(value="proc")
    private String proc;
    @TableField(value="java_script")
    private String javaScript;
    @TableField(value="template")
    private String template;
    @TableField(value="remark")
    private String remark;
    @TableField(value="create_time")
    private Timestamp createTime;
    @TableField(value="status_cd")
    private String statusCd;
}
