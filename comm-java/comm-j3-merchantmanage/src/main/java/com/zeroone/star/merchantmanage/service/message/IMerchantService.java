package com.zeroone.star.merchantmanage.service.message;

import com.baomidou.mybatisplus.extension.service.IService;
import com.zeroone.star.merchantmanage.entity.SStoreDO;
import com.zeroone.star.project.dto.j3.merchantmanage.message.MerchantDTO;
import com.zeroone.star.project.query.j3.merchantmanage.message.MerchantQuery;
import com.zeroone.star.project.dto.PageDTO;
/**
 * @author wyr on 2025/5/24
 */

public interface IMerchantService{
    /**
     * 查询商户信息
     *
     * @param query 查询条件
     * @return 商户信息列表
     */
    PageDTO<MerchantDTO> listAllMerchants(MerchantQuery query);

}
