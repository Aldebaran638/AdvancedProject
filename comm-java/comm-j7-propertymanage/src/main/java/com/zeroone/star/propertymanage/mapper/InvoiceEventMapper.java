package com.zeroone.star.propertymanage.mapper;

import com.zeroone.star.propertymanage.entity.InvoiceEventDO;
import org.apache.ibatis.annotations.Mapper;

@Mapper
public interface InvoiceEventMapper {

    /**
     * 保存发票事件记录
     * @param invoiceEventDO 包含事件信息
     * @return 插入的行数
     */
    int saveInvoiceEvent(InvoiceEventDO invoiceEventDO);
}
