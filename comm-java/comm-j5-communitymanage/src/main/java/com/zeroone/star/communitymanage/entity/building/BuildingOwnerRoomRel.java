package com.zeroone.star.communitymanage.entity.building;

import com.baomidou.mybatisplus.annotation.FieldFill;
import com.baomidou.mybatisplus.annotation.TableField;
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
 * @author langzi
 * @since 2025-05-23
 */
@Getter
@Setter
@TableName("building_owner_room_rel")
public class BuildingOwnerRoomRel implements Serializable {

    private static final long serialVersionUID = 1L;

    /**
     * 关系ID
     */
    private String relId;

    /**
     * 业主ID
     */
    private String ownerId;

    /**
     * 房间ID
     */
    private String roomId;

    /**
     * 业务ID
     */
    private String bId;

    /**
     * 业务状态 2001 业主未迁入 2002 业主迁入 2003 业主迁出
     */
    private String state;

    /**
     * 用户ID
     */
    private String userId;

    /**
     * 备注
     */
    private String remark;

    /**
     * 创建时间
     */
    @TableField(fill = FieldFill.INSERT)
    private LocalDateTime createTime;

    /**
     * 数据状态，详细参考c_status表，0, 在用 1失效
     */
    private String statusCd;

    /**
     * 起租时间
     */
    private LocalDateTime startTime;

    /**
     * 起租时间
     */
    private LocalDateTime endTime;


}
