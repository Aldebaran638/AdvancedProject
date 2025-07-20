package com.zeroone.star.communitymanage.mapper.building;

import com.zeroone.star.communitymanage.entity.building.BuildingUnit;
import com.baomidou.mybatisplus.core.mapper.BaseMapper;
import com.zeroone.star.project.dto.j5.community.building.BuildingUnitDTO;
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
public interface BuildingUnitMapper extends BaseMapper<BuildingUnit> {
    /**
     * 根据 unit_id 获取 BuildingUnitDTO 数据
     * @param unitId 单位ID
     * @return BuildingUnitDTO 对象
     */
    BuildingUnitDTO getUnitInfoByUnitId(String unitId);

     /**
     * 根据 floorId 获取 BuildingUnitDTO 数据
     * @param floorId 楼id
     * @return BuildingUnitDTO 列表
     */
     List<BuildingUnitDTO> getUnitInfoByFloorId(String floorId);

    /**
     * 查询buildingUnit表的unit_num单元编号
     * @param buildingunit
     * @return
     */
    @Select("select unit_num,floor_id from building_unit where unit_id = #{unitId} ")
    BuildingUnit listunitnum(BuildingUnit buildingunit);
}
