package com.zeroone.star.communitymanage.mapper.building;

import com.zeroone.star.communitymanage.entity.building.BuildingOwner;
import com.baomidou.mybatisplus.core.mapper.BaseMapper;
import com.zeroone.star.project.dto.j5.community.building.BuildingOwnerDTO;
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
public interface BuildingOwnerMapper extends BaseMapper<BuildingOwner> {
    BuildingOwnerDTO getOwnerInfoByOwnerId(String ownerId);

    /**
     * 获取building_owner表中的name
     * @param ownerId
     * @return
     */
    @Select("select name from building_owner where member_id = #{ownerId}")
    List<BuildingOwner> listname(String ownerId);
}
