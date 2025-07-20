package com.zeroone.star.orgmanager.entity;

import com.baomidou.mybatisplus.annotation.TableId;
import com.baomidou.mybatisplus.annotation.TableName;
import lombok.Data;

@Data
@TableName("m_menu_org")
public class MMenuOrg {
    @TableId
    private String mId; // 菜单ID
    private String gId;
    private String pId; // 权限ID
    private String name;
    private String url;
    private Integer seq;
    private String createTime;
    private String statusCd;
    private String isShow;
}
