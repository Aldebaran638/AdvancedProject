package com.zeroone.star.communitymanage.service.parking;

import com.zeroone.star.communitymanage.entity.parking.ParkingArea;
import com.baomidou.mybatisplus.extension.service.IService;

/**
 * <p>
 *  服务类
 * </p>
 *
 * @author hh
 * @since 2025-05-23
 */
public interface IParkingAreaService extends IService<ParkingArea> {

    /**
     * 从parking_area表获取area_num
     * @param paId
     * @return
     */
    ParkingArea getparkingarea(String paId);
}
