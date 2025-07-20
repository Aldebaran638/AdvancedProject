package com.zeroone.star.communityinfo.mapper;

import com.zeroone.star.communityinfo.entity.SCommunity;
import com.baomidou.mybatisplus.core.mapper.BaseMapper;
import org.apache.ibatis.annotations.Mapper;
import org.apache.ibatis.annotations.Select;

import java.util.Map;

/**
 * <p>
 *  Mapper 接口
 * </p>
 *
 * @author j5-guoba
 * @since 2025-05-23
 */
@Mapper
public interface CommunityInfoUpdateMapper extends BaseMapper<SCommunity> {
    @Select("select lon, lat from city_area where area_code = #{areaCode}")
    Map<Object, Object> listLonAndLatByAreaCode(String areaCode);
}
