package com.zeroone.star.patrolmgt.entity;

import com.baomidou.mybatisplus.annotation.TableId;
import com.baomidou.mybatisplus.annotation.TableName;
import lombok.AllArgsConstructor;
import lombok.Data;
import lombok.NoArgsConstructor;

import java.util.Date;
/**
 * 巡检路线巡检点关联表
 */


@Data
@AllArgsConstructor
@NoArgsConstructor
@TableName("inspection_route_point_rel")
public class zhangyvsen_InspectionRoutePointRel {
    //巡检路线和巡检点公用ID
    @TableId(value = "irp_rel_id")
    private String irpRelId;

    // 业务ID
    private String bId;

    // 路线ID
    private String inspectionRouteId;

    // 巡检点ID
    private String inspectionId;

    // 小区ID
    private String communityId;

    // 创建时间
    private Date createTime;

    // 数据状态
    private String statusCd;

    // 巡检点开始时间
    private Date pointStartTime;

    // 巡检点结束时间
    private Date pointEndTime;


}
