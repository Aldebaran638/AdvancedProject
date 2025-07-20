package com.zeroone.star.contractmanagement.mapper;

import com.baomidou.mybatisplus.core.mapper.BaseMapper;
import com.zeroone.star.contractmanagement.entity.ContractTypeSpec;
import org.apache.ibatis.annotations.Mapper;


/*
 *描述 ：
 *Author:28768
 */
@Mapper
public interface ContractTypeSpecMapper extends BaseMapper<ContractTypeSpec> {
    void addContractExtInfo(ContractTypeSpec entity);

    void modifyContractExtInfo(ContractTypeSpec entity);
}
