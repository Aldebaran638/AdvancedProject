package com.zeroone.star.propertymanage.controller;

import cn.hutool.core.bean.BeanUtil;
import cn.hutool.core.date.DateUtil;

import com.zeroone.star.project.components.fastdfs.FastDfsClientComponent;
import com.zeroone.star.project.dto.j7.propertymanage.invoice.AddInvoiceDTO;
import com.zeroone.star.project.dto.j7.propertymanage.invoice.InvoiceDTO;
import com.zeroone.star.project.dto.j7.propertymanage.invoice.InvoicePhotoUploadDTO;
import com.zeroone.star.project.dto.j7.propertymanage.invoice.QueryInvoiceDTO;
import com.zeroone.star.project.dto.j7.propertymanage.invoice.*;
import com.zeroone.star.project.j7.propertymanage.InvoiceApis;
import com.zeroone.star.project.query.j7.propertymanage.invoice.InvoiceDetailsQuery;
import com.zeroone.star.project.vo.JsonVO;
import com.zeroone.star.propertymanage.entity.Invoice;
import com.zeroone.star.propertymanage.entity.InvoiceItem;
import com.zeroone.star.propertymanage.service.IInvoiceService;
import com.zeroone.star.propertymanage.service.InvoiceService;
import io.swagger.annotations.*;
import lombok.RequiredArgsConstructor;
import lombok.SneakyThrows;
import org.springframework.beans.BeanUtils;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.transaction.annotation.Transactional;
import org.springframework.beans.factory.annotation.Value;
import org.springframework.http.ResponseEntity;
import org.springframework.web.bind.annotation.*;
import com.zeroone.star.project.dto.PageDTO;
import com.zeroone.star.project.query.j7.propertymanage.invoice.InvoiceQuery;
import io.swagger.annotations.Api;
import io.swagger.annotations.ApiOperation;
import org.springframework.web.bind.annotation.GetMapping;
import com.zeroone.star.project.query.j7.propertymanage.invoice.RegisterInvoiceQuery;
import org.springframework.web.bind.annotation.PostMapping;
import org.springframework.web.bind.annotation.RequestBody;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RestController;
import org.springframework.web.multipart.MultipartFile;

import java.util.Date;
import javax.validation.Valid;
import javax.annotation.Resource;
import java.util.ArrayList;
import java.util.List;


/**
 * @author neko
 * #Description：车位申请控制器
 * #Date: 2025/5/19 18:23
 */
@RestController
@RequestMapping("/j7-property/property-manage/invoice")
@Api(tags = "发票")
@RequiredArgsConstructor
public class InvoiceController implements InvoiceApis {

    @Autowired
    private InvoiceService invoiceService;


    private final IInvoiceService iinvoiceService;
    @Value("${fastdfs.nginx-servers}")
    private String serverUrl;
    @Resource
    private FastDfsClientComponent fastDfsClientComponent;

    /**
     * 获取发票列表
     * @author ermali
     * @param query 查询条件
     * @return
     */
    @ApiOperation(value = "获取发票列表 (条件+分页)")
    @GetMapping("/query-invoice")
    @Override
    public JsonVO<PageDTO<QueryInvoiceDTO>> queryInvoice(InvoiceQuery query) {
        List<QueryInvoiceDTO> dataList = invoiceService.listInvoice(query);
        PageDTO<QueryInvoiceDTO> pageData = new PageDTO<>();
        pageData.setPageIndex(query.getPageIndex());
        pageData.setPageSize(query.getPageSize());
        pageData.setTotal((long) dataList.size());
        pageData.setPages(dataList.size() / query.getPageSize() + 1);
        pageData.setRows(dataList);
        return JsonVO.success(pageData);
    }

    /**
     * 获取发票详情
     * @author ermali
     * @param applyId 申请ID
     * @param communityId 小区ID
     * @return
     */
    @ApiOperation(value = "获取发票详情")
    @GetMapping("/query-invoice-detail")
    @ApiImplicitParams ({
        @ApiImplicitParam(name = "applyId", value = "申请ID", required = true),
        @ApiImplicitParam(name = "communityId", value = "小区ID", required = true)
    })
    @Override
    public JsonVO<QueryInvoiceDTO> queryInvoiceDetail(String applyId, String communityId) {
        Invoice invoice = invoiceService.getInvoiceDetail(applyId, communityId);
        if (invoice == null) {
            return JsonVO.fail(null);
        }
        QueryInvoiceDTO invoiceDetail =new QueryInvoiceDTO();
        BeanUtils.copyProperties(invoice, invoiceDetail);
        return JsonVO.success(invoiceDetail);
    }

    /**
     * 获取发票列表
     * @author ermali
     * @param details 查询条件
     * @return  开票明细
     */
    @ApiOperation(value = "发票详情----开票明细")
    @GetMapping("/query-invoice-details")
    @Override
    public JsonVO<PageDTO<InvoiceDetailsDTO>> queryInvoiceDetails(InvoiceDetailsQuery details) {
        List<InvoiceDetailsDTO> dataList = invoiceService.listInvoiceDetails(details);
        PageDTO<InvoiceDetailsDTO> pageData = new PageDTO<>();
        pageData.setPageIndex(details.getPageIndex());
        pageData.setPageSize(details.getPageSize());
        pageData.setTotal((long) dataList.size());
        pageData.setPages(dataList.size() / details.getPageSize() + 1);
        pageData.setRows(dataList);
        return JsonVO.success(pageData);
    }

    /**
     * 获取发票列表
     * @author ermali
     * @param auditRecords 查询条件
     * @return  审核记录
     */
    @ApiOperation(value = "发票详情----审核记录")
    @GetMapping("/query-invoice-details-audit-records")
    @Override
    public JsonVO<PageDTO<AuditRecordsDTO>> queryAuditRecords(InvoiceDetailsQuery auditRecords){
        List<AuditRecordsDTO> dataList = invoiceService.listAuditRecords(auditRecords);
        PageDTO<AuditRecordsDTO> pageData = new PageDTO<>();
        pageData.setPageIndex(auditRecords.getPageIndex());
        pageData.setPageSize(auditRecords.getPageSize());
        pageData.setTotal((long) dataList.size());
        pageData.setPages(dataList.size() / auditRecords.getPageSize() + 1);
        pageData.setRows(dataList);
        return JsonVO.success(pageData);
    }

    @SneakyThrows
    @ApiOperation(value = "发票详情----查看发票")
    @GetMapping(value = "/query-invoice-details-download-link")
    public List<String> queryImage(InvoiceDetailsQuery invoiceDetails){
        List<QueryInvoiceImageDTO> invoiceImages = invoiceService.listInvoiceImage(invoiceDetails);
        List<String> imageUrls = new ArrayList<>();
        for (QueryInvoiceImageDTO image : invoiceImages) {
            String fullPath = image.getFileSaveName();
            String Urls = "http://"+serverUrl  + fullPath;
            System.out.println(serverUrl);
            imageUrls.add(Urls);
        }
        return imageUrls;
    }

    /**
     * 申请发票
     * @author douya266
     * @param addInvoiceDTO 添加发票信息
     * @return
     */

    @ApiOperation(value = "申请发票")
    @PostMapping("/add-invoice")
    @Override
    @Transactional
    public JsonVO<String> addInvoice(@RequestBody AddInvoiceDTO addInvoiceDTO) {
        Invoice invoice = BeanUtil.copyProperties(addInvoiceDTO, Invoice.class);
         invoice.setCreateTime( DateUtil.format(new Date(), "yyyy-MM-dd HH:mm:ss"));
        InvoiceItem invoiceItem = BeanUtil.copyProperties(addInvoiceDTO, InvoiceItem.class);
        iinvoiceService.addInvoice(invoice);
        invoiceItem.setApplyId(invoice.getApplyId());
        invoiceItem.setItemAmount( invoice.getInvoiceAmount());
        invoiceItem.setItemType( invoice.getInvoiceType());
        invoiceItem.setCreateTime( invoice.getCreateTime());
        invoiceItem.setStatusCd("0");
        //获取当前时间
        invoiceItem.setCreateTime( DateUtil.format(new Date(), "yyyy-MM-dd HH:mm:ss"));
        invoiceService.addInvoiceItem(invoiceItem);
        return JsonVO .success("添加成功");
    }

    /**
     * 审核发票
     * @author douya266
     * @param invoiceDTO 审核发票信息
     * @return
     */
    @ApiOperation(value = "审核发票")
    @PutMapping("/update-invoice-status")
    @Override
    public JsonVO<String> auditInvoice(@RequestBody InvoiceDTO invoiceDTO) {

        String state = invoiceDTO.getState();
        if (state.equals("U") || state.equals("F")){
            Invoice invoice = invoiceService.getById(invoiceDTO.getApplyId());
            invoice.setState(state);
            iinvoiceService.updateById(invoice);
            if (invoice.getState().equals("U"))
            return JsonVO .success("审核成功");
            return JsonVO.success("审核未通过");
        }
         return JsonVO.success("传入的参数并非审核类参数");

    }

    /**
     * 删除发票
     * @author douya266
     * @param invoiceId 发票ID
     * @return
     */
    @ApiOperation(value = "删除发票")
    @DeleteMapping("/delete-invoice")
    @Override
    public JsonVO<String> deleteInvoice(String invoiceId) {
        iinvoiceService.deleteInvoice( invoiceId);
        invoiceService.deleteInvoiceItem(invoiceId);
         return JsonVO.success("删除成功");
    }


    @ApiOperation(value = "上传发票")
    @PostMapping("upload-invoice")
    @Override
    public JsonVO<List<String>> uploadInvoicePhoto(@RequestParam("applyId") @Valid String applyId,
                                                   @RequestParam("communityId") @Valid String communityId,
                                                   @RequestPart("uploadFiles") @Valid List<MultipartFile> uploadFiles) {
        InvoicePhotoUploadDTO invoicePhotoUploadDTO = InvoicePhotoUploadDTO.builder()
                .applyId(applyId)
                .communityId(communityId)
                .files(uploadFiles)
                .build();

        return JsonVO.create(invoiceService.uploadInvoicePhoto(invoicePhotoUploadDTO), 200, "文件上传成功");
    }

    @ApiOperation(value = "登记发票")
    @PostMapping("register-invoice")
    @Override
    public JsonVO registerInvoiceApply(@RequestBody @Valid RegisterInvoiceQuery requestParam) {
        invoiceService.registerInvoiceApply(requestParam);
        return JsonVO.success("登记成功");
    }

}
