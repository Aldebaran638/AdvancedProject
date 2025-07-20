package com.zeroone.star.menumana.entity;

import com.baomidou.mybatisplus.annotation.TableName;
import lombok.*;

import java.sql.Date;

@Getter
@Setter
@TableName("m_menu_user")
public class UserMenu {
    private String muId;
    private String mId;
    private String staffId;
    private String name;
    private String icon;
    private String url;
    private String seq;
    private Date createTime;
    private String statusCd;
}
