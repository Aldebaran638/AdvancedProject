package com.zeroone.star.menumana.entity;

import com.baomidou.mybatisplus.annotation.IdType;
import com.baomidou.mybatisplus.annotation.TableField;
import com.baomidou.mybatisplus.annotation.TableId;
import com.baomidou.mybatisplus.annotation.TableName;
import lombok.Data;

import java.time.LocalDateTime;
@Data
@TableName("m_menu_group")
public class MenuGroup {
    @TableId(value="g_id",type = IdType.ASSIGN_ID)
    private String gid;
    @TableField(value="name")
    private String name;
    @TableField(value="icon")
    private String icon;
    @TableField(value="label")
    private String label;
    @TableField(value="seq")
    private Integer seq;
    @TableField(value="description")
    private String description;
    @TableField(value="create_time")
    private LocalDateTime createTime;
    @TableField(value="status_cd")
    private String statusCd;
    @TableField(value="group_type")
    private String groupType;
    @TableField(value="store_type")
    private String storeType;
}
