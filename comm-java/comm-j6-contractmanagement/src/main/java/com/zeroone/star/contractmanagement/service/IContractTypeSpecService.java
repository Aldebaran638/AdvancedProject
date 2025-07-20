package com.zeroone.star.contractmanagement.service;

import com.baomidou.mybatisplus.extension.service.IService;
import com.zeroone.star.contractmanagement.entity.ContractTypeSpec;
import com.zeroone.star.project.dto.PageDTO;
import com.zeroone.star.project.query.j6.contractmanagement.contracttype.ContractTypeSpecQuery;
import com.zeroone.star.project.vo.j6.contractmanagement.contracttype.ContractTypeSpecVO;


/*
 *描述 ：
 *Author:28768
 */
public interface IContractTypeSpecService extends IService<ContractTypeSpec> {
    public boolean deleteSpec(String specCd);
    PageDTO<ContractTypeSpecVO> listContractTypeSpec(ContractTypeSpecQuery condition);

    void addContractExtInfo(ContractTypeSpec contractExtType);
    void modifyContractExtInfo(ContractTypeSpec contractExtType);
}
