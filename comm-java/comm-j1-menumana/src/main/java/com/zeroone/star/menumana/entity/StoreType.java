package com.zeroone.star.menumana.entity;

import com.baomidou.mybatisplus.annotation.TableField;
import com.baomidou.mybatisplus.annotation.TableName;
import lombok.Data;

import java.io.Serializable;

/**
 * \* @author cv
 * \* Time: 2025/5/29 + 0:01
 * \* Description:
 * \
 */

@Data
@TableName("store_type")
public class StoreType implements Serializable {
    /*
    * 权限域 ：p_privilege的domain
    * */
    @TableField("store_type_cd")
    private String storeTypeCd;
    /*
    * 商户名称
    * */
    private String name;

}
