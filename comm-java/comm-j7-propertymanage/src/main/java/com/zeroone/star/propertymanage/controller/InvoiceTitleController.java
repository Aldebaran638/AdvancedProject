package com.zeroone.star.propertymanage.controller;

import com.zeroone.star.project.dto.PageDTO;
import com.zeroone.star.project.dto.j7.propertymanage.Invoicetitle.AddInvoicetitleDTO;
import com.zeroone.star.project.dto.j7.propertymanage.Invoicetitle.InvoicetitleDTO;
import com.zeroone.star.project.j7.propertymanage.InvoiceTitleApis;
import com.zeroone.star.project.vo.JsonVO;
import com.zeroone.star.propertymanage.service.InvoiceTitleService;
import io.swagger.annotations.Api;
import io.swagger.annotations.ApiImplicitParam;
import io.swagger.annotations.ApiOperation;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.web.bind.annotation.DeleteMapping;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RestController;
import com.zeroone.star.project.query.j7.propertymanage.Invoicetitle.InvoicetitleQuery;
import org.springframework.web.bind.annotation.*;

/**
 * @author neko
 * #Description：车位申请控制器
 * #Date: 2025/5/19 18:23
 */
@RestController
@RequestMapping("/j7-property/property-manage/invoice-title")
@Api(tags = "发票抬头")
public class InvoiceTitleController implements InvoiceTitleApis {
    @Autowired
    private InvoiceTitleService invoiceTitleService;

    @ApiOperation("获取发票抬头列表（条件+分页）")
    @GetMapping("/query")
    @Override
    public JsonVO<PageDTO<InvoicetitleDTO>> queryInvoiceTitle(InvoicetitleQuery query) {
        return invoiceTitleService.listIncoiceTitle(query);
    }

    @ApiOperation("添加发票抬头数据")
    @PostMapping("/add")
    @Override
    public JsonVO<String> addInvoiceTitle(@RequestBody AddInvoicetitleDTO addInvoicetitleDTO) {

        return invoiceTitleService.saveInvoiceTitle(addInvoicetitleDTO);
    }


    @ApiOperation("修改发票抬头数据")
    @PutMapping("/modify")
    @Override
    public JsonVO<String> modifyInvoiceTitle(@RequestBody InvoicetitleDTO invoicetitleDTO) {
        return invoiceTitleService.updateInvoiceTitle(invoicetitleDTO);
    }

    /**
     * 删除发票抬头
     * @param oiId 业主发票Id
     * @return
     */
    @ApiOperation(value = "删除发票抬头")
    @ApiImplicitParam(name = "oiId", value = "编号", required = true)
    @DeleteMapping("/remove-invoice-title")
    @Override
    public JsonVO<String> removeInvoiceTitle(String oiId) {
        int oiID = invoiceTitleService.removeInvoiceTitle(oiId);
        if (oiID == 0) {
            return JsonVO.fail("删除失败");
        }
        return JsonVO.success("删除成功");
    }
}
