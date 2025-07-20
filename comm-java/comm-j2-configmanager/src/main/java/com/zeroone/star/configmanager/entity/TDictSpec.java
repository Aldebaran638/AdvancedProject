package com.zeroone.star.configmanager.entity;

import com.baomidou.mybatisplus.annotation.FieldFill;
import com.baomidou.mybatisplus.annotation.TableField;
import com.baomidou.mybatisplus.annotation.TableId;
import com.baomidou.mybatisplus.annotation.TableName;
import lombok.Getter;
import lombok.Setter;

import java.io.Serializable;

@Getter
@Setter
@TableName("t_dict_spec")
public class TDictSpec implements Serializable {
    //规格ID
    @TableId(value = "specId")
    private String specId;

    //规格名称
    private String specName;

    //表名称
    private String tableName;

    //类名称
    private String tableColumns;

    //创建时间
    @TableField(fill = FieldFill.INSERT)
    private String createTime;

    //数据状态
    private String statusCd;
}
