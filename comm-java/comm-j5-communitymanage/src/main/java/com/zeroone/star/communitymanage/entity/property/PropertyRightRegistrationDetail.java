package com.zeroone.star.communitymanage.entity.property;

import com.baomidou.mybatisplus.annotation.*;

import java.io.Serializable;
import java.time.LocalDateTime;

import lombok.Data;
import lombok.Getter;
import lombok.Setter;

/**
 * <p>
 * 
 * </p>
 *
 * @author Jungle
 * @since 2025-05-24
 */
@Data
@Getter
@Setter
@TableName("property_right_registration_detail")
public class PropertyRightRegistrationDetail implements Serializable {

    private static final long serialVersionUID = 1L;

    /**
     * 主键id
     */
    @TableId(value = "prrd_id", type = IdType.ASSIGN_ID)
    private String prrdId;

    /**
     * 产权登记id
     */
    private String prrId;

    /**
     * 材料类型    001身份证   002购房合同   003维修基金   004契税
     */
    private String securities;

    private String fundIsPaid;

    private String taxIsPaid;

    private String isTrue;


    /**
     * 创建时间
     */
    @TableField(fill = FieldFill.INSERT)
    private LocalDateTime createTime;

    /**
     * 创建人
     */
    private String createUser;

    /**
     * 数据状态，详细参考c_status表，0, 在用 1失效
     */
    private String statusCd;


}
