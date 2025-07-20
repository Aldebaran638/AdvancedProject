package com.zeroone.star.parkmanage.mapper;

import com.baomidou.mybatisplus.core.mapper.BaseMapper;
import com.zeroone.star.parkmanage.entity.ParkingArea;
import com.zeroone.star.project.dto.j7.parkmanage.parkinglotmanage.GetParkingLotDTO;
import org.apache.ibatis.annotations.Mapper;

@Mapper
public interface ParkingLotManageMapper extends BaseMapper<ParkingArea> {
}
