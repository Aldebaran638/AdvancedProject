package com.zeroone.star.cachemanage.entity;

import com.baomidou.mybatisplus.annotation.TableField;
import com.baomidou.mybatisplus.annotation.TableId;
import com.baomidou.mybatisplus.annotation.TableName;
import lombok.Data;

import java.sql.Timestamp;
@Data
@TableName("c_cache")
public class CCacheDO {
    @TableId(value = "id")
    private int id;
    @TableField(value="cache_code")
    private String cacheCode;
    @TableField(value="service_code")
    private String serviceCode;
    @TableField(value="name")
    private String name;
    @TableField(value="seq")
    private int seq;
    @TableField(value="group")
    private String group;
    @TableField(value="create_time")
    private Timestamp createTime;
    @TableField(value="status_cd")
    private String statusCd;
    @TableField(value="url")
    private String url;
}
