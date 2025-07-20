package com.zeroone.star.propertymanage.service;

import com.zeroone.star.project.dto.PageDTO;
import com.zeroone.star.project.dto.j7.propertymanage.Invoicetitle.AddInvoicetitleDTO;
import com.zeroone.star.project.dto.j7.propertymanage.Invoicetitle.InvoicetitleDTO;
import com.zeroone.star.project.query.j7.propertymanage.Invoicetitle.InvoicetitleQuery;
import com.zeroone.star.project.vo.JsonVO;

/**
 * @author ermali
 * @version 1.0
 */
public interface InvoiceTitleService {


    JsonVO<PageDTO<InvoicetitleDTO>> listIncoiceTitle(InvoicetitleQuery query);

    JsonVO<String> saveInvoiceTitle(AddInvoicetitleDTO addInvoicetitleDTO);

    JsonVO<String> updateInvoiceTitle(InvoicetitleDTO invoicetitleDTO);
    /**
     * 删除发票抬头
     *
     * @param oiId 发票抬头编号
     * @return 删除结果
     */
    int  removeInvoiceTitle(String oiId);
}
