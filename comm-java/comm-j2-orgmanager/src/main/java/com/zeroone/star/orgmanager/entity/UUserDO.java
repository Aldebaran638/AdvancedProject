package com.zeroone.star.orgmanager.entity;

import com.baomidou.mybatisplus.annotation.*;
import lombok.Data;

import java.io.Serializable;
import java.time.LocalDateTime;

/**
 * 实体类
 */
@Data
@TableName("u_user")
public class UUserDO implements Serializable {

    /**
     * id
     */
    @TableId(type = IdType.ASSIGN_ID)
    private int id;

    /**
     * 用户id
     */
    private String userId;

    /**
     * 名称
     */
    private String name;

    /**
     * 邮箱地址
     */
    private String email;

    /**
     * 现居住地址
     */
    private String address;

    /**
     * 用户密码,加密过后
     */
    private String password;

    /**
     * 用户地区，编码详见 u_location
     */
    private String locationCd;

    /**
     * 用户年龄
     */
    private int age;

    /**
     * 性别，0表示男孩 1表示女孩
     */
    private char sex;
    /**
     * 手机号
     */
    private String tel;
    /**
     * 用户级别,关联user_level
     */
    private char levelCd;
    /**
     * 业务ID
     */
    private String bId;
    /**
     * 创建时间
     */
    @TableField(fill = FieldFill.INSERT)
    private LocalDateTime createTime;

    /**
     * 数据状态，详细参考c_status表，S 保存，0, 在用 1失效
     */
    private char statusCd;

    /**
     * 评分
     */
    private String score;

    /**
     * 权限组ID
     * u_user通过user_id关联p_privilege_user
     * p_privilege_user通过p_id关联p_privilege_rel
     */
    @TableField(exist = false)
    private String pgId;
}
