package com.zeroone.star.communitymanage.service.parking.impl;

import com.zeroone.star.communitymanage.entity.parking.ParkingArea;
import com.zeroone.star.communitymanage.mapper.parking.ParkingAreaMapper;
import com.zeroone.star.communitymanage.service.parking.IParkingAreaService;
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
public class ParkingAreaServiceImpl extends ServiceImpl<ParkingAreaMapper, ParkingArea> implements IParkingAreaService {

    @Autowired
    private ParkingAreaMapper parkingAreaMapper;

    /**
     * 从parking_area获取area_num
     * @param paId
     * @return
     */
    @Override
    public ParkingArea getparkingarea(String paId) {
        ParkingArea parkingArea = parkingAreaMapper.listparkingarea(paId);
        return parkingArea;
    }
}
