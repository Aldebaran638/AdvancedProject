package com.zeroone.star.parkmanage.mapper;

import com.baomidou.mybatisplus.core.mapper.BaseMapper;
import com.zeroone.star.parkmanage.entity.BusinessParkingArea;
import com.zeroone.star.parkmanage.entity.ParkingArea;
import org.apache.ibatis.annotations.Mapper;

@Mapper
public interface BusinessParkingLotManageMapper extends BaseMapper<BusinessParkingArea> {
}
