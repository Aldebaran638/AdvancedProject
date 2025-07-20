package com.zeroone.star.dashboard.mapper;

import com.zeroone.star.dashboard.entity.SCommunity;
import com.baomidou.mybatisplus.core.mapper.BaseMapper;
import org.apache.ibatis.annotations.Mapper;
import org.apache.ibatis.annotations.Select;

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
public interface SCommunityMapper extends BaseMapper<SCommunity> {

    /**
     * 获取小区数量
     */
    @Select("SELECT COUNT(*) FROM s_community WHERE status_cd = '0'")
    Long getCommunityCount();

    /**
     * 获取业主数量
     */
    @Select("SELECT COUNT(*) FROM building_owner WHERE status_cd = '0' AND owner_type_cd = '1001'")
    Long getOwnerCount();

    /**
     * 获取车辆数量
     */
    @Select("SELECT COUNT(*) FROM owner_car WHERE status_cd = '0'")
    Long getCarCount();

    /**
     * 获取房屋统计数据（房屋总数和商铺数）
     */
    @Select("SELECT " +
            "COUNT(*) as house_count, " +
            "SUM(CASE WHEN room_type = '2020602' THEN 1 ELSE 0 END) as commercial_house_count " +
            "FROM building_room WHERE status_cd = '0'")
    Map<String, Object> getHouseStatistics();

    /**
     * 优化查询：一次性获取商户统计数据
     * 使用CASE WHEN合并多个商户类型统计
     */
    @Select("SELECT " +
            "SUM(CASE WHEN store_type_cd = '800900000001' THEN 1 ELSE 0 END) as property_count, " +
            "SUM(CASE WHEN store_type_cd != '800900000001' THEN 1 ELSE 0 END) as business_count, " +
            "SUM(CASE WHEN store_type_cd = '800900000003' THEN 1 ELSE 0 END) as shop_count " +
            "FROM s_store WHERE status_cd = '0'")
    Map<String, Object> getStoreStatistics();

    /**
     * 获取今日缴费数
     */
    @Select("SELECT COUNT(*) FROM pay_fee WHERE DATE(create_time) = CURDATE()")
    Long getTodayPaymentCount();

    /**
     * 获取今日报修数
     */
    @Select("SELECT COUNT(*) FROM r_repair_pool WHERE DATE(create_time) = CURDATE()")
    Long getTodayRepairCount();

    /**
     * 获取今日巡检数
     */
    @Select("SELECT COUNT(*) FROM inspection_task WHERE DATE(create_time) = CURDATE()")
    Long getTodayInspectionCount();

    /**
     * 获取今日投诉数
     */
    @Select("SELECT COUNT(*) FROM complaint WHERE DATE(create_time) = CURDATE()")
    Long getTodayComplaintCount();
}
