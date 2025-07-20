package com.zeroone.star.project.j5.community.building;

import com.zeroone.star.project.dto.j5.community.building.BuildingStructureRoomDTO;
import com.zeroone.star.project.dto.j5.community.building.BuildingUnitDTO;
import com.zeroone.star.project.dto.j5.community.building.BusinessFloorDTO;
import com.zeroone.star.project.query.j5.community.building.BuildingAllQuery;
import com.zeroone.star.project.query.j5.community.building.BuildingRoomQuery;
import com.zeroone.star.project.query.j5.community.building.BuildingUnitQuery;
import com.zeroone.star.project.query.j5.community.building.BusinessFloorQuery;
import com.zeroone.star.project.vo.JsonVO;
import com.zeroone.star.project.vo.j5.community.building.BuildingRoomVO;

import java.util.List;

/**
 * <p>
 * 描述：楼栋结构图API接口
 *      浪子：获取指定单元楼栋结构————并待命协助其他组员未完成的接口与数据定义
 * </p>
 * @author 浪子
 * @version 1.0.0
 */
public interface BuildingApis {

    /**
     * 获取楼栋结构图接口
     * @param query 接受前面传的数据
     * @return
     */

    public JsonVO<List<BuildingRoomVO>> queryRoomStructure(BuildingRoomQuery query);

    public JsonVO<List<BusinessFloorDTO>> queryFloorStructure(BusinessFloorQuery query);

    public JsonVO<List<BuildingUnitDTO>> queryRoomStructureByFloorId(BuildingUnitQuery query);

    public JsonVO<BuildingStructureRoomDTO> queryBuildingStructureRoom(BuildingAllQuery query);
}
