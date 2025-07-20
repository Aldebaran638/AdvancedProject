package com.zeroone.star.dashboard.mapper;

import com.baomidou.mybatisplus.core.mapper.BaseMapper;
import com.zeroone.star.dashboard.entity.BusinessCommunity;
import org.apache.ibatis.annotations.Mapper;
import org.apache.ibatis.annotations.Select;

/**
 * <p>
 *  Mapper 接口
 * </p>
 *
 * @author wunianwufeng
 * @since 2025-05-30
 */
@Mapper
public interface BusinessCommunityMapper extends BaseMapper<BusinessCommunity> {


    @Select("select community_id from business_community where tel=#{tel}")
    String getCommunityIdByTel(String tel);

}
