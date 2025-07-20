package com.zeroone.star.systemmanage.entity;

import com.baomidou.mybatisplus.annotation.*;
import lombok.Data;

import java.io.Serializable;
import java.math.BigDecimal;
import java.time.LocalDateTime;

@Data
@TableName("s_community")
public class SCommunityDO implements Serializable {
    private static final long serialVersionUID = 1L;

    @TableId(value = "community_id", type = IdType.ASSIGN_ID)
    private String communityId;
    private String bId;
    private String name;
    private String address;
    private String nearbyLandmarks;
    private String cityCode;
    private String mapX;
    private String mapY;
    @TableField(fill = FieldFill.INSERT)
    private LocalDateTime createTime;
    private String statusCd;
    private String state;
    private BigDecimal communityArea;
    private String tel;
    private Long payFeeMonth;
    private BigDecimal feePrice;
    private String qrCode;
}
