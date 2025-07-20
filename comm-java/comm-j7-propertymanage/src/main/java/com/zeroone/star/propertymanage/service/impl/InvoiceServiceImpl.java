package com.zeroone.star.propertymanage.service.impl;

import cn.hutool.core.lang.UUID;
import cn.hutool.core.util.IdUtil;
import com.alibaba.cloud.commons.lang.StringUtils;
import com.baomidou.mybatisplus.core.conditions.update.LambdaUpdateWrapper;
import com.baomidou.mybatisplus.extension.service.impl.ServiceImpl;
import com.zeroone.star.project.components.fastdfs.FastDfsClientComponent;
import com.zeroone.star.project.components.fastdfs.FastDfsFileInfo;
import com.zeroone.star.project.components.user.UserHolder;
import com.zeroone.star.project.dto.j7.propertymanage.invoice.*;
import com.zeroone.star.project.query.j7.propertymanage.invoice.InvoiceDetailsQuery;
import com.zeroone.star.project.query.j7.propertymanage.invoice.InvoiceQuery;
import com.zeroone.star.project.query.j7.propertymanage.invoice.RegisterInvoiceQuery;
import com.zeroone.star.propertymanage.entity.FileRelDO;
import com.zeroone.star.propertymanage.entity.HcFileDO;
import com.zeroone.star.propertymanage.entity.Invoice;
import com.zeroone.star.propertymanage.entity.InvoiceItem;
import com.zeroone.star.propertymanage.mapper.FileRelMapper;
import com.zeroone.star.propertymanage.mapper.HcFileMapper;
import com.zeroone.star.propertymanage.mapper.InvoiceMapper;
import com.zeroone.star.propertymanage.entity.InvoiceEventDO;
import com.zeroone.star.propertymanage.mapper.*;
import com.zeroone.star.propertymanage.service.InvoiceService;
import lombok.SneakyThrows;
import org.slf4j.Logger;
import org.slf4j.LoggerFactory;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.beans.factory.annotation.Value;
import org.springframework.stereotype.Service;
import org.springframework.transaction.annotation.Transactional;
import org.springframework.web.multipart.MultipartFile;
import java.net.URL;
import java.util.*;

import java.util.List;

/**
 * @author ermali
 * @version 1.0
 */
@Service
public class InvoiceServiceImpl extends ServiceImpl<InvoiceMapper, Invoice> implements InvoiceService {

    @Autowired
    private InvoiceMapper invoiceMapper;
    @Autowired
    private HcFileMapper hcFileMapper;
    @Autowired
    private FileRelMapper fileRelMapper;
    @Autowired
    private InvoiceEventMapper invoiceEventMapper;
    @Autowired
    private FastDfsClientComponent fastDfsClientComponent;

    @Value("${fastdfs.server-url")
    private String serverUrl;

    private static Logger logger = LoggerFactory.getLogger(InvoiceServiceImpl.class);

    // 定义发票图片的关联类型编码
    private static final String FILE_REL_TYPE_INVOICE_IMAGE = "29000"; // 发票图片

    // 定义文件存储方式 (与 file_rel 表的 save_way 字段对应)
    private static final String FILE_SAVE_WAY_FASTDFS = "fastdfs";

    /**
     * 获取发票列表
     *
     * @param query 查询参数
     * @return 发票列表
     */
    @Override
    public List<QueryInvoiceDTO> listInvoice(InvoiceQuery query) {
        return invoiceMapper.selectInvoice(query);
    }

    @SneakyThrows
    @Transactional
    @Override
    public List<String> uploadInvoicePhoto(InvoicePhotoUploadDTO invoicePhotoUploadDTO) {
        if (invoicePhotoUploadDTO.getApplyId() == null || StringUtils.isBlank(invoicePhotoUploadDTO.getApplyId())) {
            throw new Exception("发票编号缺失");
        }

        if (invoicePhotoUploadDTO.getCommunityId() == null || StringUtils.isBlank(invoicePhotoUploadDTO.getCommunityId())) {
            throw new Exception("社区Id缺失");
        }

        if (invoicePhotoUploadDTO.getFiles() == null || invoicePhotoUploadDTO.getFiles().isEmpty()) {
            throw new Exception("图片列表缺失");
        }

        List<String> savedFileIdentifiers = new ArrayList<>();
        try {
            // 遍历每个上传的文件进行处理
            for (int i = 0; i < invoicePhotoUploadDTO.getFiles().size(); i++) {
                MultipartFile uploadFile = invoicePhotoUploadDTO.getFiles().get(i);
                String originalFileName = uploadFile.getOriginalFilename();

                if (uploadFile.isEmpty()) {
                    continue; // 跳过空文件
                }

                String fileId = UUID.randomUUID().toString().replace("-", "").substring(0, 30); // 为每个文件生成唯一ID
                String suffix = "";
                // 获取文件后缀名
                if (originalFileName != null && originalFileName.contains(".")) {
                    suffix = originalFileName.substring(originalFileName.lastIndexOf(".") + 1);
                }

                /** 文件上传到 FastDFS **/
                FastDfsFileInfo fastDfsFileInfo = fastDfsClientComponent.uploadFile(uploadFile.getBytes(), suffix);
                if (fastDfsFileInfo == null) {
                    logger.error("文件 {} (原始名: {}) 上传到FastDFS失败", fileId, originalFileName);
                    throw new Exception("上传文件 " + originalFileName + " 到FastDFS失败");
                }
                logger.debug("文件 {} (原始名: {}) 上传到FastDFS成功，group: {}, storageId: {}", fileId, originalFileName, fastDfsFileInfo.getGroup(), fastDfsFileInfo.getStorageId());

                String fastDfsFileSavePath = fastDfsClientComponent.fetchUrl(fastDfsFileInfo, serverUrl, true);
                URL url = new URL(fastDfsFileSavePath);
                String fileSaveName = url.getPath();

                /** 保存文件元数据到 hc_file 表 **/
                HcFileDO hcFileDO = HcFileDO.builder()
                        .fileId(fileId)
                        .communityId(invoicePhotoUploadDTO.getCommunityId())
                        .fileName(originalFileName)
                        .suffix(suffix)
                        .context("invoice_photo")
                        .createTime(new Date())
                        .statusCd("0")
                        .build();

                Map<String, Object> fileInfoMap = new HashMap<>();
                fileInfoMap.put("fileId", hcFileDO.getFileId());
                fileInfoMap.put("communityId", hcFileDO.getCommunityId());
                fileInfoMap.put("fileName", hcFileDO.getFileName());
                fileInfoMap.put("context", hcFileDO.getContext());
                fileInfoMap.put("suffix", hcFileDO.getSuffix());
                fileInfoMap.put("createTime", hcFileDO.getCreateTime());
                fileInfoMap.put("statusCd", "0");

                int saveFileFlag = hcFileMapper.saveFile(fileInfoMap);
                if (saveFileFlag < 1) {
                    logger.error("保存文件元数据到hc_file失败，fileId: {}", fileId);
                    throw new Exception("保存文件信息失败: " + originalFileName);
                }
                logger.debug("文件元数据保存到hc_file成功，fileId: {}", fileId);

                /** 创建 FileRelDo 记录文件与发票申请的关联 **/
                FileRelDO fileRelDO = FileRelDO.builder()
                        .fileRelId(UUID.randomUUID().toString().replace("-", "").substring(0, 30))
                        .bId("-1")
                        .relTypeCd(FILE_REL_TYPE_INVOICE_IMAGE)
                        .saveWay(FILE_SAVE_WAY_FASTDFS)
                        .objId(invoicePhotoUploadDTO.getApplyId())
                        .fileRealName(originalFileName)
                        .fileSaveName(fileSaveName)
                        .createTime(new Date())
                        .statusCd("0")
                        .build();

                /** 调用 FileRelMapper 保存关联记录 **/
                Map<String, Object> fileRelInfoMap = new HashMap<>();
                fileRelInfoMap.put("fileRelId", fileRelDO.getFileRelId());
                fileRelInfoMap.put("objId", fileRelDO.getObjId());
                fileRelInfoMap.put("relTypeCd", fileRelDO.getRelTypeCd());
                fileRelInfoMap.put("saveWay", fileRelDO.getSaveWay());
                fileRelInfoMap.put("fileRealName", fileRelDO.getFileRealName());
                fileRelInfoMap.put("fileSaveName", fileRelDO.getFileSaveName());
                fileRelInfoMap.put("statusCd", fileRelDO.getStatusCd());
                fileRelInfoMap.put("bId", fileRelDO.getBId());
                fileRelInfoMap.put("createTime", fileRelDO.getCreateTime());

                int saveRelFlag = fileRelMapper.saveFileRel(fileRelInfoMap);
                if (saveRelFlag < 1) {
                    logger.error("保存文件关联记录到file_rel失败，applyId: {}, fileRelId: {}", fileRelDO.getObjId(), fileRelDO.getFileRelId());
                    throw new Exception("保存文件关联信息失败: " + originalFileName);
                }
                logger.debug("文件关联信息保存到file_rel成功，fileRelId: {}", fileRelDO.getFileRelId());

                /** 将 FastDFS 文件标识添加到结果列表 **/
                savedFileIdentifiers.add(fastDfsFileSavePath);

                /** 将发票图片上传事件更新到invoice_event表中 **/
                String eventId = String.valueOf(IdUtil.getSnowflake(1,1).nextId());
                InvoiceEventDO invoiceEventDO = InvoiceEventDO.builder()
                        .eventId(eventId.length() > 30 ? eventId.substring(0, 30) : eventId)
                        .applyId(invoicePhotoUploadDTO.getApplyId())
                        .eventType(InvoiceEventCreateDTO.STATE_UPLOAD)
                        .remark("上传发票")
                        //生产环境开发时通过上下文获取Id和Name
                        .createUserId(new UserHolder().getCurrentUser().getId().toString())
                        .createUserName(new UserHolder().getCurrentUser().getUsername())
                        //.createUserId("111")
                        //.createUserName("UserName")
                        .communityId(invoicePhotoUploadDTO.getCommunityId())
                        .createTime(new Date())
                        .statusCd("0")
                        .build();

                int saveEventFlag = invoiceEventMapper.saveInvoiceEvent(invoiceEventDO);
                if (saveEventFlag < 1) {
                    logger.error("保存发票上传事件失败");
                    throw new Exception("保存发票事件失败");
                }

            } // 结束文件遍历循环

            return savedFileIdentifiers;

        } catch (Exception e) {
            logger.error("文件上传和关联过程中发生未知错误:", e);
            throw new Exception("文件上传过程中发生未知错误：" + e.getMessage(), e);
        }
    }

    /**
     * 获取发票详情
     *
     * @param applyId     申请ID
     * @param communityId 小区ID
     * @return 发票详情
     */
    @Override
    public Invoice getInvoiceDetail(String applyId, String communityId) {
        return invoiceMapper.selectInvoiceDetail(applyId, communityId);
    }

    /**
     * 获取发票详情---开票明细
     *
     * @param
     * @return 发票详情
     */
    @Override
    public List<InvoiceDetailsDTO> listInvoiceDetails(InvoiceDetailsQuery details) {
        return invoiceMapper.selectInvoiceDetails(details);
    }

    /**
     * 获取发票详情----审核记录
     *
     * @param
     * @return 审核记录
     */
    @Override
    public List<AuditRecordsDTO> listAuditRecords(InvoiceDetailsQuery auditRecords) {
        return invoiceMapper.selectAuditRecords(auditRecords);
    }

    public void addInvoiceItem(InvoiceItem invoiceItem) {
        invoiceMapper.insertInvoiceItem(invoiceItem);
    }

    @SneakyThrows
    @Override
    @Transactional
    public void registerInvoiceApply(RegisterInvoiceQuery requestParam) {
        // 1. 根据 eventType 确定要更新的发票申请状态
        String newState;
        // 2. 更新发票申请状态
        Invoice invoice = Invoice.builder()
                .applyId(requestParam.getApplyId())
                .communityId(requestParam.getCommunityId())
                .build();
        // 如果前端选择了4004领用，则更新invoice_apply表中的状态为已领用，选择了5005登记，则不做更新
        if (InvoiceEventCreateDTO.EVENT_TYPE_GET.equals(requestParam.getEventType())) {
            newState = InvoiceApplyUpdateDTO.STATE_COMPLETE;
            invoice.setState(newState);
        }
        LambdaUpdateWrapper<Invoice> updateWrapper = new LambdaUpdateWrapper<>();
        updateWrapper.eq(Invoice::getApplyId, invoice.getApplyId())
                .eq(Invoice::getCommunityId, invoice.getCommunityId())
                .eq(Invoice::getStatusCd, "0");
        int updateFlag = baseMapper.update(invoice, updateWrapper);
        if (updateFlag < 1) {
            logger.error("更新发票申请状态失败失败");
            throw new RuntimeException("更新发票申请状态失败：未找到符合条件的记录");
        }
        // 3. 创建发票事件DO
        String eventId = String.valueOf(IdUtil.getSnowflake(1,1).nextId());
        InvoiceEventDO invoiceEventDO = InvoiceEventDO.builder()
                .eventId(eventId.length() > 30 ? eventId.substring(0, 30) : eventId)
                .applyId(requestParam.getApplyId())
                .remark(requestParam.getRemark())
                .eventType(requestParam.getEventType())
                .communityId(requestParam.getCommunityId())
                //生产环境开发时通过上下文获取Id和Name
                .createUserId(new UserHolder().getCurrentUser().getId().toString())
                .createUserName(new UserHolder().getCurrentUser().getUsername())
                //.createUserId("111")
                //.createUserName("UserName")
                .createTime(new Date())
                .statusCd("0")
                .build();

        int saveEventFlag = invoiceEventMapper.saveInvoiceEvent(invoiceEventDO);
        if (saveEventFlag < 1) {
            logger.error("保存发票登记事件失败");
            throw new RuntimeException("保存发票登记事件失败");
        }
    }

     /**
     * 获取发票详情------查看发票下载地址
     * @param  invoiceDetails
     * @return fileSaveName
     */
    @Override
    public List<QueryInvoiceImageDTO> listInvoiceImage(InvoiceDetailsQuery invoiceDetails) {
        System.out.println(invoiceMapper.selectInvoiceImage(invoiceDetails));
        return invoiceMapper.selectInvoiceImage(invoiceDetails);
    }




    /**
     * 删除发票明细
     *
     * @param
     * @return 删除发票明细
     */
    public void deleteInvoiceItem(String applyId) {
        invoiceMapper.deleteInvoiceItem(applyId);
    }
}

