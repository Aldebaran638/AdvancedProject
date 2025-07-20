package com.zeroone.star.orgmanager.entity;

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
@TableName("business_store_user")
@AllArgsConstructor
@NoArgsConstructor
public class BusinessStoreUser {
    /**
     * 代理商用户ID
     */
    private String storeUserId;
    /**
     * '代理商ID'
     */
    private String storeId;
    /**
     * '业务Id'
     */
    private String bId;
    /**
     * '用户ID'
     */
    private String userId;
    /**
     * 用户和代理商关系 详情查看 agent_user_rel表
     */
    private String relCd;
    /**
     * '创建时间'
     */
    private LocalDateTime createTime;
    /**
     * 数据状态，添加ADD，修改MOD 删除DEL
     */
    private String operate;
}
