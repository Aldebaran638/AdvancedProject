package com.zeroone.star.parkmanage.entity;

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
 * @author daimon
 * @since 2025-06-02
 */
@Getter
@Setter
@TableName("owner_app_user")
public class OwnerAppUser implements Serializable {

    private static final long serialVersionUID = 1L;

    /**
     * app用户ID
     */
    private String appUserId;

    /**
     * 业主成员ID
     */
    private String memberId;

    /**
     * 业务ID
     */
    private String bId;

    /**
     * 小区Id
     */
    private String communityId;

    /**
     * 小区名称
     */
    private String communityName;

    /**
     * app用户名称
     */
    private String appUserName;

    /**
     * 身份证号码
     */
    private String idCard;

    /**
     * 联系人手机号
     */
    private String link;

    /**
     * app 开放ID
     */
    private String openId;

    /**
     * 应用类型 10010 微信小程序
     */
    private String appTypeCd;

    /**
     * 状态类型，10000 审核中，12000 审核成功，13000 审核失败
     */
    private String state;

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
     * 数据状态，详细参考c_status表，0, 在用 1失效
     */
    private String statusCd;

    /**
     * 用户ID
     */
    private String userId;

    /**
     * 绑定业主手机端类型
     */
    private String appType;

    /**
     * 昵称
     */
    private String nickname;

    /**
     * 微信头像
     */
    private String headimgurl;

    /**
     * 认证房屋ID
     */
    private String roomId;

    /**
     * 认证房屋
     */
    private String roomName;

    /**
     * 人员类型
     */
    private String ownerTypeCd;


}
