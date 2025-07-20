package com.zeroone.star.cachemanage.entity;

import com.baomidou.mybatisplus.annotation.TableField;
import com.baomidou.mybatisplus.annotation.TableId;
import com.baomidou.mybatisplus.annotation.TableName;
import lombok.Data;

import java.sql.Timestamp;

@Data
@TableName("c_business_databus")
public class CBusinessDatabusDO {
    @TableId(value="databus_id")
    private String databusId;
    @TableField(value="databus_name")
    private String databusName;
    @TableField(value="business_type_cd")
    private String businessTypeCd;
    @TableField(value="bean_name")
    private String beanName;
    @TableField(value="seq")
    private int seq;
    @TableField(value="state")
    private String state;
    @TableField(value="create_time")
    private Timestamp createTime;
    @TableField(value="status_cd")
    private String statusCd;
}
