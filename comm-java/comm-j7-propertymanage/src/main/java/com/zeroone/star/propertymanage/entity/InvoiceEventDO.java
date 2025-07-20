package com.zeroone.star.propertymanage.entity;

import com.baomidou.mybatisplus.annotation.IdType;
import com.baomidou.mybatisplus.annotation.TableId;
import com.baomidou.mybatisplus.annotation.TableName;
import lombok.AllArgsConstructor;
import lombok.Builder;
import lombok.Data;
import lombok.NoArgsConstructor;

import java.util.Date;

@Data
@TableName("invoice_event")
@Builder
@AllArgsConstructor
@NoArgsConstructor
public class InvoiceEventDO {
    /**
     * ID
     */
    private String eventId;

    /**
     * 申请ID
     */
    private String applyId;

    /**
     * 类型 1001 审核成功 2002 上传 3003 审核失败 4004 领用 5005 登记
     */
    private String eventType;

    /**
     * 小区ID
     */
    private String communityId;

    /**
     * 操作人
     */
    private String createUserId;

    /**
     * 操作人
     */
    private String createUserName;

    /**
     * 备注
     */
    private String remark;

    /**
     * 创建时间
     */
    private Date createTime;

    /**
     * 数据状态，详细参考c_status表，0， 在用 1失效
     */
    private String statusCd;

}
