package com.zeroone.star.patrolmgt.entity;


import com.baomidou.mybatisplus.annotation.*;
import com.fasterxml.jackson.annotation.JsonFormat;
import lombok.Data;

import java.io.Serializable;
import java.time.LocalDateTime;
import java.util.Date;

/**
 * 巡检路线对象 inspection_route
 * 
 * @author NiuJiaXu
 * @date 2025-05-24
 */
@Data
@TableName("inspection_route")
public class NiuJiaXu_InspectionRoute implements Serializable {
    private static final long serialVersionUID = 1L;

    /** Route_ID */
    @TableId(value = "inspection_route_id",type = IdType.ASSIGN_ID)
    private String inspectionRouteId;

    /** 业务ID */
    private String bId;

    /** 路线名称 */
    private String routeName;

    /** 小区ID */
    private String communityId;

    /** 路线顺序 */
    private String seq;

    /** 备注说明 */
    private String remark;

    /** 创建时间 */
    @JsonFormat(pattern = "yyyy-MM-dd HH:mm:ss")
    //@TableField(fill = FieldFill.INSERT)
    //不用写，数据库设置有默认值，因为这个插入的时候会获取用户信息，没有的话会报错，所以不用了
    private LocalDateTime createTime;

    /** 数据状态 */
    private String statusCd;

}
