package com.zeroone.star.parkmanage.entity;

import com.baomidou.mybatisplus.annotation.TableName;
import lombok.Data;
import com.baomidou.mybatisplus.annotation.FieldFill;
import com.baomidou.mybatisplus.annotation.TableField;
import java.time.LocalDateTime;

@Data
@TableName("unitem_log")
public class UnitemLog {
    /**
     * 业务Id
     */
    private String bId;
    
    /**
     * 订单ID
     */
    private String oId;
    
    /**
     * 服务名称，事务失败时回滚调用微服务名称
     */
    private String serviceName;
    
    /**
     * 回滚内容
     */
    private String operateContent;
    
    /**
     * 数据状态，详细参考c_status表
     */
    private String statusCd;
    
    /**
     * 创建时间
     */
    @TableField(fill = FieldFill.INSERT)
    private LocalDateTime createTime;
} 