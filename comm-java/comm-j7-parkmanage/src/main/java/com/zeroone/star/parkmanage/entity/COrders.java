package com.zeroone.star.parkmanage.entity;

import com.baomidou.mybatisplus.annotation.TableId;
import com.baomidou.mybatisplus.annotation.TableName;
import lombok.Data;
import com.baomidou.mybatisplus.annotation.FieldFill;
import com.baomidou.mybatisplus.annotation.TableField;
import java.time.LocalDateTime;
import java.time.LocalDate;

@Data
@TableName("c_orders")
public class COrders {
    @TableId
    private String orderId;
    private String bId;
    private String appId;
    private String extTransactionId;
    private String userId;
    private String requestTime;
    private String orderTypeCd;
    private String statusCd;
    private String communityId;
    private String remark;
    @TableField(fill = FieldFill.INSERT)
    private LocalDateTime createTime;
    @TableField(fill = FieldFill.INSERT_UPDATE)
    private LocalDateTime updateTime;
    private LocalDate finishTime;
} 