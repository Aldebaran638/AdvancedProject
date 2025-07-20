package com.zeroone.star.parkmanage.service;

import com.zeroone.star.parkmanage.entity.OwnerCar;
import com.baomidou.mybatisplus.extension.service.IService;
import com.zeroone.star.parkmanage.entity.OwnerCar1;
import com.zeroone.star.project.dto.PageDTO;
import com.zeroone.star.project.dto.j7.parkmanage.ownervehicle.AddMemberVehicleDTO;
import com.zeroone.star.project.dto.j7.parkmanage.ownervehicle.MemberVehicleDTO;
import com.zeroone.star.project.query.j7.parkmanage.ownervehicle.MemberVehicleQuery;

/**
 * <p>
 *  服务类
 * </p>
 *
 * @author daimon
 * @since 2025-05-31
 */
public interface IOwnerCarService extends IService<OwnerCar1> {

    OwnerCar1 saveAddToOwnerCar(AddMemberVehicleDTO addMemberVehicleDTO);

    PageDTO<MemberVehicleDTO> listMemberVehicle(MemberVehicleQuery query);
}
