package com.zeroone.star.datamanager.entity;

import com.baomidou.mybatisplus.annotation.TableName;
import lombok.Getter;
import lombok.Setter;

@Getter
@Setter
@TableName("s_store_attr")
public class SStoreAttr {
    /**
     * 业务ID
     */
    private String bId;

    /**
     * 属性ID
     */
    private String attrId;

    /**
     * 物业公司ID
     */
    private String storeId;

    /**
     * 属性规格
     */
    private String specCd;

    /**
     * 属性值
     */
    private String value;

    /**
     * 创建时间
     */
    private String createTime;

    /**
     * 状态
     */
    private String statusCd;
}
