package com.zeroone.star.dashboard.service.impl;

import com.github.benmanes.caffeine.cache.Cache;
import com.github.benmanes.caffeine.cache.Caffeine;
import com.zeroone.star.dashboard.mapper.*;
import com.zeroone.star.dashboard.service.DashboardService;
import com.zeroone.star.project.constant.RedisConstant;
import com.zeroone.star.project.vo.j1.dashboard.data.CommunityPaymentStatisticsVO;
import com.zeroone.star.project.vo.j1.dashboard.data.CommunityRepairStatisticsVO;
import com.zeroone.star.project.vo.j1.dashboard.data.PlatformStatisticsVO;

import org.springframework.data.redis.core.RedisTemplate;
import org.springframework.stereotype.Service;
import org.springframework.util.DigestUtils;

import javax.annotation.Resource;
import java.math.BigDecimal;
import java.time.LocalDate;
import java.time.format.DateTimeFormatter;
import java.util.ArrayList;
import java.util.List;
import java.util.Map;
import java.util.Random;
import java.util.concurrent.TimeUnit;

/**
 * 平台数据统计服务实现类
 */
@Service
public class DashboardServiceImpl implements DashboardService {

    @Resource
    private SCommunityMapper communityMapper;

    @Resource
    private PayFeeMapper payFeeMapper;

    @Resource
    private RRepairPoolMapper repairMapper;

    @Resource
    private RedisTemplate<String, Object> redisTemplate;

    // 构建本地缓存 LOCAL_CACHE
    private final Cache<String, Object> LOCAL_CACHE =
            Caffeine.newBuilder().initialCapacity(1024)
                    .maximumSize(10000L)
                    .expireAfterWrite(5L, TimeUnit.MINUTES)
                    .build();

    // 缓存相关常量
    private static final Random RANDOM = new Random();
    // 基础缓存时间（秒）
    private static final int BASE_CACHE_EXPIRE_TIME = 1500;
    // 随机时间范围（秒）
    private static final int CACHE_EXPIRE_RANGE = 600;

    /**
     * 生成每日缓存键
     *
     * @param prefix
     * @return
     */
    private String generateDailyCacheKey(String prefix) {
        String dateStr = LocalDate.now().format(DateTimeFormatter.ofPattern("yyyyMMdd"));
        String hashKey = DigestUtils.md5DigestAsHex(dateStr.getBytes());
        return String.format("%s:%s", prefix, hashKey);
    }

    /**
     * 安全地将Object转换为int值
     *
     * @param value
     * @return
     */
    private int safeToInt(Object value) {
        if (value == null) {
            return 0;
        }
        if (value instanceof Number) {
            return ((Number) value).intValue();
        }
        return 0;
    }

    /**
     * 安全地将Object转换为double值
     *
     * @param value
     * @return
     */
    private double safeToDouble(Object value) {
        if (value == null) {
            return 0.0;
        }
        if (value instanceof BigDecimal) {
            return ((BigDecimal) value).doubleValue();
        }
        if (value instanceof Number) {
            return ((Number) value).doubleValue();
        }
        return 0.0;
    }

    /**
     * 从多级缓存获取数据
     *
     * @param cacheKey     缓存键
     * @param dataSupplier 数据提供者，在缓存未命中时调用
     * @return 缓存数据
     */
    private <T> T getFromMultilevelCache(String cacheKey, java.util.function.Supplier<T> dataSupplier) {
        // 1. 先查本地缓存(Caffeine)
        T cacheValue = (T) LOCAL_CACHE.getIfPresent(cacheKey);
        if (cacheValue != null) {
            return cacheValue;
        }

        // 2. 本地缓存未命中，查询Redis
        Object redisValue = redisTemplate.opsForValue().get(cacheKey);
        if (redisValue != null) {
            try {
                // 如果是字符串，且期望对象不是字符串，则重新查询数据库
                if (redisValue instanceof String && !(dataSupplier.get() instanceof String)) {
                    // 清除错误的缓存值
                    redisTemplate.delete(cacheKey);
                    // 重新获取数据
                    cacheValue = dataSupplier.get();
                    // 更新缓存
                    int cacheExpireTime = BASE_CACHE_EXPIRE_TIME + RANDOM.nextInt(CACHE_EXPIRE_RANGE);
                    redisTemplate.opsForValue().set(cacheKey, cacheValue, cacheExpireTime, TimeUnit.SECONDS);
                } else {
                    // 正常类型转换
                    cacheValue = (T) redisValue;
                }
                // 更新本地缓存
                LOCAL_CACHE.put(cacheKey, cacheValue);
                return cacheValue;
            } catch (ClassCastException e) {
                // 类型转换失败，清除Redis缓存并重新获取数据
                redisTemplate.delete(cacheKey);
            }
        }

        // 3. Redis获取失败或未命中，查询数据库
        cacheValue = dataSupplier.get();

        // 将结果存入Redis和本地缓存
        int cacheExpireTime = BASE_CACHE_EXPIRE_TIME + RANDOM.nextInt(CACHE_EXPIRE_RANGE);
        redisTemplate.opsForValue().set(cacheKey, cacheValue, cacheExpireTime, TimeUnit.SECONDS);
        LOCAL_CACHE.put(cacheKey, cacheValue);

        return cacheValue;
    }


    /**
     * 获取平台统计数据
     * 已优化：使用分离的高效查询，避免子查询性能问题
     *
     * @return 平台统计数据VO
     */
    @Override
    public PlatformStatisticsVO getPlatformStatistics() {
        String cacheKey = generateDailyCacheKey(RedisConstant.CACHE_PLATFORM_STATISTICS);

        return getFromMultilevelCache(cacheKey, () -> {
            PlatformStatisticsVO vo = new PlatformStatisticsVO();

            // 1. 基础统计数据（简单高效的单表查询）
            vo.setCommunityCount(safeToInt(communityMapper.getCommunityCount()));
            vo.setOwnerCount(safeToInt(communityMapper.getOwnerCount()));
            vo.setCarCount(safeToInt(communityMapper.getCarCount()));

            // 2. 房屋统计数据（合并同表查询）
            Map<String, Object> houseStats = communityMapper.getHouseStatistics();
            vo.setHouseCount(safeToInt(houseStats.get("house_count")));
            vo.setCommercialHouseCount(safeToInt(houseStats.get("commercial_house_count")));

            // 3. 商户统计数据（合并同表查询）
            Map<String, Object> storeStats = communityMapper.getStoreStatistics();
            vo.setPropertyCount(safeToInt(storeStats.get("property_count")));
            vo.setBusinessCount(safeToInt(storeStats.get("business_count")));
            vo.setShopCount(safeToInt(storeStats.get("shop_count")));

            // 4. 今日统计数据（简单高效的单表查询）
            vo.setTodayPaymentCount(safeToInt(communityMapper.getTodayPaymentCount()));
            vo.setTodayRepairCount(safeToInt(communityMapper.getTodayRepairCount()));
            vo.setTodayInspectionCount(safeToInt(communityMapper.getTodayInspectionCount()));
            vo.setTodayComplaintCount(safeToInt(communityMapper.getTodayComplaintCount()));

            return vo;
        });
    }

    /**
     * 获取小区缴费统计数据
     * 已优化：使用JOIN查询避免N+1问题
     *
     * @return 小区缴费统计数据VO列表
     */
    @Override
    public List<CommunityPaymentStatisticsVO> getCommunityPaymentStatistics() {
        String cacheKey = generateDailyCacheKey(RedisConstant.CACHE_COMMUNITY_PAYMENT);

        return getFromMultilevelCache(cacheKey, () -> {
            // 使用优化的JOIN查询，一次性获取所有小区的缴费统计数据
            List<Map<String, Object>> statisticsData = payFeeMapper.getCommunityPaymentStatistics();
            List<CommunityPaymentStatisticsVO> voList = new ArrayList<>(statisticsData.size());

            for (Map<String, Object> data : statisticsData) {
                CommunityPaymentStatisticsVO vo = new CommunityPaymentStatisticsVO();
                vo.setCommunityId((String) data.get("community_id"));
                vo.setCommunityName((String) data.get("community_name"));
                vo.setPaymentCount(safeToInt(data.get("payment_count")));
                vo.setPaymentAmount(safeToDouble(data.get("payment_amount")));
                voList.add(vo);
            }

            return voList;
        });
    }

    /**
     * 获取小区报修统计数据
     * 已优化：使用JOIN查询避免N+1问题
     *
     * @return 小区报修统计数据VO列表
     */
    @Override
    public List<CommunityRepairStatisticsVO> getCommunityRepairStatistics() {
        String cacheKey = generateDailyCacheKey(RedisConstant.CACHE_COMMUNITY_REPAIR);

        return getFromMultilevelCache(cacheKey, () -> {
            // 使用优化的JOIN查询，一次性获取所有小区的报修统计数据
            List<Map<String, Object>> statisticsData = repairMapper.getCommunityRepairStatistics();
            List<CommunityRepairStatisticsVO> voList = new ArrayList<>(statisticsData.size());

            for (Map<String, Object> data : statisticsData) {
                CommunityRepairStatisticsVO vo = new CommunityRepairStatisticsVO();
                vo.setCommunityId((String) data.get("community_id"));
                vo.setCommunityName((String) data.get("community_name"));
                vo.setRepairCount(safeToInt(data.get("repair_count")));
                voList.add(vo);
            }

            return voList;
        });
    }
}