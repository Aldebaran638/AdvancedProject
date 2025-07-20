package com.zeroone.star.cachemanage.entity;

import com.baomidou.mybatisplus.annotation.TableField;
import com.baomidou.mybatisplus.annotation.TableId;
import com.baomidou.mybatisplus.annotation.TableName;
import lombok.Data;

import java.sql.Timestamp;

@Data
@TableName("c_service")
public class CServiceDO {
    @TableId(value = "id")
    private int id;
    @TableField(value="service_id")
    private String serviceId;
    @TableField(value="service_code")
    private String serviceCode;
    @TableField(value="business_type_cd")
    private String businessTypeCd;
    @TableField(value="name")
    private String name;
    @TableField(value="seq")
    private int seq;
    @TableField(value="messageQueueName")
    private String messageQueueName;
    @TableField(value="is_instance")
    private String isInstance;
    @TableField(value="url")
    private String url;
    @TableField(value="method")
    private String method;
    @TableField(value="timeout")
    private int timeout;
    @TableField(value="retry_count")
    private int retryCount;
    @TableField(value="provide_app_id")
    private String provideAppId;
    @TableField(value="create_time")
    private Timestamp createTime;
    @TableField(value="status_cd")
    private String statusCd;
}