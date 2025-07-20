package com.zeroone.star.orgmanager.entity;

import com.baomidou.mybatisplus.annotation.*;
import lombok.Data;

import java.io.Serializable;
import java.time.LocalDateTime;

@Data
@TableName("p_privilege_rel")
public class PPrivilegeRel implements Serializable {
    /**
     * 权限关系id
     */
    @TableId(type = IdType.ASSIGN_ID)
    private int relId;

    /**
     * 权限id
     */
    private String pId;

    /**
     * 权限组id
     */
    private String pgId;

    /**
     * 创建时间
     */
    @TableField(fill = FieldFill.INSERT)
    private LocalDateTime createTime;

    /**
     * 数据状态，详细参考c_status表，S 保存，0, 在用 1失效
     */
    private String statusCd;
}
