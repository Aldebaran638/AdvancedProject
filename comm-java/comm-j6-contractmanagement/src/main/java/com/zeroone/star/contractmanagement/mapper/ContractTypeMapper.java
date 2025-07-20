package com.zeroone.star.contractmanagement.mapper;

import com.zeroone.star.contractmanagement.entity.ContractType;
import com.baomidou.mybatisplus.core.mapper.BaseMapper;
import org.apache.ibatis.annotations.Mapper;

/**
 * <p>
 *  Mapper 接口
 * </p>
 *
 * @author 坤哥
 * @since 2025-05-18
 */
@Mapper
public interface ContractTypeMapper extends BaseMapper<ContractType> {

    Integer deleteByContractTypeId(String contractTypeId);
}
