package com.zeroone.star.reportconfiguration.entity;

import java.io.Serializable;
import java.time.LocalDateTime;

import com.baomidou.mybatisplus.annotation.*;
import lombok.Getter;
import lombok.Setter;

/**
 * <p>
 * 描述：报表组件-底部统计
 * </p>
 *
 *
 * @author Arthur
 * @version 1.0.0
 */
@Getter
@Setter
@TableName("report_custom_component_footer")
public class RCCCFooter implements Serializable{
    
    @TableId(value = "footer_id")
    private String footerId;
    
    private String componentId;
    
    private String name;
    
    private String queryModel;
    
    private String javaScript;
    
    private String componentSql;
    
    private String remark;
    
    private LocalDateTime createTime;
    
    private String statusCd;
}
