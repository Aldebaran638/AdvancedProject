package com.zeroone.star.configmanager.entity;

import com.baomidou.mybatisplus.annotation.IdType;
import com.baomidou.mybatisplus.annotation.TableId;
import com.baomidou.mybatisplus.annotation.TableName;
import lombok.Getter;
import lombok.Setter;

import java.io.Serializable;
import java.time.LocalDateTime;

@Getter
@Setter
@TableName("t_dict")
public class TDict implements Serializable {
    private static final long serialVersionUID = 1L;
    //id
    @TableId(value = "id",type = IdType.AUTO)
    private Integer id;

    //表字段状态 取值
    private String statusCd;

    //名称
    private String name;

    //描述
    private String description;

    //创建时间
    private LocalDateTime createTime;

    //表名称
    private String tableName;

    //类名称
    private String tableColumns;
}
