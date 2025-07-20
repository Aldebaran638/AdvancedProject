package com.zeroone.star.dashboard.mapper;

import com.baomidou.mybatisplus.core.mapper.BaseMapper;
import com.zeroone.star.dashboard.entity.BuildingOwner;
import com.zeroone.star.dashboard.entity.BusinessCommunityInfo;
import org.apache.ibatis.annotations.Mapper;

import java.util.List;

/**
 * <p>
 *  Mapper 接口
 * </p>
 *
 * @author fayff
 * @since 2025-05-21
 */
@Mapper
public interface BusinessCommunityInfoMapper extends BaseMapper<BusinessCommunityInfo> {


    List<BuildingOwner> selectAllCommunityIdByUserId(String userId);

    List<BuildingOwner> selectAllUserIdByCommunityId(String communityId);

    Integer getBuildingRoomCount(String userId);

    Integer getRegisteredCount(String userId);

    Integer getBuildingUnitCount(String userId);

    Integer getOwnerCarCount(String communityId);

    Integer getParkingSpaceCount(String communityId);

    Integer getSStoreCount(String communityId);


}
