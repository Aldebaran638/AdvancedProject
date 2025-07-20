package com.zeroone.star.communitymanage.entity.mycommunity;

import com.baomidou.mybatisplus.annotation.TableId;
import com.baomidou.mybatisplus.annotation.TableName;
import lombok.AllArgsConstructor;
import lombok.Data;
import lombok.NoArgsConstructor;

import java.time.LocalDateTime;

@Data
@AllArgsConstructor
@NoArgsConstructor
@TableName("u_user")
public class User {
    @TableId
    private Integer id;
    /**
     * 用户id
     */
    private String userId;
    /**
     * 用户名称
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
     * 密码
     */
    private String password;
    /**
     * 用户地区
     */
    private String locationCd;
    /**
     * 用户年龄
     */
    private Short age;
    /**
     * 用户性别
     */
    private Byte sex;
    /**
     * 电话号码
     */
    private String tel;
    /**
     * 用户级别
     */
    private String levelCd;
    /**
     * 业务id
     */
    private String bId;
    /**
     * 创建时间
     */
    private LocalDateTime createTime;
    /**
     * 数据状态
     */
    private Integer statusCd;
    /**
     * 评分
     */
    private String score;
}
