package com.zeroone.star.parkmanage.service;

import com.baomidou.mybatisplus.extension.service.IService;
import com.zeroone.star.parkmanage.entity.ParkingArea;
import com.zeroone.star.project.dto.j7.parkmanage.parkinglotmanage.GetParkingLotDTO;

public interface IParkingLotManageService extends IService<ParkingArea> {

    void removeById(String paId);
}
