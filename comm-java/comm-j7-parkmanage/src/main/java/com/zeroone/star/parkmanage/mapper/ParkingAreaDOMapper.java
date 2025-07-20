package com.zeroone.star.parkmanage.mapper;

import com.baomidou.mybatisplus.core.mapper.BaseMapper;
import com.zeroone.star.parkmanage.entity.ParkingAreaDO;
import org.apache.ibatis.annotations.Select;

import java.util.List;

public interface ParkingAreaDOMapper extends BaseMapper<ParkingAreaDO> {

    /**
     * 查询停车场编号列表
     * @param parkingAreaDO 查询条件
     * @return 停车场编号列表
     */
    @Select("SELECT num FROM parking_area WHERE type_cd = #{typeCd} AND community_id = #{communityId} AND status_cd = #{statusCd}")
    List<String> selectParkingAreaNums(ParkingAreaDO parkingAreaDO);
}