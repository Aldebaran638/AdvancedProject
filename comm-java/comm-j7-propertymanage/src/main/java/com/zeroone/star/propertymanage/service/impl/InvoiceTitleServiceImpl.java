package com.zeroone.star.propertymanage.service.impl;

import com.zeroone.star.project.dto.PageDTO;
import com.zeroone.star.project.dto.j7.propertymanage.Invoicetitle.AddInvoicetitleDTO;
import com.zeroone.star.project.dto.j7.propertymanage.Invoicetitle.InvoicetitleDTO;
import com.zeroone.star.project.query.j7.propertymanage.Invoicetitle.InvoicetitleQuery;
import com.zeroone.star.project.vo.JsonVO;
import com.zeroone.star.propertymanage.entity.InvoiceTitle;
import com.zeroone.star.propertymanage.mapper.InvoiceTitleMapper;
import com.zeroone.star.propertymanage.service.InvoiceTitleService;
import lombok.extern.slf4j.Slf4j;
import org.springframework.beans.BeanUtils;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Service;

import java.time.LocalDateTime;
import java.util.List;
import java.util.UUID;

/**
 * @author ermali
 * @version 1.0
 */
@Slf4j
@Service
public class InvoiceTitleServiceImpl implements InvoiceTitleService {

    @Autowired
    private InvoiceTitleMapper invoiceTitleMapper;

    /**
     * 删除发票抬头
     * @param oiId 编号
     * @return
     */
    @Override
    public int removeInvoiceTitle(String oiId) {
        return invoiceTitleMapper.deleteInvoiceTitle(oiId);
    }

    @Override
    public JsonVO<PageDTO<InvoicetitleDTO>> listIncoiceTitle(InvoicetitleQuery query) {
        List<InvoicetitleDTO> list=invoiceTitleMapper.selectInvoiceTitle(query);
        PageDTO<InvoicetitleDTO> pageDTO=new PageDTO<>();
        pageDTO.setPageIndex(query.getPageIndex());
        pageDTO.setPageSize(query.getPageSize());
        pageDTO.setTotal((long) list.size());
        pageDTO.setPages(list.size()/query.getPageSize()+1);
        pageDTO.setRows(list);
        return JsonVO.success(pageDTO);
    }

    @Override
    public JsonVO<String> saveInvoiceTitle(AddInvoicetitleDTO addInvoicetitleDTO) {
        InvoiceTitle invoiceTitle=new InvoiceTitle();

        log.info(addInvoicetitleDTO.toString());

        BeanUtils.copyProperties(addInvoicetitleDTO,invoiceTitle);

        log.info(invoiceTitle.toString());

       invoiceTitle.setOiId(UUID.randomUUID().toString().replace("-", "").substring(0, 30));
        InvoiceTitle list=invoiceTitleMapper.selectBuildingOwner(invoiceTitle.getOwnerId());
        log.info(invoiceTitle.toString());
        invoiceTitle.setCommunityId(list.getCommunityId());
        invoiceTitle.setStatusCd(list.getStatusCd());
        invoiceTitle.setCreateTime(LocalDateTime.now());
        invoiceTitleMapper.insertInvoiceTitle(invoiceTitle);
        return JsonVO.success("添加成功");
    }

    @Override
    public JsonVO<String> updateInvoiceTitle(InvoicetitleDTO invoicetitleDTO) {
        invoiceTitleMapper.updateInvoiceTitle(invoicetitleDTO);
        return JsonVO.success("修改成功");
    }
}
