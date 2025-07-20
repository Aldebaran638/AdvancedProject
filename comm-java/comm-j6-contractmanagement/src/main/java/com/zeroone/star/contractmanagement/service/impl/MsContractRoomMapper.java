package com.zeroone.star.contractmanagement.service.impl;

import com.zeroone.star.contractmanagement.entity.ContractRoom;
import com.zeroone.star.project.dto.j6.contractmanagement.contractmodification.ContractRoomDTO;
import org.mapstruct.Mapper;

/*
 *描述 ：
 *Author:28768
 */
@Mapper(componentModel = "spring")
public interface MsContractRoomMapper {
    /**
     * ContractRoomDTO转为
     */
    ContractRoom ContractRoomDTOtoContractRoom(ContractRoomDTO contractRoomDTO);
}
