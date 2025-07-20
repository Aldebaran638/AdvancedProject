package com.zeroone.star.project.j7.propertymanage;

import com.zeroone.star.project.dto.j7.propertymanage.invoice.*;
import com.zeroone.star.project.query.j7.propertymanage.invoice.InvoiceDetailsQuery;
import com.zeroone.star.project.vo.JsonVO;
import com.zeroone.star.project.dto.PageDTO;
import com.zeroone.star.project.query.j7.propertymanage.invoice.InvoiceQuery;
import com.zeroone.star.project.query.j7.propertymanage.invoice.RegisterInvoiceQuery;
import org.springframework.http.ResponseEntity;
import org.springframework.web.multipart.MultipartFile;
import springfox.documentation.spring.web.json.Json;

import java.util.List;

/**
 * @author neko
 * #Description：发票apis
 * #Date: 2025/5/19 17:58
 */
public interface InvoiceApis {

    /**
     * 添加发票信息
     * @author douya266
     * @param addInvoiceDTO 添加发票信息
     * @return 添加发票信息
     */
    JsonVO<String> addInvoice(AddInvoiceDTO addInvoiceDTO);

    /**
     * 修改发票信息
     * @author douya266
     * @param invoiceDTO 修改发票信息
     * @return 修改发票信息
     */
    JsonVO<String> auditInvoice(InvoiceDTO invoiceDTO);

    /**
     * 删除发票信息
     * @author douya266
     * @param invoiceId 删除发票信息
     * @return 删除发票信息
     */
    JsonVO<String> deleteInvoice(String invoiceId);

    /*
     * 发票信息查询
     *
     * @param query 查询条件
     * @return 发票信息列表
     */
    JsonVO<PageDTO<QueryInvoiceDTO>> queryInvoice(InvoiceQuery query);

    /**
     * 获取发票详细
     *
     * @param applyId 申请Id
     * @param communityId 小区Id
     * @return 详细发票信息
     */
    JsonVO<QueryInvoiceDTO> queryInvoiceDetail(String applyId,String communityId);

    /**
     * 发票详细---------获取开票详情
     *
     * @param invoiceDetails  发票详细
     * @return 详细发票信息
     */
    JsonVO<PageDTO<InvoiceDetailsDTO>> queryInvoiceDetails(InvoiceDetailsQuery invoiceDetails);

    /**
     * 发票详细---------获取审核记录
     *
     * @param auditRecords  审核记录
     * @return 详细发票信息
     */
    JsonVO<PageDTO<AuditRecordsDTO>> queryAuditRecords(InvoiceDetailsQuery auditRecords);

    /**
     * 发票详情-------查看发票下载地址
     * @param downloadLink 发票下载地址
     */
    List<String> queryImage(InvoiceDetailsQuery downloadLink);

    /**
     * 登记发票
     *
     * @param requestParam 请求参数
     * @return 登记状态
     */
    public JsonVO registerInvoiceApply(RegisterInvoiceQuery requestParam);

    /**
     * 上传发票
     * @param applyId 发票申请ID
     * @param communityId 社区ID
     * @param uploadFiles 上传的文件列表
     * @return 操作结果
     */
    public JsonVO uploadInvoicePhoto(String applyId,
                                     String communityId,
                                     List<MultipartFile> uploadFiles);
}
