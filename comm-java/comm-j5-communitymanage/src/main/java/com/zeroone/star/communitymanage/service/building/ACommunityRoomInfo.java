package com.zeroone.star.communitymanage.service.building;

import com.zeroone.star.project.query.j5.community.building.BuildingRoomQuery;
import com.zeroone.star.project.vo.j5.community.building.BuildingRoomVO;

import java.util.List;

public interface ACommunityRoomInfo {
    List<BuildingRoomVO> queryRoomStructure( BuildingRoomQuery query);
}
