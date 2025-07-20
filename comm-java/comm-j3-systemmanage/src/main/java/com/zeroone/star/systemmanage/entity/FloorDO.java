package com.zeroone.star.systemmanage.entity;

import com.baomidou.mybatisplus.annotation.TableName;
import lombok.Data;

import java.math.BigDecimal;
import java.time.LocalDateTime;

@Data
@TableName("f_floor")
public class FloorDO {
    private String floorId;        // 楼ID
    private String bId;            // 业务ID
    private String floorNum;       // 楼编号
    private String name;           // 小区楼名称
    private String userId;         // 用户ID
    private String remark;         // 备注
    private LocalDateTime createTime;  // 创建时间
    private String statusCd;       // 数据状态
    private String communityId;    // 小区ID
    private BigDecimal floorArea;  // 建筑面积
    private Integer seq;           // 楼栋加入排序
}
