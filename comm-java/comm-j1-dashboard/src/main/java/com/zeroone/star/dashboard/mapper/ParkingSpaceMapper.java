package com.zeroone.star.dashboard.mapper;

import com.zeroone.star.dashboard.entity.ParkingSpace;
import com.baomidou.mybatisplus.core.mapper.BaseMapper;
import org.apache.ibatis.annotations.Mapper;

/**
 * <p>
 *  Mapper 接口
 * </p>
 *
 * @author wunianwufeng
 * @since 2025-05-27
 */
@Mapper
public interface ParkingSpaceMapper extends BaseMapper<ParkingSpace> {


    Integer getParkingSpaceCount(long communityId);

}
