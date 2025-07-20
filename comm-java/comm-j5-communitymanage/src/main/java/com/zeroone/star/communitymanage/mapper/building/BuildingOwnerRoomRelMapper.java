package com.zeroone.star.communitymanage.mapper.building;

import com.zeroone.star.communitymanage.entity.building.BuildingOwnerRoomRel;
import com.baomidou.mybatisplus.core.mapper.BaseMapper;
import com.zeroone.star.project.dto.j5.community.building.BuildingOwnerRoomRelDTO;
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
public interface BuildingOwnerRoomRelMapper extends BaseMapper<BuildingOwnerRoomRel> {
    BuildingOwnerRoomRelDTO getByRoomId(String roomId);

    @Select("select room_id from building_owner_room_rel where owner_id =#{ownerId}")
    List<BuildingOwnerRoomRel> selectroomid(String ownerId);
}
