package com.zeroone.star.communitymanage.entity.property;

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
 * @author Jungle
 * @since 2025-05-24
 */
@Getter
@Setter
@TableName("business_property_right_registration")
public class BusinessPropertyRightRegistration implements Serializable {

    private static final long serialVersionUID = 1L;

    /**
     * 主键id
     */
    private String prrId;

    private String bId;

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
     * 创建时间
     */
    @TableField(fill = FieldFill.INSERT)
    private LocalDateTime createTime;

    /**
     * 创建人
     */
    private String createUser;

    private String statusCd;

    /**
     * 数据状态，添加ADD，修改MOD 删除DEL
     */
    private String operate;

    /**
     * 审核状态  0 未审核  1 审核通过  2 审核拒绝
     */
    private String state;

    /**
     * 备注
     */
    private String remark;

    /**
     * 小区ID
     */
    private String communityId;


}
