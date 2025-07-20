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
@TableName("room_renovation_detail")
public class RoomRenovationDetail implements Serializable {

    private static final long serialVersionUID = 1L;

    /**
     * 明细ID
     */
    @TableId(value = "detail_id", type = IdType.ASSIGN_ID)
    private String detailId;

    /**
     * 装修ID
     */
    private String rId;

    /**
     * 小区ID
     */
    private String communityId;

    /**
     * 明细类型,1001 验房
     */
    private String detailType;

    /**
     * 验房人ID
     */
    private String staffId;

    /**
     * 验房人
     */
    private String staffName;

    /**
     * 状态  3000 验收成功 4000验收失败 
     */
    private String state;

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
     * 验房说明
     */
    private String remark;


}
