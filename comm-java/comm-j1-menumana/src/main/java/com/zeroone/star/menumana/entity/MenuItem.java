package com.zeroone.star.menumana.entity;

import com.baomidou.mybatisplus.annotation.*;
import lombok.Data;
import lombok.Getter;
import lombok.Setter;

import java.io.Serializable;
import java.util.Date;

@Data
@TableName("m_menu")
public class MenuItem implements Serializable {

    private static final long serialVersionUID = 1L;

    @TableId(value = "m_id",type = IdType.ASSIGN_ID)
    private String mid;

    private String name;
    @TableField("g_id")
    private String gid;

    private String url;

    private Integer seq;
    @TableField("p_id")
    private String pid;

    private String description;
    @TableField(value = "create_time",fill = FieldFill.INSERT)
    private Date createTime;
    @TableField("status_cd")
    private String statusCd;
    @TableField("is_show")
    private String isShow;
}
