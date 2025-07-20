package com.zeroone.star.housemgt.entity;

import com.baomidou.mybatisplus.annotation.TableId;
import com.baomidou.mybatisplus.annotation.TableName;
import lombok.Data;

import java.sql.Timestamp;

/**
 * DO 实体类：对应 owner_committee_contract 表
 * 实际表示“业委会紧急联系人信息”
 * 注意表名虽然是：contract，意为合同。但是为了表示准确的联系人的含义，类名写成了：Contact 联系人
 */

@Data
@TableName("owner_committee_contract")
public class ycl_OwnerCommitteeContact {

    @TableId(value = "contract_id") //明确主键绑定字段是联系人id
    private String contractId;  // 联系人 ID

    private String ocId;    // 业委会编号

    private String name;    // 姓名

    private String relName; // 与业委会成员的关系

    private String link;    // 联系电话

    private String address; // 地址

    private String remark;  // 备注

    private String communityId; // 小区 ID

    private Timestamp createTime;   // 创建时间

    private String statusCd;    // 状态码（0/1）

}
