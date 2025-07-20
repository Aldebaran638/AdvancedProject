package com.zeroone.star.cachemanage.entity;

import com.baomidou.mybatisplus.annotation.TableField;
import com.baomidou.mybatisplus.annotation.TableId;
import com.baomidou.mybatisplus.annotation.TableName;
import lombok.Data;

import java.sql.Timestamp;

@Data
@TableName("c_business_table_his")
public class CBusinessTableHis {
    @TableId(value="his_id")
    private String hisId;
    @TableField(value="action")
    private String action;
    @TableField(value="action_obj")
    private String actionObj;
    @TableField(value="action_obj_his")
    private String actionObjHis;
    @TableField(value="business_type_cd")
    private String businessTypeCd;
    @TableField(value="remark")
    private String remark;
    @TableField(value="create_time")
    private Timestamp createTime;
    @TableField(value="status_cd")
    private String statusCd;
}
