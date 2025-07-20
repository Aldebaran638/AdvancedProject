package com.zeroone.star.housemgt.entity;

import com.baomidou.mybatisplus.annotation.IdType;
import com.baomidou.mybatisplus.annotation.TableId;
import com.baomidou.mybatisplus.annotation.TableName;
import lombok.Data;

import java.sql.Timestamp;

@Data
@TableName("owner_committee_contract")
public class gzx_OwnerCommitteeContact {
    @TableId(value = "contract_id", type = IdType.ASSIGN_ID) // 改为雪花算法
    private Long contractId; // 改为Long类型

    private Long ocId; // 关联字段也改为Long类型

    private String name;    // 姓名

    private String relName; // 与业委会成员的关系

    private String link;    // 联系电话

    private String address; // 地址

    private String remark;  // 备注

    private String communityId; // 小区 ID

    private Timestamp createTime;   // 创建时间

    private String statusCd;    // 状态码（0/1）
}
