package com.zeroone.star.cachemanage.entity;

import com.baomidou.mybatisplus.annotation.TableField;
import com.baomidou.mybatisplus.annotation.TableId;
import com.baomidou.mybatisplus.annotation.TableName;
import lombok.Data;

import java.sql.Timestamp;

@Data
@TableName("c_route")
public class CRouteDO {
    @TableId(value = "id")
    private int id;
    @TableField(value="app_id")
    private String appId;
    @TableField(value="service_id")
    private String serviceId;
    @TableField(value="order_type_cd")
    private String orderTypeCd;
    @TableField(value="invoke_limit_times")
    private String invokeLimitTimes;
    @TableField(value="invoke_model")
    private String invokeModel;
    @TableField(value="create_time")
    private Timestamp createTime;
    @TableField(value="status_cd")
    private String statusCd;
}
