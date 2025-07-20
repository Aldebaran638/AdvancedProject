package com.zeroone.star.orgmanager.entity;

import com.baomidou.mybatisplus.annotation.FieldFill;
import com.baomidou.mybatisplus.annotation.TableField;
import com.baomidou.mybatisplus.annotation.TableName;
import lombok.AllArgsConstructor;
import lombok.Getter;
import lombok.NoArgsConstructor;
import lombok.Setter;

import java.time.LocalDateTime;

/**
 * <p>
 *
 * </p>
 *
 * @author heavydrink
 * @since 2025-05-21
 */
@Getter
@Setter
@TableName("s_store_user")
@AllArgsConstructor
@NoArgsConstructor
public class SStoreUser {

    private String storeUserId;

    private String storeId;

    private String bId;

    private String userId;

    private String relCd;

    @TableField(fill = FieldFill.INSERT)
    private LocalDateTime createTime;

    private String statusCd;
}
