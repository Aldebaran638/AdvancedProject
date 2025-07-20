package com.zeroone.star.parkmanage.service;

import com.zeroone.star.parkmanage.entity.ParkingArea;
import com.baomidou.mybatisplus.extension.service.IService;
import com.zeroone.star.project.dto.PageDTO;
import com.zeroone.star.project.dto.j7.parkmanage.parkinglotmanage.GetParkingLotDTO;
import com.zeroone.star.project.dto.j7.parkmanage.parkinglotmanage.InsertParkingLotDTO;
import com.zeroone.star.project.dto.j7.parkmanage.parkinglotmanage.UpdateParkingLotDTO;
import com.zeroone.star.project.query.j7.parkmanage.parkinglotmanage.GetParkingLotQuery;

/**
 * <p>
 *  服务类
 * </p>
 *
 * @author wuven
 * @since 2025-05-26
 */
public interface IParkingAreaService extends IService<ParkingArea> {


    PageDTO<GetParkingLotDTO> listParkingLots(GetParkingLotQuery query);

    void insertParkingLot(InsertParkingLotDTO insertParkingLotDTO);

    void updateParkingLot(UpdateParkingLotDTO updateParkingLotDTO);
}
