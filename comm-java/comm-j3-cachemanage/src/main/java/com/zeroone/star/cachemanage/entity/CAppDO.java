package com.zeroone.star.cachemanage.entity;

import com.baomidou.mybatisplus.annotation.TableField;
import com.baomidou.mybatisplus.annotation.TableId;
import com.baomidou.mybatisplus.annotation.TableName;
import lombok.Data;

import java.sql.Timestamp;

@Data
@TableName("c_app")
public class CAppDO {
    @TableId(value="id")
    private int id;
    @TableField(value="app_id")
    private String appId;
    @TableField(value="name")
    private String name;
    @TableField(value="security_code")
    private String securityCode;
    @TableField(value="while_list_ip")
    private String whileListIp;
    @TableField(value="black_list_ip")
    private String blackListIp;
    @TableField(value="remark")
    private String remark;
    @TableField(value="create_time")
    private Timestamp createTime;
    @TableField(value="status_cd")
    private String statusCd;
}
