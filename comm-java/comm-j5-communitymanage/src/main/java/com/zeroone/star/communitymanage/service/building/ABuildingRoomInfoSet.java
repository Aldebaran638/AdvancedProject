package com.zeroone.star.communitymanage.service.building;

import com.zeroone.star.project.dto.j5.community.building.*;
import com.zeroone.star.project.vo.j5.community.building.BuildingRoomVO;

public interface ABuildingRoomInfoSet {

    void setInfo_BuildingUnitDTO(BuildingRoomVO info, BuildingUnitDTO buildingUnitDTO);

    void setInfo_BusinessFloorDTO(BuildingRoomVO info, BusinessFloorDTO businessFloorDTO);

    void setInfo_BuildingRoomDTO_common(BuildingRoomVO info, BuildingRoomDTO buildingUnitDTO);

    void setInfo_TDictDTO(BuildingRoomVO info, TDictDTO tDictDTO);

    void setInfo_BuildingRoomDTO_owner(BuildingRoomVO info, BuildingOwnerDTO buildingOwnerDTO);

    void setInfo_FeeReceiptDTO(BuildingRoomVO info, FeeReceiptDTO feeReceiptDTO);
}
