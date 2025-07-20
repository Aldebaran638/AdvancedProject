package com.zeroone.star.housemgt.entity;

import com.baomidou.mybatisplus.annotation.IdType;
import com.baomidou.mybatisplus.annotation.TableId;
import com.baomidou.mybatisplus.annotation.TableName;
import lombok.Data;

import java.sql.Timestamp;

/**
 * DO 实体类：对应数据库表 owner_committee
 * 实际表示业委会成员信息
 */
@Data
@TableName("owner_committee")
public class ycl_OwnerCommittee {

    @TableId(value = "oc_id",type = IdType.ASSIGN_ID) // 主键：编号,用雪花ID
    private String ocId;

    private String name;

    private String sex;

    private String link;

    private String idCard;

    private String address;

    private String position;

    private String post;

    private String postDesc;

    private String appointTime;

    private String curTime;

    private String state;         // 状态（1000=在职，2000=离职）

    private String remark;

    private String communityId;

    private Timestamp createTime;

    private String statusCd;      // 数据状态（0=在用，1=失效）
}
