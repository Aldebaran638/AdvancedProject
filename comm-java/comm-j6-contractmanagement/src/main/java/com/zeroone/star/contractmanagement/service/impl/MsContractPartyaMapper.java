package com.zeroone.star.contractmanagement.service.impl;

import com.zeroone.star.contractmanagement.entity.ContractPartya;
import com.zeroone.star.project.dto.j6.contractmanagement.contractpartya.ContractPartyaAddDTO;
import com.zeroone.star.project.vo.j6.contractmanagement.contractpartya.ContractPartyaVO;
import org.mapstruct.Mapper;
import org.mapstruct.Mapping;
import org.mapstruct.Mappings;
import org.mapstruct.factory.Mappers;

@Mapper(componentModel = "spring")
public interface MsContractPartyaMapper {

    MsContractPartyaMapper INSTANCE = Mappers.getMapper(MsContractPartyaMapper.class);

    // 从 ContractPartyaAddDTO 转换为 ContractPartya 实体
    ContractPartya addDtoToEntity(ContractPartyaAddDTO dto);

    // 从 ContractPartya 实体转换为 ContractPartyaVO
    @Mappings({
            @Mapping(source = "partyA", target = "partyA"),
            @Mapping(source = "AContacts", target = "AContacts"),
            @Mapping(source = "ALink", target = "ALink"),
            @Mapping(source = "partyaId", target = "partyaId"),
            @Mapping(source = "statusCd", target = "statusCd"),
            @Mapping(source = "storeId", target = "storeId")
    })
    ContractPartyaVO entityToVo(ContractPartya entity);
    ContractPartya toEntity(ContractPartyaAddDTO DTO);
}
