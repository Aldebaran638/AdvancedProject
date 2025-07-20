package com.zeroone.star.dashboard.mapper;

import com.zeroone.star.dashboard.entity.BuildingRoom;
import com.baomidou.mybatisplus.core.mapper.BaseMapper;
import org.apache.ibatis.annotations.Mapper;

/**
 * <p>
 *  Mapper 接口
 * </p>
 *
 * @author fayff
 * @since 2025-05-21
 */
@Mapper
public interface BuildingRoomMapper extends BaseMapper<BuildingRoom> {

    Integer getBuildingRoomCount(String communityId);

}
