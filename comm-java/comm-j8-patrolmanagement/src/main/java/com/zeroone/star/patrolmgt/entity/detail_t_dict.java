package com.zeroone.star.patrolmgt.entity;

import com.baomidou.mybatisplus.annotation.FieldFill;
import com.baomidou.mybatisplus.annotation.TableField;
import com.baomidou.mybatisplus.annotation.TableId;
import com.baomidou.mybatisplus.annotation.TableName;
import lombok.Getter;
import lombok.Setter;

import java.io.Serializable;
import java.time.LocalDateTime;

@Getter
@Setter
@TableName("t_dict")
public class detail_t_dict implements Serializable {

    private static final long serialVersionUID = 1L;

    @TableId("id")
    @TableField("id")
    private int id;

    @TableField("status_cd")
    private String statusCd;

    @TableField("name")
    private String name;

    @TableField("description")
    private String description;

    @TableField(fill = FieldFill.INSERT, value = "create_time")
    private LocalDateTime createTime;

    @TableField("table_name")
    private String tableName;

    @TableField("table_columns")
    private String tableColumns;
}
