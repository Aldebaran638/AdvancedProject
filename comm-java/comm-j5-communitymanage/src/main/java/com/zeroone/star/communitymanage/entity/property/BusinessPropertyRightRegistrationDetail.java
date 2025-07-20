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
 * @author jungle
 * @since 2025-05-29
 */
@Getter
@Setter
@TableName("business_property_right_registration_detail")
public class BusinessPropertyRightRegistrationDetail implements Serializable {

    private static final long serialVersionUID = 1L;

    /**
     * 房屋产权详情ID
     * 主键id
     */
    private String prrdId;

    /**
     * 产权登记id
     */
    private String prrId;

    /**
     * 材料类型   001身份证   002购房合同   003维修基金   004契税
     */
    private String securities;

    private String fundIsPaid;

    private String taxIsPaid;
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
     * 数据状态，添加ADD，修改MOD 删除DEL
     */
    private String operate;



    private String url;


}
