package com.zeroone.star.merchantmanage.mapper;

import com.baomidou.mybatisplus.core.conditions.query.QueryWrapper;
import com.baomidou.mybatisplus.core.mapper.BaseMapper;
import com.baomidou.mybatisplus.extension.plugins.pagination.Page;
import com.zeroone.star.merchantmanage.entity.SStoreDO;
import com.zeroone.star.project.dto.j3.merchantmanage.message.MerchantDTO;
import com.zeroone.star.project.query.j3.merchantmanage.message.MerchantQuery;
import org.apache.ibatis.annotations.Mapper;
import org.apache.ibatis.annotations.Param;

/**
 * @author wyr on 2025/5/24
 */
@Mapper
public interface MerchantMapper{
    /**
     * 查询商户信息
     * @param page
     * @param query 查询条件
     * @return 商户信息列表
     */
    Page<MerchantDTO> listAllMerchants(@Param("page") Page<MerchantDTO> page, @Param("query") MerchantQuery query);
}
