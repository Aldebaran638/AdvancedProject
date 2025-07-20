package com.zeroone.star.patrolmgt.entity;

import com.baomidou.mybatisplus.annotation.TableId;
import com.baomidou.mybatisplus.annotation.TableName;
import lombok.AllArgsConstructor;
import lombok.Data;
import lombok.NoArgsConstructor;

import java.util.Date;
/**
 * 巡检点表
 */

@Data
@AllArgsConstructor
@NoArgsConstructor
@TableName("inspection_point")
public class zhangyvsen_InspectionPoint {
    // 巡检点ID
    @TableId(value = "inspection_id")
    private String inspectionId;

    // 业务ID
    private String bId;

    // 巡检名称
    private String inspectionName;

    // 小区ID
    private String communityId;

    // 备注说明
    private String remark;

    // 创建时间
    private Date createTime;

    // 数据状态
    private String statusCd;

    // 1001 设备巡检，2002 环境巡检
    private String pointObjType;

    // 对象ID，环境时写-1，设备时写设备ID
    private String pointObjId;

    // 对象名称
    private String pointObjName;
    //

}
