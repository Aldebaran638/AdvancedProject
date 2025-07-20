package com.zeroone.star.patrolmgt.entity;

import com.baomidou.mybatisplus.annotation.FieldFill;
import com.baomidou.mybatisplus.annotation.TableField;
import com.baomidou.mybatisplus.annotation.TableId;
import com.baomidou.mybatisplus.annotation.TableName;
import java.io.Serializable;
import java.time.LocalDateTime;
import lombok.Getter;
import lombok.Setter;

/**
 * <p>
 *
 * </p>
 *
 * @author yuanzijie
 * @since 2025-05-24
 */
@Getter
@Setter
@TableName("inspection_route")
public class detail_InspectionRoute implements Serializable {

    private static final long serialVersionUID = 1L;

    /**
     * Route_ID
     */
    @TableId("inspection_route_id")
    @TableField("inspection_route_id")
    private String inspectionRouteId;

    /**
     * 业务ID
     */
    @TableField("b_id")
    private String bId;

    /**
     * 路线名称
     */
    @TableField("route_name")
    private String routeName;

    /**
     * 小区ID
     */
    @TableField("community_id")
    private String communityId;

    /**
     * 路线顺序
     */
    @TableField("seq")
    private String seq;

    /**
     * 备注说明
     */
    @TableField("remark")
    private String remark;

    /**
     * 创建时间（自动填充）
     */
    @TableField(fill = FieldFill.INSERT,  value = "create_time")
    private LocalDateTime createTime;

    /**
     * 数据状态
     */
    @TableField("status_cd")
    private String statusCd;

}
