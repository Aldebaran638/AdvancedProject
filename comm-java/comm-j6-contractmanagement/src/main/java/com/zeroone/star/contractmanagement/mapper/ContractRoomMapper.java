package com.zeroone.star.contractmanagement.mapper;


import com.baomidou.mybatisplus.core.mapper.BaseMapper;
import com.zeroone.star.contractmanagement.entity.ContractRoom;
import org.apache.ibatis.annotations.Delete;
import org.apache.ibatis.annotations.Mapper;

import java.util.List;

@Mapper
public interface ContractRoomMapper extends BaseMapper<ContractRoom> {
    void insertBatchSomeColumn(List<ContractRoom> contractRoomListADD);

    @Delete("delete  from contract_room where contract_id=#{contractId}")
    int deleteByContractId(String contractId);
}
