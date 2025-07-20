package com.zeroone.star.contractmanagement.service.impl;

import com.zeroone.star.contractmanagement.entity.Contract;
import com.zeroone.star.project.dto.j6.contractmanagement.draftcontract.ContractDTO;
import com.zeroone.star.project.dto.j6.contractmanagement.expiredcontract.ExpiredContractDTO;
import com.zeroone.star.project.vo.j6.contractmanagement.draftcontract.ContractChangeListVO;
import com.zeroone.star.project.vo.j6.contractmanagement.draftcontract.ContractListVO;
import com.zeroone.star.project.vo.j6.contractmanagement.draftcontract.ContractSelectVO;
import org.mapstruct.Mapper;

@Mapper(componentModel = "spring")
public interface MsContractMapper {
    /**
     * 将实体类转换为DTO
     * @param contractDo 实体类
     * @return 转换结果
     */
    ContractSelectVO contractDoTOcontractSelectVO (Contract contractDo);
    /**
     * 将Contract对象转换为ContractlistVO对象
     * @param contractlistVo
     * @return
     */
    ContractListVO toContractVO(Contract contractlistVo);

    ContractChangeListVO toContractChangeListVO(Contract contractChangeListVO);

    /**
     * 将dto转为实体类
     */
    Contract contractDTOtocontractDo(ContractDTO contractDTO);


    /**
     * dto 转 实体类Contract
     * @param dto
     * @return
     */
    public Contract ExpiredContractDtoToContract(ExpiredContractDTO dto);

    /**
     * 实体类Contract 转 dto
     * @param contract
     * @return
     */
    public ExpiredContractDTO contractToExpiredContractDto(Contract contract);

}
