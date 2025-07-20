package com.zeroone.star.systemmanage.entity;

import com.baomidou.mybatisplus.annotation.TableName;
import lombok.Data;

import java.time.LocalDateTime;

@Data
@TableName("building_owner")
public class BuildingOwnerDO {
    private String memberId;        // 业主成员ID
    private String ownerId;         // 业主ID
    private String bId;             // 业务ID
    private String name;            // 业主名称
    private String sex;             // 性别
    private String age;             // 年龄
    private String link;            // 联系人手机号
    private String userId;          // 用户ID
    private String remark;          // 备注
    private LocalDateTime createTime;   // 创建时间
    private String statusCd;        // 数据状态
    private String ownerTypeCd;     // 1001 业主本人 1002 家庭成员
    private String communityId;     // 小区ID
    private String idCard;          // 身份证号码
    private String state;           // 业主成员状态 1000 表示待审核，2000 审核完成  3000 拒绝审核
    private String ownerFlag;       // 业主标识 T是真实业主 F 是虚拟业主
    private String address;         // 家庭住址
}
