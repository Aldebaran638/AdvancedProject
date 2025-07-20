package com.zeroone.star.contractmanagement.service.impl;

import com.zeroone.star.contractmanagement.entity.ContractTypeTemplate;
import com.zeroone.star.project.vo.j6.contractmanagement.contracttype.ContractTypeTemplateVO;
import org.mapstruct.Mapper;

@Mapper(componentModel = "spring")
public interface MsContractTypeTemplateMapper {
    ContractTypeTemplateVO toContractTypeTemplateVO(ContractTypeTemplate contractTypeTemplate);
}
