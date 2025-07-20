package com.zeroone.star.communitymanage.service.parking;

import com.zeroone.star.communitymanage.entity.parking.OwnerCar;
import com.baomidou.mybatisplus.extension.service.IService;
import com.zeroone.star.project.query.j5.community.parking.ParkingQuery;

import java.util.List;

/**
 * <p>
 *  OwnerCar服务层
 * </p>
 *
 * @author hh
 * @since 2025-05-23
 */
public interface IOwnerCarService extends IService<OwnerCar> {

    List<OwnerCar> listcar(ParkingQuery query);
}
