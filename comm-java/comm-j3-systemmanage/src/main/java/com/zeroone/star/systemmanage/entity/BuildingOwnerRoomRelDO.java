package com.zeroone.star.systemmanage.entity;

import com.baomidou.mybatisplus.annotation.TableName;
import lombok.Data;

import java.time.LocalDateTime;

@Data
@TableName("building_owner_room_rel")
public class BuildingOwnerRoomRelDO {
    private String relId;           // 关系ID
    private String ownerId;         // 业主ID
    private String roomId;          // 房间ID
    private String bId;             // 业务ID
    private String state;           // 业务状态 2001 业主未迁入 2002 业主迁入 2003 业主迁出
    private String userId;          // 用户ID
    private String remark;          // 备注
    private LocalDateTime createTime;   // 创建时间
    private String statusCd;        // 数据状态
    private LocalDateTime startTime;    // 起租时间
    private LocalDateTime endTime;      // 起租时间
}
