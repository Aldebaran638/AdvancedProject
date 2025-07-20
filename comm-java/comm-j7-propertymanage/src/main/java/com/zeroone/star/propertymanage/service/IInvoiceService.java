package com.zeroone.star.propertymanage.service;

import com.baomidou.mybatisplus.extension.service.IService;
import com.zeroone.star.propertymanage.entity.Invoice;
import org.springframework.stereotype.Service;


public interface IInvoiceService extends IService<Invoice> {
    /**
     * 审核发票
     * @param invoice 审核信息
     */
    void auditInvoice(Invoice invoice);

    /**
     * 删除发票
     * @param invoiceId 发票ID
     * @return 删除结果
     */
    void  deleteInvoice(String invoiceId);

    /**
     * 添加发票条目
     * @param invoice 发票信息
     */
    void addInvoice(Invoice invoice);
}
