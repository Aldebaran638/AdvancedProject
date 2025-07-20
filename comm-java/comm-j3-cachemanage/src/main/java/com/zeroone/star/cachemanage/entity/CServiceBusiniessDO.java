package com.zeroone.star.cachemanage.entity;

import com.baomidou.mybatisplus.annotation.TableField;
import com.baomidou.mybatisplus.annotation.TableId;
import com.baomidou.mybatisplus.annotation.TableName;
import lombok.Data;

import java.sql.Timestamp;

@Data
@TableName("c_service_business")
public class CServiceBusiniessDO {
    @TableId(value="service_business_id")
    private int serviceBusinessId;
    @TableField(value = "business_type_cd")
    private String businessTypeCd;
    @TableField(value = "invoke_type")
    private String invokeType;
    @TableField(value = "url")
    private String url;
    @TableField(value = "message_topic")
    private String messageTopic;
    @TableField(value = "timeout")
    private int timeout;
    @TableField(value = "retry_count")
    private int retryCount;
    @TableField(value = "create_time")
    private Timestamp createTime;
    @TableField(value = "status_cd")
    private String statusCd;
}
