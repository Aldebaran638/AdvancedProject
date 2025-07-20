package com.zeroone.star.communitymanage.mapper.building;

import com.zeroone.star.communitymanage.entity.building.BusinessFloor;
import com.baomidou.mybatisplus.core.mapper.BaseMapper;
import com.zeroone.star.project.dto.j5.community.building.BusinessFloorDTO;
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
public interface BusinessFloorMapper extends BaseMapper<BusinessFloor> {
    /**
     * 根据 communityId 和 floorId 获取楼层信息
     * @param communityId 社区ID
     * @param floorId 楼层ID
     * @return 包含 floorNum 的 BusinessFloorDTO 对象
     */
    BusinessFloorDTO getFloorNumByCommunityIdAndFloorId(String communityId, String floorId);

     /**
     * 根据 communityId 获取楼层信息
     * @param communityId 社区ID
     * @return 列表包含 floorNum 的 BusinessFloorDTO 列表
     */
    List<BusinessFloorDTO> getFloorDTOByCommunityId(String communityId);

    @Select("select floor_num from business_floor where floor_id = #{floorId}")
    BusinessFloor listfloornum(BusinessFloor businessFloor);
}
