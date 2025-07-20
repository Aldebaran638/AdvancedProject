package com.zeroone.star.communitymanage.service.parking;

import com.zeroone.star.project.query.j5.community.parking.ParkingQuery;
import com.zeroone.star.project.vo.j5.community.parking.ParkingVO;

import java.util.List;


/**
 * 车位结构图接口
 */
public interface IParkingService {
    List<ParkingVO> listparking(ParkingQuery query);
}
