package com.zeroone.star.parkmanage.service.impl;

import cn.hutool.core.bean.BeanUtil;
import com.baomidou.mybatisplus.core.conditions.query.QueryWrapper;
import com.baomidou.mybatisplus.core.toolkit.IdWorker;
import com.baomidou.mybatisplus.extension.plugins.pagination.Page;
import com.zeroone.star.parkmanage.entity.OwnerCar;
import com.zeroone.star.parkmanage.entity.OwnerCar1;
import com.zeroone.star.parkmanage.mapper.OwnerCarMapper;
import com.zeroone.star.parkmanage.service.*;
import com.baomidou.mybatisplus.extension.service.impl.ServiceImpl;
import com.zeroone.star.project.dto.PageDTO;
import com.zeroone.star.project.dto.j7.parkmanage.ownervehicle.AddMemberVehicleDTO;
import com.zeroone.star.project.dto.j7.parkmanage.ownervehicle.MemberVehicleDTO;
import com.zeroone.star.project.query.j7.parkmanage.ownervehicle.MemberVehicleQuery;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Service;

import java.sql.Struct;

/**
 * <p>
 *  服务实现类
 * </p>
 *
 * @author daimon
 * @since 2025-05-31
 */
@Service
public class OwnerCarServiceImpl extends ServiceImpl<OwnerCarMapper, OwnerCar1> implements IOwnerCarService {

    @Autowired
    MsOwnerCarMapper ms;

    @Autowired
    IBuildingRoomService buildingRoomService;

    @Autowired
    IOwnerAppUserService ownerAppUserService;

    @Autowired
    IParkingAreaService1 iParkingAreaService1;

    @Autowired
    IParkingSpaceService parkingSpaceService;

    @Override
    public OwnerCar1 saveAddToOwnerCar(AddMemberVehicleDTO addMemberVehicleDTO) {
        OwnerCar1 ownerCar = ms.addDtoToOwnerCar1(addMemberVehicleDTO);
        ownerCar.setBId(IdWorker.getIdStr());
        ownerCar.setMemberId(IdWorker.getIdStr());
        String carId = ownerCar.getCarId();

        QueryWrapper<OwnerCar1> queryWrapper = new QueryWrapper<>();
        queryWrapper.eq("car_id", carId).eq("member_id",addMemberVehicleDTO.getMemberId());
        OwnerCar1 car = baseMapper.selectOne(queryWrapper);

        ownerCar.setOwnerId(car.getOwnerId());
        ownerCar.setPsId(car.getPsId());
        ownerCar.setUserId(car.getUserId());
        ownerCar.setStatusCd("0");
        ownerCar.setCommunityId(car.getCommunityId());
        ownerCar.setStartTime(car.getStartTime());
        ownerCar.setEndTime(car.getEndTime());
        ownerCar.setState("1001");
        ownerCar.setCarTypeCd("1002");
        ownerCar.setLeaseType("H");
        return ownerCar;
    }

    @Override
    public PageDTO<MemberVehicleDTO> listMemberVehicle(MemberVehicleQuery query) {
        Page<OwnerCar1> page = new Page<>(query.getPageIndex(), query.getPageSize());
        QueryWrapper<OwnerCar1> wrapper = new QueryWrapper<>();
        wrapper.eq("car_id", query.getCarId()).eq("member_id",query.getMemberId());
        Page<OwnerCar1> pageResult = baseMapper.selectPage(page, wrapper);

        return PageDTO.create(pageResult, ownerCar -> {
            MemberVehicleDTO dto = new MemberVehicleDTO();
            BeanUtil.copyProperties(ownerCar, dto);

            dto.setStartTime(ownerCar.getStartTime() != null ? ownerCar.getStartTime().toString() : null);
            dto.setEndTime(ownerCar.getEndTime() != null ? ownerCar.getEndTime().toString() : null);
            dto.setState(ownerCar.getState());

            QueryWrapper<OwnerCar1> queryWrapper = new QueryWrapper<>();
            queryWrapper.eq("car_id", query.getCarId()).eq("member_id",query.getMemberId());
            OwnerCar1 car = baseMapper.selectOne(queryWrapper);

            String communityId = car.getCommunityId();
            String bId = car.getBId();
            String memberId = query.getMemberId();
            dto.setRoomNum(buildingRoomService.getRoomNum(communityId,bId));
            dto.setUserName(ownerAppUserService.getUserName(communityId,memberId));
            dto.setUserTel(ownerAppUserService.getUserTel(communityId,memberId));
            dto.setPaNum(parkingSpaceService.getPsNum(communityId,bId));
            dto.setPsNum(iParkingAreaService1.getPaNum(communityId,bId));
            return dto;
        });
    }


}
