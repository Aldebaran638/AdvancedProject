package com.zeroone.star.communitymanage.service.parking;

import com.zeroone.star.communitymanage.entity.parking.ParkingSpace;
import com.baomidou.mybatisplus.extension.service.IService;

/**
 * <p>
 *  服务类
 * </p>
 *
 * @author hh
 * @since 2025-05-23
 */
public interface IParkingSpaceService extends IService<ParkingSpace> {

    /**
     * 获取pa_id和num接口
     * @param psId
     * @return
     */
    ParkingSpace getparkingspace(String psId);
}
