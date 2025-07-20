package com.zeroone.star.orgmanager.entity;

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
 * @author youndry
 * @since 2025-05-30
 */
@Getter
@Setter
@TableName("u_role_community")
public class URoleCommunity implements Serializable {

    private static final long serialVersionUID = 1L;

    /**
     * 主键ID
     */
    @TableId(value = "rc_id", type = IdType.ASSIGN_ID)
    private String rcId;

    /**
     * 角色ID
     */
    private String roleId;

    /**
     * 小区ID
     */
    private String communityId;

    /**
     * 创建时间
     */
    @TableField(fill = FieldFill.INSERT)
    private LocalDateTime createTime;

    /**
     * 数据状态，详细参考c_status表，0在用，1失效
     */
    @TableField(fill = FieldFill.INSERT)
    private String statusCd;

    /**
     * 商户ID
     */
    @TableField(fill = FieldFill.INSERT)
    private String storeId;

    /**
     * 小区名称
     */
    private String communityName;

    @Override
    public String toString() {
        return "URoleCommunity{" +
                "rcId='" + rcId + '\'' +
                ", roleId='" + roleId + '\'' +
                ", communityId='" + communityId + '\'' +
                ", createTime=" + createTime +
                ", statusCd='" + statusCd + '\'' +
                ", storeId='" + storeId + '\'' +
                ", communityName='" + communityName + '\'' +
                '}';
    }
}
