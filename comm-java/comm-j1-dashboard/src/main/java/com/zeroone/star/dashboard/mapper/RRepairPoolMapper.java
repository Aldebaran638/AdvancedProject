package com.zeroone.star.dashboard.mapper;

import com.zeroone.star.dashboard.entity.RRepairPool;
import com.baomidou.mybatisplus.core.mapper.BaseMapper;
import org.apache.ibatis.annotations.Mapper;
import org.apache.ibatis.annotations.Select;

import java.util.List;
import java.util.Map;

/**
 * <p>
 *  Mapper 接口
 * </p>
 *
 * @author fayff
 * @since 2025-05-21
 */
@Mapper
public interface RRepairPoolMapper extends BaseMapper<RRepairPool> {

    @Select("SELECT repair_id, state FROM r_repair_pool WHERE community_id = #{communityId}")
    List<RRepairPool> selectAll(String communityId);

    /**
     * 优化查询：一次性获取所有小区的报修统计数据
     * 使用JOIN和GROUP BY避免N+1查询问题
     */
    @Select("SELECT " +
            "c.community_id, " +
            "c.name as community_name, " +
            "COUNT(rp.repair_id) as repair_count " +
            "FROM s_community c " +
            "LEFT JOIN r_repair_pool rp ON c.community_id = rp.community_id AND rp.status_cd = '0' " +
            "WHERE c.status_cd = '0' " +
            "GROUP BY c.community_id, c.name")
    List<Map<String, Object>> getCommunityRepairStatistics();
}
