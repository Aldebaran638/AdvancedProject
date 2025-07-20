package com.zeroone.star.systemmanage.entity;

import com.baomidou.mybatisplus.annotation.IdType;
import com.baomidou.mybatisplus.annotation.TableId;
import com.baomidou.mybatisplus.annotation.TableName;
import lombok.Data;

@Data
@TableName("u_user")
public class UserDO {
    @TableId
    private Integer id;
    private String address;
    private String sex;
    private String statusCd = "0";
    private String userId;
    private String levelCd;
    private String locationCd;
    private String score;
    private String password;
    private String name;
    private String tel;
    private String email;
    private String age;
    private String bId;
}
