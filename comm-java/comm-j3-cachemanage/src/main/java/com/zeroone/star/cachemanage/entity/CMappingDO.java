package com.zeroone.star.cachemanage.entity;

import com.baomidou.mybatisplus.annotation.TableField;
import com.baomidou.mybatisplus.annotation.TableId;
import com.baomidou.mybatisplus.annotation.TableName;
import lombok.Data;

import java.sql.Timestamp;

@Data
@TableName("c_mapping")
public class CMappingDO {
    @TableId(value="id")
    private int id;
    @TableField(value="domain")
    private String domain;
    @TableField(value="name")
    private String name;
    @TableField(value="key")
    private String key;
    @TableField(value="value")
    private String value;
    @TableField(value="remark")
    private String remark;
    @TableField(value="create_time")
    private Timestamp createTime;
    @TableField(value="status_cd")
    private String statusCd;
}
