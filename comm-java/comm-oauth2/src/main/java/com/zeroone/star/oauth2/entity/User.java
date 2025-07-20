package com.zeroone.star.oauth2.entity;

import com.baomidou.mybatisplus.annotation.IdType;
import com.baomidou.mybatisplus.annotation.TableId;
import com.baomidou.mybatisplus.annotation.TableName;
import com.baomidou.mybatisplus.annotation.TableField;
import lombok.Getter;
import lombok.Setter;

import java.io.Serializable;
import java.time.LocalDateTime;

/**
 * <p>
 * u_user用户表实体类
 * </p>
 *
 * @author 阿伟
 */
@Getter
@Setter
@TableName("u_user")
public class User implements Serializable {

    private static final long serialVersionUID = 1L;

    /**
     * 主键ID
     */
    @TableId(value = "id", type = IdType.AUTO)
    private Integer id;

    /**
     * 用户ID（业务ID）
     */
    @TableField("user_id")
    private String userId;

    /**
     * 用户名（对应name字段）
     */
    @TableField("name")
    private String username;

    /**
     * 邮箱地址
     */
    private String email;

    /**
     * 现居住地址
     */
    private String address;

    /**
     * 用户密码，加密过后
     */
    private String password;

    /**
     * 用户地区，编码详见 u_location
     */
    @TableField("location_cd")
    private String locationCd;

    /**
     * 用户年龄
     */
    private Integer age;

    /**
     * 性别，0表示男孩 1表示女孩
     */
    private String sex;

    /**
     * 联系电话
     */
    private String tel;

    /**
     * 用户级别,关联user_level
     */
    @TableField("level_cd")
    private String levelCd;

    /**
     * 业务ID
     */
    @TableField("b_id")
    private String bId;

    /**
     * 创建时间
     */
    @TableField("create_time")
    private LocalDateTime createTime;

    /**
     * 数据状态，详细参考c_status表，S 保存，0, 在用 1失效
     */
    @TableField("status_cd")
    private String statusCd;

    /**
     * 评分
     */
    private String score;
}
