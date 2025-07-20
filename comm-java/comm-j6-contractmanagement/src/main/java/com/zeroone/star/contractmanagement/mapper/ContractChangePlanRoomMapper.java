package com.zeroone.star.contractmanagement.mapper;


import com.baomidou.mybatisplus.core.mapper.BaseMapper;
import com.zeroone.star.contractmanagement.entity.ContractChangePlanRoom;
import org.apache.ibatis.annotations.Mapper;

import java.util.List;

@Mapper
public interface ContractChangePlanRoomMapper extends BaseMapper<ContractChangePlanRoom> {
    int insertBatchSomeColumn(List<ContractChangePlanRoom> contractChangePlanRoomList);

}
