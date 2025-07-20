package com.zeroone.star.communitymanage.entity.renovation;

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
 * @author tianganwuzao
 * @since 2025-05-23
 */
@Getter
@Setter
@TableName("room_renovation_record")
public class RoomRenovationRecord implements Serializable {

    private static final long serialVersionUID = 1L;

    /**
     * 装修记录id
     */
    @TableId(value = "record_id", type = IdType.ASSIGN_ID)
    private String recordId;

    /**
     * 装修id
     */
    private String rId;

    /**
     * 员工id
     */
    @TableField(fill = FieldFill.INSERT)
    private String staffId;

    /**
     * 员工姓名
     */
    @TableField(fill = FieldFill.INSERT)
    private String staffName;

    /**
     * 状态 1000 待审核 2000 审核不通过 3000 装修中 4000 待验收 5000 验收成功 6000 验收失败 
     */
    private String state;

    /**
     * 数据状态，详细参考c_status表，0, 在用 1失效
     */
    private String statusCd;

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
     * 是否违规  true 是   false 否
     */
    private String isTrue;


}
