package com.zeroone.star.propertymanage.service.impl;

import com.baomidou.mybatisplus.extension.service.impl.ServiceImpl;
import com.zeroone.star.propertymanage.entity.Invoice;
import com.zeroone.star.propertymanage.mapper.IInvoiceMapper;
import com.zeroone.star.propertymanage.service.IInvoiceService;
import org.springframework.stereotype.Service;

@Service
public class IInvoiceServiceImpl extends ServiceImpl<IInvoiceMapper, Invoice> implements IInvoiceService {

    /**
     * 审核发票
     *author : douya266
     * @param invoice 发票信息
     */
    @Override
    public void auditInvoice(Invoice invoice) {


    }

    /**
     * 删除发票
     *author : douya266
     * @param invoiceId 发票ID
     */
    public void deleteInvoice(String invoiceId) {
        Invoice invoice = getById(invoiceId);
        invoice.setStatusCd( "1");
        updateById(invoice);
    }

    public void addInvoice(Invoice invoice) {
        save(invoice);
    }

}
