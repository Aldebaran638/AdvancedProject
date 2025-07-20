package com.zeroone.star.communitymanage.entity.property;

import com.baomidou.mybatisplus.annotation.FieldFill;
import com.baomidou.mybatisplus.annotation.IdType;
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
 * @author Jungle
 * @since 2025-05-24
 */
@Getter
@Setter
@TableName("property_right_registration")
public class PropertyRightRegistration implements Serializable {

    private static final long serialVersionUID = 1L;

    @TableId(value = "prr_id", type = IdType.ASSIGN_ID)
    private String  prrId;

    /**
     * 房屋id
     */
    private String roomId;

    /**
     * 姓名
     */
    private String name;

    /**
     * 联系方式
     */
    private String link;

    /**
     * 身份证号
     */
    private String idCard;

    /**
     * 地址
     */
    private String address;

    /**
     * 审核状态  0 未审核  1 审核通过  2 审核拒绝
     */
    private String state;

    /**
     * 创建时间
     */
    @TableField(fill = FieldFill.INSERT)
    private LocalDateTime createTime;

    /**
     * 创建人
     */
    @TableField(fill = FieldFill.INSERT)
    private String createUser;

    /**
     * 数据状态，详细参考c_status表，0, 在用 1失效
     */
    private String statusCd;

    /**
     * 备注
     */
    private String remark;

    /**
     * 小区ID
     */
    private String communityId;



}
