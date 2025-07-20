package com.zeroone.star.propertymanage.mapper;

import com.baomidou.mybatisplus.core.mapper.BaseMapper;
import com.zeroone.star.project.dto.PageDTO;
import com.zeroone.star.project.dto.j7.propertymanage.invoice.*;
import com.zeroone.star.project.query.j7.propertymanage.invoice.InvoiceDetailsQuery;
import com.zeroone.star.project.query.j7.propertymanage.invoice.InvoiceQuery;
import com.zeroone.star.project.vo.JsonVO;
import com.zeroone.star.propertymanage.entity.Invoice;
import com.zeroone.star.propertymanage.entity.InvoiceItem;
import org.apache.ibatis.annotations.Mapper;
import org.apache.ibatis.annotations.Param;
import org.apache.ibatis.annotations.Update;


import java.util.List;

/**
 * @author ermali
 * @version 1.0
 */

@Mapper
public interface InvoiceMapper extends BaseMapper<Invoice> {
    /**
     * 查询发票列表
     * @param query 查询参数
     * @return 发票列表
     */
    List<QueryInvoiceDTO> selectInvoice(InvoiceQuery query);

    /**
     * 查询发票详情
     * @param applyId 申请ID
     * @param communityId 小区ID
     * @return 发票详情
     */
    Invoice selectInvoiceDetail(@Param("applyId") String applyId, @Param("communityId") String communityId);

    /**
     * 获取发票详情----开票明细
     * @param
     * @return 发票详情
     */
    List<InvoiceDetailsDTO> selectInvoiceDetails(InvoiceDetailsQuery details);

    /**
     * 获取发票详情----审核记录
     * @param
     * @return 审核记录
     */
    List<AuditRecordsDTO> selectAuditRecords(InvoiceDetailsQuery auditRecords);

    /**
     * 添加发票条目
     * @param invoiceItem
     */
    void insertInvoiceItem(InvoiceItem invoiceItem);

    /**
     * 删除发票条目
     * @param applyId
     */
    @Update("update invoice_apply_item set status_cd = '1' where apply_id = #{applyId}")
    void deleteInvoiceItem(String applyId);
     /**
     * 获取发票详情----发票图片
     * @param
     * @return 发票图片
     */
    List<QueryInvoiceImageDTO> selectInvoiceImage(InvoiceDetailsQuery invoiceDetails);

}
