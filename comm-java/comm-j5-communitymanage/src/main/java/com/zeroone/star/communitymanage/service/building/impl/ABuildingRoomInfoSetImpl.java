package com.zeroone.star.communitymanage.service.building.impl;

import com.zeroone.star.communitymanage.service.building.ABuildingRoomInfoSet;
import com.zeroone.star.project.dto.j5.community.building.*;
import com.zeroone.star.project.vo.j5.community.building.BuildingRoomVO;
import org.springframework.stereotype.Service;

@Service
public class ABuildingRoomInfoSetImpl implements ABuildingRoomInfoSet {

    @Override
    public void setInfo_BuildingUnitDTO(BuildingRoomVO info, BuildingUnitDTO buildingUnitDTO) {
        //优化 并注释
//        info.setUnitId(buildingUnitDTO.getUnitId());
//        info.setUnitNum(buildingUnitDTO.getUnitNum());
//        info.setFloorId(buildingUnitDTO.getFloorId());
    }

    @Override
    public void setInfo_BusinessFloorDTO(BuildingRoomVO info, BusinessFloorDTO businessFloorDTO) {
        //优化 并注释
        //info.setFloorNum(businessFloorDTO.getFloorNum());
    }


    @Override
    public void setInfo_BuildingRoomDTO_common(BuildingRoomVO info, BuildingRoomDTO buildingRoomDTO) {
        //获取共同属性 优化并注释
        //info.setApartment(buildingRoomDTO.getApartment());
        //info.setBuiltUpArea(buildingRoomDTO.getBuiltUpArea());
        //info.setCommunityId(buildingRoomDTO.getCommunityId());
        //info.setFeeCoefficient(buildingRoomDTO.getFeeCoefficient());
        info.setLayer(buildingRoomDTO.getLayer());
        //info.setRoomArea(buildingRoomDTO.getRoomArea());
        info.setRoomId(buildingRoomDTO.getRoomId());
        info.setRoomNum(buildingRoomDTO.getRoomNum());
        //info.setRoomRent(buildingRoomDTO.getRoomRent());
       // info.setRoomType(buildingRoomDTO.getRoomType());
        //info.setRoomSubType(buildingRoomDTO.getRoomSubType());
        //info.setSection(buildingRoomDTO.getSection());
        info.setState(buildingRoomDTO.getState());
        //info.setStatusCd(buildingRoomDTO.getStatusCd());
        //info.setCreateTime(buildingRoomDTO.getCreateTime());
    }

    @Override
    public void setInfo_TDictDTO(BuildingRoomVO info, TDictDTO tDictDTO) {
        //获取当前状态名称
        info.setStateName(tDictDTO.getStateName());
    }

    @Override
    public void setInfo_BuildingRoomDTO_owner(BuildingRoomVO info, BuildingOwnerDTO buildingOwnerDTO) {
        //获取业主信息
        info.setOwnerId(buildingOwnerDTO.getOwnerId());
        info.setOwnerName(buildingOwnerDTO.getOwnerName());
        //info.setIdCard(buildingOwnerDTO.getIdCard());
        //info.setLink(buildingOwnerDTO.getLink());
    }


    @Override
    public void setInfo_FeeReceiptDTO(BuildingRoomVO info, FeeReceiptDTO feeReceiptDTO) {
        //获取欠费信息
        info.setOweAmount(feeReceiptDTO.getOweAmount());
    }
}
