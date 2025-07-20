package com.zeroone.star.communitymanage.mapper.building;

import com.zeroone.star.communitymanage.entity.building.BuildingRoom;
import com.baomidou.mybatisplus.core.mapper.BaseMapper;
import com.zeroone.star.project.dto.j5.community.building.BuildingRoomDTO;
import org.apache.ibatis.annotations.Mapper;
import org.apache.ibatis.annotations.Select;

import java.util.List;

/**
 * <p>
 *  Mapper 接口
 * </p>
 *
 * @author langzi
 * @since 2025-05-23
 */
@Mapper
public interface BuildingRoomMapper extends BaseMapper<BuildingRoom> {
    /**
     * 根据社区ID和单元ID查询房间列表
     * @param communityId 社区ID
     * @param unitId 单元ID
     * @return List<BuildingRoomDTO>
     */
    List<BuildingRoomDTO> getRoomsByCommunityIdAndUnitId(
            String communityId,
            String unitId
    );

    @Select("select room_num,unit_id from building_room where room_id =#{roomId}")
    BuildingRoom listroom(String roomId);
}
