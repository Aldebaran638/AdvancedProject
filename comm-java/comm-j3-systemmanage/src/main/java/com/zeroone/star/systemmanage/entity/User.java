package com.zeroone.star.systemmanage.entity;

import com.baomidou.mybatisplus.annotation.TableName;
import lombok.Data;

import java.io.Serializable;
import java.time.LocalDateTime;

@Data
@TableName("u_user")
public class User implements Serializable {
    private Integer id;          // id
    private String userId;       // 用户ID
    private String name;         // 名称
    private String email;        // 邮箱地址
    private String address;      // 现居住地址
    private String password;     // 用户密码
    private String locationCd;   // 用户地区编码
    private Integer age;         // 用户年龄
    private String sex;          // 性别，0表示男孩 1表示女孩
    private String tel;          // 电话号码
    private String levelCd;      // 用户级别
    private String bId;          // 业务ID
    private LocalDateTime createTime;     // 创建时间
    private String statusCd;     // 数据状态
    private String score;        // 评分

}
