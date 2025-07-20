package com.zeroone.star.project.j3.merchantmanage.message;

import com.zeroone.star.project.dto.PageDTO;
import com.zeroone.star.project.dto.j3.merchantmanage.message.MerchantDTO;
import com.zeroone.star.project.query.j3.merchantmanage.message.MerchantQuery;
import com.zeroone.star.project.vo.JsonVO;

/**
 * 商户消息相关API接口
 * @author wyr on 2025/5/19
 */
public interface MerchantMessageApis {
    /**
     * 查询商户信息
     * @param query 查询条件
     * @return 商户信息列表
     */
    JsonVO<PageDTO<MerchantDTO>> queryMerchant(MerchantQuery query);
}
