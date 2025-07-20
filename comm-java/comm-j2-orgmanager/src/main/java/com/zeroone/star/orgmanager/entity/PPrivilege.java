package com.zeroone.star.orgmanager.entity;

import com.baomidou.mybatisplus.annotation.TableId;
import com.baomidou.mybatisplus.annotation.TableName;
import lombok.Data;

@Data
@TableName("p_privilege")
public class PPrivilege {
    @TableId
    private String pId;
    private String name;
    private String statusCd;
    private String createTime;
    private String mId;
}
