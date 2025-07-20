package com.zeroone.star.project.j7.propertymanage;

import com.zeroone.star.project.dto.PageDTO;
import com.zeroone.star.project.dto.j7.propertymanage.Invoicetitle.AddInvoicetitleDTO;
import com.zeroone.star.project.dto.j7.propertymanage.Invoicetitle.InvoicetitleDTO;
import com.zeroone.star.project.query.j7.propertymanage.Invoicetitle.InvoicetitleQuery;
import com.zeroone.star.project.vo.JsonVO;

/**
 * @author neko
 * #Description：发票抬头apis
 * #Date: 2025/5/19 17:58
 */
public interface InvoiceTitleApis {

    /**
     * 发票抬头删除
     *
     * @param oiId 业主发票ID
     * @return 删除结果
     */
    JsonVO<String> removeInvoiceTitle(String oiId);
     /**
      * 分页查询发票抬头
      * @param query 查询数据对象
      * @return 查询结果
      */
     JsonVO<PageDTO<InvoicetitleDTO>> queryInvoiceTitle(InvoicetitleQuery query);

     /**
      * 添加发票抬头数据
      * @param addInvoicetitleDTO
      * @return 添加结果
      */
     JsonVO<String> addInvoiceTitle(AddInvoicetitleDTO addInvoicetitleDTO);

     /**
      * 修改发票抬头数据
      * @param invoicetitleDTO
      * @return 修改数据
      */
     JsonVO<String> modifyInvoiceTitle(InvoicetitleDTO invoicetitleDTO);
}
