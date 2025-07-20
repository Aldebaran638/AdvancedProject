package com.zeroone.star.propertymanage.mapper;

import com.zeroone.star.project.dto.j7.propertymanage.Invoicetitle.InvoicetitleDTO;
import com.zeroone.star.project.query.j7.propertymanage.Invoicetitle.InvoicetitleQuery;
import com.zeroone.star.propertymanage.entity.InvoiceTitle;
import org.apache.ibatis.annotations.Mapper;
import org.apache.ibatis.annotations.Param;

import java.util.List;

/**
 * @author 任彦屹
 * @version 1.0
 */

@Mapper
public interface InvoiceTitleMapper {
    /**
     * 删除发票抬头
     * @param oiId 编号
     * @return
     */
    int deleteInvoiceTitle(@Param("oiId") String oiId);

    List<InvoicetitleDTO> selectInvoiceTitle(InvoicetitleQuery query);

    InvoiceTitle selectBuildingOwner(String ownerId);

    void insertInvoiceTitle(InvoiceTitle invoiceTitle);

    void updateInvoiceTitle(InvoicetitleDTO invoicetitleDTO);
}
