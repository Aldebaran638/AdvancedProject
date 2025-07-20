package com.zeroone.star.communitymanage.controller;

import com.zeroone.star.communitymanage.service.building.ACommunityRoomInfo;
import com.zeroone.star.communitymanage.service.building.IBuildingUnitService;
import com.zeroone.star.communitymanage.service.building.IBusinessFloorService;
import com.zeroone.star.project.dto.j5.community.building.*;
import com.zeroone.star.project.j5.community.building.BuildingApis;
import com.zeroone.star.project.query.j5.community.building.BuildingAllQuery;
import com.zeroone.star.project.query.j5.community.building.BuildingRoomQuery;
import com.zeroone.star.project.query.j5.community.building.BuildingUnitQuery;
import com.zeroone.star.project.query.j5.community.building.BusinessFloorQuery;
import com.zeroone.star.project.vo.JsonVO;
import com.zeroone.star.project.vo.j5.community.building.BuildingRoomVO;
import io.swagger.annotations.Api;
import io.swagger.annotations.ApiOperation;
import org.springframework.validation.annotation.Validated;
import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RestController;

import javax.annotation.Resource;
import java.util.*;

/**
 * <p>
 * 描述：楼栋结构图的控制器
 * </p>
 * @author 浪子
 * @version 1.0.0
 */
@RestController
@RequestMapping("/j5-community/building")
@Api(tags = "楼栋结构图")
public class BuildingController implements BuildingApis {
    //共有信息
    @Resource
    IBuildingUnitService buildingUnit;
    @Resource
    IBusinessFloorService businessFloor;

    @Resource
    ACommunityRoomInfo aCommunityRoomInfo;

    @ApiOperation("获取指定单元楼栋结构")
    @Override
    @GetMapping("query-building-room")
    public JsonVO<List<BuildingRoomVO>> queryRoomStructure(@Validated BuildingRoomQuery query) {
        List<BuildingRoomVO> buildingRoomVOList = aCommunityRoomInfo .queryRoomStructure(query);
        //赋值分页字段 后期可能要修改
        return JsonVO.success(buildingRoomVOList);
    }

    @ApiOperation("获取指定小区结构")
    @GetMapping("query-business-floor")
    @Override
    public JsonVO<List<BusinessFloorDTO>> queryFloorStructure(@Validated BusinessFloorQuery query) {
        if(query == null){
            return JsonVO.fail(null);
        }
        List<BusinessFloorDTO> businessFloorDTOList = businessFloor.getFloorDTOByCommunityId(query.getCommunityId());
        return JsonVO.success(businessFloorDTOList);
    }

    @ApiOperation("获取指定社区楼栋结构")
    @GetMapping("query-building-unit")
    @Override
    public JsonVO<List<BuildingUnitDTO>> queryRoomStructureByFloorId(@Validated BuildingUnitQuery query) {
        if(query == null){
             return JsonVO.fail(null);
        }
        List<BuildingUnitDTO > buildingUnitDTOList = buildingUnit.getUnitInfoByFloorId(query.getFloorId());
        return JsonVO.success(buildingUnitDTOList);
    }


    /**
     *  获取一次性获取所有结构
     * @param query
     * @return
     */
    @ApiOperation("获取一次性获取所有结构")
    @GetMapping("query-building-structure")
    public JsonVO<BuildingStructureRoomDTO> queryBuildingStructureRoom(@Validated BuildingAllQuery query) {
        if(query == null){
            return JsonVO.fail(null);
        }
        //创建 BuildingStructureRoomDTO 对象，并设置相关属性
        BuildingStructureRoomDTO buildingStructureRoomDTO = new BuildingStructureRoomDTO();
        buildingStructureRoomDTO.setCommunityId(query.getCommunityId());
        //获取所有楼栋信息 通过小区id
        List<BusinessFloorDTO> businessFloorDTOList = businessFloor.getFloorDTOByCommunityId(query.getCommunityId());
        buildingStructureRoomDTO.setBusinessFloorDTOList(businessFloorDTOList);
        //遍历所有楼栋信息
        for(BusinessFloorDTO businessFloorDTO : businessFloorDTOList){
             // 获取所有单元信息
             List<BuildingUnitDTO> buildingUnitDTOList = buildingUnit.getUnitInfoByFloorId(businessFloorDTO.getFloorId());
             // 设置单元信息
             businessFloorDTO.setBuildingUnitDTOList(buildingUnitDTOList);
             for(BuildingUnitDTO buildingUnitDTO : buildingUnitDTOList){
                 // 生成查询房间信息的查询对象
                 BuildingRoomQuery buildingRoomQuery = new BuildingRoomQuery();
                 buildingRoomQuery.setUnitId(buildingUnitDTO.getUnitId());
                 buildingRoomQuery.setCommunityId(query.getCommunityId());
                 buildingRoomQuery.setPageIndex(1);
                 buildingRoomQuery.setPageSize(10);
                 // 获取所有房间信息
                 List<BuildingRoomVO> buildingRoomVOList = aCommunityRoomInfo.queryRoomStructure(buildingRoomQuery);
                 buildingUnitDTO.setBuildingRoomVOList(buildingRoomVOList);
             }
        }
        // 返回成功信息，包含查询到的建筑物结构信息
        return JsonVO.success(buildingStructureRoomDTO);
     }
}


