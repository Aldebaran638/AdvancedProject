package com.zeroone.star.merchantmanage.service.message;

import com.baomidou.mybatisplus.core.conditions.query.QueryWrapper;
import com.baomidou.mybatisplus.extension.plugins.pagination.Page;
import com.zeroone.star.merchantmanage.mapper.MerchantMapper;
import com.zeroone.star.project.dto.PageDTO;
import com.zeroone.star.project.dto.j3.merchantmanage.message.MerchantDTO;
import com.zeroone.star.project.query.j3.merchantmanage.message.MerchantQuery;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Service;
import org.springframework.util.StringUtils;

/**
 * @author wyr on 2025/5/24
 */
@Service
public class MerchantServiceImpl implements IMerchantService {

    @Autowired
    private MerchantMapper merchantMapper;

    /**
     * 查询商户信息
     *
     * @param query 查询条件
     * @return 商户信息列表
     */
    public PageDTO<MerchantDTO> listAllMerchants(MerchantQuery query) {
        Page<MerchantDTO> page = new Page<>(query.getPageIndex(), query.getPageSize());
        Page<MerchantDTO> resultPage = merchantMapper.listAllMerchants(page, query);
        return PageDTO.create(resultPage);
    }
}