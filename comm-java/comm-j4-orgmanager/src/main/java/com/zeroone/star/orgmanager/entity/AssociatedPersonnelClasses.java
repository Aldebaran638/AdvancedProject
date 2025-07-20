package com.zeroone.star.orgmanager.entity;

import com.baomidou.mybatisplus.annotation.TableName;
import lombok.AllArgsConstructor;
import lombok.Data;
import lombok.NoArgsConstructor;

import java.util.Date;
@Data
@AllArgsConstructor
@NoArgsConstructor
@TableName("attendance_classes_staff")
public class AssociatedPersonnelClasses{
    // 排班员工ID（主键）
    private String scsId;
    // 班次ID
    private String scheduleId;
    // 员工ID
    private String staffId;
    // 员工姓名
    private String staffName;
    // 商户ID（组织信息）
    private String storeId;
    // 创建时间
    private Date createTime;
    // 状态（0-无效，1-有效）
    private Integer statusCd;
}
