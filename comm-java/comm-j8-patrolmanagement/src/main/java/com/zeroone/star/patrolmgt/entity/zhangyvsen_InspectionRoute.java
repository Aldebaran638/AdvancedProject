package com.zeroone.star.patrolmgt.entity;

import com.baomidou.mybatisplus.annotation.TableId;
import com.baomidou.mybatisplus.annotation.TableName;
import lombok.AllArgsConstructor;
import lombok.Data;
import lombok.NoArgsConstructor;

import java.util.Date;

/**
 * <p>
 * 巡检路线表
 */
@Data
@AllArgsConstructor
@NoArgsConstructor
@TableName("inspection_route")
public class zhangyvsen_InspectionRoute {
    //线路ID
    @TableId(value = "inspection_route_id")
    private String inspectionRouteId;
    //业务id
    private String bId;
    //路线名称
    private String routeName;
    //小区id
    private String communityId;
    //巡检顺序
    private String seq;
    //备注
    private String remark;
    //创建时间
    private Date createTime;
    //数据状态
    private String statusCd;
}
