package com.zeroone.star.communitymanage.service.parking.impl;

import com.zeroone.star.communitymanage.entity.parking.OwnerCar;
import com.zeroone.star.communitymanage.mapper.parking.OwnerCarMapper;
import com.zeroone.star.communitymanage.service.parking.IOwnerCarService;
import com.baomidou.mybatisplus.extension.service.impl.ServiceImpl;
import com.zeroone.star.project.query.j5.community.parking.ParkingQuery;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Service;

import java.util.List;

/**
 * <p>
 *  服务实现类
 * </p>
 *
 * @author hh
 * @since 2025-05-23
 */
@Service
public class OwnerCarServiceImpl extends ServiceImpl<OwnerCarMapper, OwnerCar> implements IOwnerCarService {

    @Autowired
    private MsMapper msMapper;

    @Autowired
    private OwnerCarMapper ownerCarMapper;

    @Override
    public List<OwnerCar> listcar(ParkingQuery query) {
        OwnerCar ownerCar = msMapper.toOwnerCar(query);
        List<OwnerCar> cars = ownerCarMapper.selectcar(ownerCar);
        return cars;
    }
}
