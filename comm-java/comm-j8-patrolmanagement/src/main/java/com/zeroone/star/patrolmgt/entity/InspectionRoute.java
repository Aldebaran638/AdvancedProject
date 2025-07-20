package com.zeroone.star.patrolmgt.entity;

import com.baomidou.mybatisplus.annotation.TableId;
import com.baomidou.mybatisplus.annotation.TableName;
import lombok.AllArgsConstructor;
import lombok.Data;
import lombok.NoArgsConstructor;

import java.util.Date;

@Data
@AllArgsConstructor
@NoArgsConstructor
@TableName("inspection_route")
public class InspectionRoute {
    //线路ID
    @TableId(value = "inspection_route_id")
    private String inspection_route_id;
    //业务id
    private String b_id;
    //路线名称
    private String route_name;
    //小区id
    private String community_id;
    //巡检顺序
    private String seq;
    //备注
    private String remark;
    //创建时间
    private Date create_time;
    //数据状态
    private String status_cd;
}