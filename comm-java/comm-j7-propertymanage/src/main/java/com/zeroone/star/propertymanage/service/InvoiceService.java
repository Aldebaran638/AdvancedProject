package com.zeroone.star.propertymanage.service;

import com.baomidou.mybatisplus.extension.service.IService;
import com.zeroone.star.project.dto.PageDTO;
import com.zeroone.star.project.dto.j7.propertymanage.invoice.*;
import com.zeroone.star.project.query.j7.propertymanage.invoice.InvoiceDetailsQuery;
import com.zeroone.star.project.query.j7.propertymanage.invoice.InvoiceQuery;
import com.zeroone.star.project.query.j7.propertymanage.invoice.RegisterInvoiceQuery;
import com.zeroone.star.project.vo.JsonVO;
import com.zeroone.star.propertymanage.entity.Invoice;
import com.zeroone.star.propertymanage.entity.InvoiceItem;
import com.zeroone.star.propertymanage.service.impl.InvoiceServiceImpl;
import io.swagger.models.auth.In;
import org.springframework.http.ResponseEntity;
import org.springframework.stereotype.Component;
import com.zeroone.star.propertymanage.entity.Invoice;

import java.util.List;

public interface InvoiceService extends IService<Invoice>{
   /**
   * 获取发票列表
   * @param query 查询参数
   * @return 发票列表
   */
   List<QueryInvoiceDTO> listInvoice(InvoiceQuery query);

   /**
   * 获取发票详情
   * @param applyId 申请ID
   * @param communityId 小区ID
   * @return 发票详情
   */
   Invoice getInvoiceDetail(String applyId, String communityId);


   /**
   * 获取发票详情----开票明细
   * @param
   * @return 开票明细
   */
   List<InvoiceDetailsDTO> listInvoiceDetails(InvoiceDetailsQuery details);

    /**
     * 上传发票图片 (支持多文件)
     * @param invoicePhotoUploadDTO 文件上传信息DTO，包含文件列表
     * @return List<String> 保存后的文件标识列表
     */
    List<String> uploadInvoicePhoto(InvoicePhotoUploadDTO invoicePhotoUploadDTO);
   /**
   * 获取发票详情----审核记录
   * @param
   * @return 审核记录
   */
   List<AuditRecordsDTO> listAuditRecords(InvoiceDetailsQuery auditRecords);



    void addInvoiceItem(InvoiceItem invoiceItem);

    /**
     * 删除发票明细表
     * @param invoiceId
     */
    void deleteInvoiceItem(String invoiceId);
    /**
     * 执行发票登记核销操作
     * @param requestParam 登记核销信息
     * @return
     */
    void registerInvoiceApply(RegisterInvoiceQuery requestParam);
    /**
     * 获取发票详情----查看发票
     * @param
     * @return 查看发票
     */
    List<QueryInvoiceImageDTO> listInvoiceImage(InvoiceDetailsQuery invoiceDetails);

}
