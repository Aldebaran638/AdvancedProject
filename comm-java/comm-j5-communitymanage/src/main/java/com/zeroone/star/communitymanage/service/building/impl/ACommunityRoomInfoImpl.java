package com.zeroone.star.communitymanage.service.building.impl;

import com.zeroone.star.communitymanage.service.building.*;
import com.zeroone.star.project.dto.j5.community.building.*;
import com.zeroone.star.project.query.j5.community.building.BuildingRoomQuery;
import com.zeroone.star.project.vo.j5.community.building.BuildingRoomVO;
import org.springframework.stereotype.Service;

import javax.annotation.Resource;
import java.math.BigDecimal;
import java.util.*;

@Service
public class ACommunityRoomInfoImpl implements ACommunityRoomInfo {

    //共有信息
    @Resource
    IBuildingUnitService buildingUnit;
    @Resource
    IBusinessFloorService businessFloor;

    //特有信息
    @Resource
    IBuildingRoomService buildingRoom;

    @Resource
    ITDictService tDict;

    @Resource
    IBuildingOwnerRoomRelService buildingOwnerRoomRel;

    @Resource
    IBuildingOwnerService buildingOwnerService;

    @Resource
    IFeeReceiptService feeReceipt;

    @Resource
    ABuildingRoomInfoSet toSet;

    @Override
    public List<BuildingRoomVO> queryRoomStructure(BuildingRoomQuery query) {
        //根据query参数获取 unitId unitNum floorId
        //BuildingUnitDTO buildingUnitDTO = buildingUnit.getUnitInfoByUnitId(query.getUnitId());
        //floorNum
        //BusinessFloorDTO businessFloorDTO = businessFloor.getFloorNumByCommunityIdAndFloorId(query.getCommunityId(), buildingUnitDTO.getFloorId());
        //获取各个房间的信息
        List<BuildingRoomDTO> buildingRoomDTOList = buildingRoom.getRoomsByCommunityIdAndUnitId(query.getCommunityId(), query.getUnitId());
        //面对情况1 当小区id和单元id查询时候，但是获取的为空，则返回空
        List<BuildingRoomVO> buildingRoomVOList = new ArrayList<>();
        if(buildingRoomDTOList.isEmpty()){
            return null;
        }
        Map<String, TDictDTO> tDictMap = new HashMap<>();
        //都不能批量处理 否则会 未销售 已入住 已交房 装修中 只给4个状态数据 但有9个查询
        //只能对用map进行简单的优化
        //[发现这个obj_id存在的数据可能会没有数据 不能批量处理 比如有房子id 但是该表可能没有对应obj_id]
//        //其次批量获取roomId
//        List<String> roomIdList = buildingRoomDTO.stream()
//                        .map(BuildingRoomDTO::getRoomId)
//                        .collect(Collectors.toList());
//        //获取当前每个房子的欠费状况


        //批量获取
        for(int i = 0; i < buildingRoomDTOList.size(); i++){
            BuildingRoomVO  buildingRoomVO = new BuildingRoomVO();
            //赋值unitDTO FloorDTO RoomDTO_common 以及当前状态
            //进行优化 注释
            //toSet.setInfo_BuildingUnitDTO(buildingRoomVO, buildingUnitDTO);
            //toSet.setInfo_BusinessFloorDTO(buildingRoomVO, businessFloorDTO);
            toSet.setInfo_BuildingRoomDTO_common(buildingRoomVO, buildingRoomDTOList.get(i));
            //先查询是否有无 无则map加入一个 有则那现成的
            String state = buildingRoomVO.getState();
            TDictDTO tDictDTO = tDictMap.get(state);
            if(tDictDTO == null){
                tDictDTO = tDict.getNameByState(state);
                tDictMap.put(state, tDictDTO);
                toSet.setInfo_TDictDTO(buildingRoomVO, tDictDTO);
            }
            else{
                toSet.setInfo_TDictDTO(buildingRoomVO, tDictDTO);
            }

            //获取feeReceiptDTO
            FeeReceiptDTO feeReceiptDTO = feeReceipt.getFeeReceiptByRoomId(buildingRoomVO.getRoomId());
            if(feeReceiptDTO == null){
                buildingRoomVO.setOweAmount(BigDecimal.valueOf(0.0));
            }else{
                toSet.setInfo_FeeReceiptDTO(buildingRoomVO, feeReceiptDTO);
            }
            //是否继续
            if(tDictDTO.getStateName() == "未出售"){
                buildingRoomVOList.add(buildingRoomVO);
                continue;
            }
            //获取当前用户信息 并赋值给BuildingRoomVO 因为存在多个业主id 只截取一个id
            BuildingOwnerRoomRelDTO buildingOwnerRoomRelDTO = buildingOwnerRoomRel.getByRoomId(buildingRoomVO.getRoomId());
            if(buildingOwnerRoomRelDTO == null) {
                buildingRoomVOList.add(buildingRoomVO);
                continue;
            }
            //是否存在这个业主id
            BuildingOwnerDTO buildingOwnerDTO = buildingOwnerService.getOwnerInfoByOwnerId(buildingOwnerRoomRelDTO.getOwnerId());
            if(buildingOwnerDTO == null){
                buildingRoomVOList.add(buildingRoomVO);
                continue;
            }
            toSet.setInfo_BuildingRoomDTO_owner(buildingRoomVO, buildingOwnerDTO);
            buildingRoomVOList.add(buildingRoomVO);
        }
        //进行排序  building_room的 layer 和 room_num 从小到大排序 在同floor_id
        if(buildingRoomDTOList.size() == 1) return buildingRoomVOList;

        //防止出翔shangpu001 和 1-1-1进行捣乱
        buildingRoomVOList.sort(Comparator
                .comparingInt((BuildingRoomVO info) -> Integer.parseInt(info.getLayer()))
                .thenComparing(info -> {
                    String roomNum = info.getRoomNum();
                    // 提取第一个连续的数字串
                    String firstNumberGroup = roomNum.replaceAll("^.*?(\\d+).*?$", "$1");
                    return Integer.parseInt(firstNumberGroup);
                })
        );

        return buildingRoomVOList;
    }
}
