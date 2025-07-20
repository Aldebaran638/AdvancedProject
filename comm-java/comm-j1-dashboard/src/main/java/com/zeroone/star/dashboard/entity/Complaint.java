package com.zeroone.star.dashboard.entity;

import com.baomidou.mybatisplus.annotation.*;
import java.io.Serializable;
import java.time.LocalDateTime;
import lombok.Getter;
import lombok.Setter;

/**
 * <p>
 * 
 * </p>
 *
 * @author fayff
 * @since 2025-05-21
 */
@Getter
@Setter
@TableName("complaint")
public class Complaint implements Serializable {

    private static final long serialVersionUID = 1L;

    /**
     * 投诉ID
     */
    @TableId(value = "complaint_id", type = IdType.ASSIGN_ID)
    private String complaintId;

    /**
     * 投诉人
     */
    @TableField("complaint_name")
    private String complaintName;

    /**
     * 投诉类型，见t_dict表
     */
    @TableField("type_cd")
    private String typeCd;

    /**
     * 小区ID
     */
    @TableField("community_id")
    private String communityId;

    /**
     * 物业公司ID
     */
    @TableField("store_id")
    private String storeId;

    /**
     * 业主ID
     */
    @TableField("owner_id")
    private String ownerId;

    /**
     * 业主名称
     */
    @TableField("owner_name")
    private String ownerName;

    /**
     * 房屋ID
     */
    @TableField("room_id")
    private String roomId;

    /**
     * 房间名称
     */
    @TableField("room_name")
    private String roomName;

    /**
     * 投诉人联系方式
     */
    @TableField("tel")
    private String tel;

    /**
     * 投诉内容
     */
    @TableField("context")
    private String context;

    /**
     * 投诉处理状态，见 t_dict表
     */
    @TableField("state")
    private String state;

    /**
     * 投诉人ID
     */
    @TableField("start_user_id")
    private String startUserId;

    /**
     * 创建时间
     */
    @TableField(value = "create_time", fill = FieldFill.INSERT)
    private LocalDateTime createTime;

    /**
     * 数据状态，详细参考t_dict表，0, 在用 1失效
     */
    @TableField("status_cd")
    private String statusCd;
}
