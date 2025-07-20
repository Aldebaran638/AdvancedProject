package com.zeroone.star.communitymanage.mapper.parking;

import com.zeroone.star.project.query.j5.community.parking.ParkingQuery;
import com.zeroone.star.project.vo.j5.community.parking.ParkingVO;
import org.apache.ibatis.annotations.Mapper;

import java.util.List;

@Mapper
public interface ParkingMapper {

     List<ParkingVO> selectpark(ParkingQuery query);

}
