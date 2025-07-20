package com.zeroone.star.contractmanagement.service.impl;

import com.zeroone.star.contractmanagement.entity.ContractType;
import com.zeroone.star.project.dto.j6.contractmanagement.contracttype.ContractTypeDTO;
import com.zeroone.star.project.vo.j6.contractmanagement.contracttype.ContractTypeNameVO;
import com.zeroone.star.project.vo.j6.contractmanagement.contracttype.ContractTypeVO;
import org.mapstruct.Mapper;

/*
 *描述 ：ContractType对象转换成其他类
 *Author:28768
 */
@Mapper(componentModel = "spring")
public interface MsContractTypeMapper {
    /**
     * 将ContractType对象转换为ContractTypeVO对象
     * @param contractType
     * @return
     */
    ContractTypeVO toContractTypeVO(ContractType contractType);

    /**
     * 将ContractType对象转换为ContractTypeNameVO对象
     * @param contractType
     * @return
     */
    ContractTypeNameVO toContractTypeNameVO(ContractType contractType);

    /**
     * 将ContractTypeDTO对象转换为ContractType对象
     * @param dto
     * @return
     */
    ContractType toContractType(ContractTypeDTO dto);
}
