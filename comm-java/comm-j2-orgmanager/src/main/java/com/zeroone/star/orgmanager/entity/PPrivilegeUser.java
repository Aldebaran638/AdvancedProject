package com.zeroone.star.orgmanager.entity;

import com.baomidou.mybatisplus.annotation.TableId;
import com.baomidou.mybatisplus.annotation.TableName;
import lombok.Data;

@Data
@TableName("p_privilege_user")
public class PPrivilegeUser {
    @TableId
    private String puId;
    private String pId;
    private String userId;
    private String statusCd;
    private String storeId;
}
