package com.zeroone.star.communitymanage.service.parking.impl;

import com.zeroone.star.communitymanage.entity.parking.ParkingSpace;
import com.zeroone.star.communitymanage.mapper.parking.ParkingSpaceMapper;
import com.zeroone.star.communitymanage.service.parking.IParkingSpaceService;
import com.baomidou.mybatisplus.extension.service.impl.ServiceImpl;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Service;

/**
 * <p>
 *  服务实现类
 * </p>
 *
 * @author hh
 * @since 2025-05-23
 */
@Service
public class ParkingSpaceServiceImpl extends ServiceImpl<ParkingSpaceMapper, ParkingSpace> implements IParkingSpaceService {

    @Autowired
    private ParkingSpaceMapper parkingSpaceMapper;

    /**
     * 根据ps_id获取num和pa_id
     * @param psId
     * @return
     */
    @Override
    public ParkingSpace getparkingspace(String psId) {
       ParkingSpace parkingSpace = parkingSpaceMapper.listparkingspace(psId);
        return parkingSpace;
    }
}
