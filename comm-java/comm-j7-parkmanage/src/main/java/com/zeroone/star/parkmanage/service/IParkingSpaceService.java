package com.zeroone.star.parkmanage.service;

import com.zeroone.star.parkmanage.entity.ParkingSpace;
import com.baomidou.mybatisplus.extension.service.IService;

/**
 * <p>
 *  服务类
 * </p>
 *
 * @author daimon
 * @since 2025-06-02
 */
public interface IParkingSpaceService extends IService<ParkingSpace> {
    String getPsNum(String communityId,String bId);
}
