package com.zeroone.star.systemmanage.entity;

import com.baomidou.mybatisplus.annotation.TableName;
import lombok.Data;

import java.math.BigDecimal;
import java.time.LocalDateTime;

@Data
@TableName("building_unit")
public class BuildingUnitDO {
    private String unitId;         // 单元ID
    private String bId;            // 业务ID
    private String unitNum;        // 单元编号
    private String floorId;        // 楼ID
    private Integer layerCount;    // 总层数
    private String lift;           // 是否有电梯 1010有 2020 无
    private String userId;         // 用户ID
    private String remark;         // 备注
    private LocalDateTime createTime;  // 创建时间
    private String statusCd;       // 数据状态
    private BigDecimal unitArea;   // 单元面积
}
