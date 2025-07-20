package com.zeroone.star.communitymanage.entity.renovation;

import com.baomidou.mybatisplus.annotation.*;

import java.io.Serializable;
import java.time.LocalDateTime;
import lombok.Getter;
import lombok.Setter;

/**
 * <p>
 * 房屋装修实体类
 * </p>
 *
 * @author tianganwuzao & powfu
 * @since 2025-05-23
 */
@Getter
@Setter
@TableName("room_renovation")
public class RoomRenovation implements Serializable {

    private static final long serialVersionUID = 1L;

    /**
     * 主键ID,唯一标识
     */
    @TableId(value = "r_id", type = IdType.ASSIGN_ID)
    private String rId;

    /**
     * 房屋ID
     */
    private String roomId;

    /**
     * 房屋名称
     */
    private String roomName;

    /**
     * 小区ID
     */
    private String communityId;

    /**
     * 开始时间
     */
    private LocalDateTime startTime;

    /**
     * 结束时间
     */
    private LocalDateTime endTime;

    /**
     * 联系人
     */
    private String personName;

    /**
     * 联系电话
     */
    private String personTel;

    /**
     * 创建时间
     */
    @TableField(value = "create_time", fill = FieldFill.INSERT)
    private LocalDateTime createTime;

    /**
     * 数据状态，详细参考c_status表，0, 在用 1失效
     */
    private String statusCd;

    /**
     * 状态 1000 待审核 2000 审核不通过 3000 装修中 4000 待验收 5000 验收成功 6000 验收失败 
     */
    private String state;

    /**
     * 是否违规 Y违规 N正常
     */
    private String isViolation;

    /**
     * 违规说明
     */
    private String violationDesc;

    /**
     * 备注
     */
    private String remark;

    /**
     * 审核备注
     */
    @TableField("examineRemark")
    private String examineRemark;

    /**
     * 是否延期 Y延期 N正常
     */
    private String isPostpone;

    /**
     * 延期时间
     */
    private String postponeTime;

    /**
     * 装修单位
     */
    private String renovationCompany;

    /**
     * 装修主要负责人
     */
    private String personMain;

    /**
     * 负责人联系方式
     */
    private String personMainTel;


}
