package com.zeroone.star.systemmanage.entity;

import com.baomidou.mybatisplus.annotation.TableName;
import lombok.Data;

import java.time.LocalDateTime;

/**
 * 停车场实体类
 */
@Data
@TableName("parking_area")
public class ParkingAreaDO {
    /**
     * 停车场ID
     */
    private String paId;

    /**
     * 业务ID
     */
    private String bId;

    /**
     * 小区ID
     */
    private String communityId;

    /**
     * 停车场编号
     */
    private String num;

    /**
     * 停车场类型，1001 地上停车场 2001 地下停车场
     */
    private String typeCd;

    /**
     * 备注
     */
    private String remark;

    /**
     * 创建时间
     */
    private LocalDateTime createTime;

    /**
     * 数据状态，详细参考c_status表，S 保存，0, 在用 1失效
     */
    private String statusCd;
}