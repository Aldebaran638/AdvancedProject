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
 * @author 阿伟
 * @since 2025-05-20
 */

@Getter
@Setter
@TableName("inspection_route_point_rel")
public class yuxixia_DO implements Serializable {

    private static final long serialVersionUID = 1L;

    /**
     * inspection_route and point relation ID
     */
    @TableId
    private String irpRelId;

    /**
     * 业务ID
     */
    private String bId;

    /**
     * 路线ID
     */
    private String inspectionRouteId;

    /**
     * 巡检点ID
     */
    private String inspectionId;

    /**
     * 小区ID
     */
    private String communityId;

    /**
     * 创建时间
     */
    @TableField(fill = FieldFill.INSERT)
    private LocalDateTime createTime;

    /**
     * 数据状态
     */
    private String statusCd;

    /**
     * 巡检点开始时间
     */
    private String pointStartTime;

    /**
     * 巡检点结束时间
     */
    private String pointEndTime;

    /**
     * 排序
     */
    private Integer sortNumber;


}
