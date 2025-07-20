package com.zeroone.star.merchantmanage.controller.message;

import com.zeroone.star.merchantmanage.service.message.IMerchantService;
import com.zeroone.star.project.dto.PageDTO;
import com.zeroone.star.project.dto.j3.merchantmanage.message.MerchantDTO;
import com.zeroone.star.project.j3.merchantmanage.message.MerchantMessageApis;
import com.zeroone.star.project.query.j3.merchantmanage.message.MerchantQuery;
import com.zeroone.star.project.vo.JsonVO;
import io.swagger.annotations.Api;
import io.swagger.annotations.ApiOperation;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.validation.annotation.Validated;
import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.RequestBody;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RestController;

import javax.validation.Valid;

@RestController
@RequestMapping("j3-merchant/merchant-message")
@Api(tags = "商户信息管理")
public class MerchantMessageController implements MerchantMessageApis {
    @Autowired
    private IMerchantService merchantService;
    /**
     * 查询商户信息
     * @param query 查询条件
     * @return 商户信息列表
     * @author: 零一星
     *
     */
    @Override
    @ApiOperation("获取商户列表（条件+分页）")
    @GetMapping("/query")
    public JsonVO<PageDTO<MerchantDTO>> queryMerchant(@Validated MerchantQuery query) {

        // 调用服务层查询商户信息
        PageDTO<MerchantDTO> merchantList = merchantService.listAllMerchants(query);
        if(merchantList == null || merchantList.getTotal() == null || merchantList.getTotal() == 0) {
            return JsonVO.create(null, 9999, "没有查询到商户信息");
        }
        // 返回结果
        return JsonVO.success(merchantList);
    }
}
