package com.zeroone.star.communityinfo.service.impl;

import com.baomidou.mybatisplus.core.conditions.query.LambdaQueryWrapper;
import com.baomidou.mybatisplus.core.conditions.query.QueryWrapper;
import com.baomidou.mybatisplus.extension.plugins.pagination.Page;
import com.zeroone.star.communityinfo.entity.CityArea;
import com.zeroone.star.communityinfo.entity.SCommunity;
import com.zeroone.star.communityinfo.entity.SCommunityMember;
import com.zeroone.star.communityinfo.mapper.CityAreaMapper;
import com.zeroone.star.communityinfo.mapper.CommunityInfoMapper;
import com.zeroone.star.communityinfo.service.CommunityInfoQueryService;
import com.zeroone.star.project.dto.PageDTO;
import com.zeroone.star.project.query.j5.info.communityinfo.CityAreaQuery;
import com.zeroone.star.project.query.j5.info.communityinfo.CommunityInfoQuery;
import com.zeroone.star.project.vo.j5.info.communityinfo.CityAreaVO;
import com.zeroone.star.project.vo.j5.info.communityinfo.CommunityInfoVO;
import com.zeroone.star.project.vo.j5.info.communityinfo.CommunityNameVO;
import lombok.extern.slf4j.Slf4j;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.data.redis.core.RedisTemplate;
import org.springframework.data.redis.core.script.DefaultRedisScript;
import org.springframework.stereotype.Service;
import org.springframework.util.StringUtils;

import javax.annotation.Resource;
import java.util.*;
import java.util.concurrent.TimeUnit;
import java.util.stream.Collectors;

/**
 * <p>
 * 描述：小区信息服务接口
 *      yuezi : 获取小区列表（条件+分页）、获取未入驻物业的小区名称列表
 * </p>
 * @author yuezi
 * @version 1.0.0
 */
@Service
@Slf4j
public class CommunityInfoQueryServiceImpl implements CommunityInfoQueryService {

    @Resource
    CommunityInfoMapper communityInfoMapper;

    @Resource
    CityAreaMapper cityAreaMapper;

    @Resource
    MsCommunityInfoMapper msCommunityInfoMapper;

    @Resource
    MsCityAreaMapper msCityAreaMapper;

    @Override
    public PageDTO<CommunityInfoVO> listCommunityInfo(CommunityInfoQuery query) {
        Page<CommunityInfoVO> page = new Page<>(query.getPageIndex(), query.getPageSize());
        Page<CommunityInfoVO> pageResult = communityInfoMapper.selectCommunityWithProperty(page, query.getCommunityId(), query.getCityCode(), query.getName());
        return PageDTO.create(pageResult);
    }

    @Resource(name = "nameListRedisTemplate")
    private RedisTemplate<String, List<CommunityNameVO>> nameListRedisTemplate;

    @Resource(name = "nameListLockRedisTemplate")
    private RedisTemplate<String, String> nameListLockRedisTemplate;

    private static final String COMMUNITY_NAME_LIST_KEY = "info:community.info:name.list";
    private static final String COMMUNITY_NAME_LIST_LOCK_KEY = "info:community.info:name.list.lock";

    @Override
    public List<CommunityNameVO> listNotEnteredCommunityNameWithCache() {
        List<CommunityNameVO> communityNameList = nameListRedisTemplate.opsForValue().get(COMMUNITY_NAME_LIST_KEY);
        if (communityNameList == null) {

            // 查询数据库前设置互斥锁，防止缓存击穿
            // TODO 将分布式锁封装为工具类，便于其他成员使用
            String uuid = UUID.randomUUID().toString();
            Boolean lockAcquired = nameListLockRedisTemplate.opsForValue().setIfAbsent(COMMUNITY_NAME_LIST_LOCK_KEY, uuid, 30, TimeUnit.SECONDS);
            while (Boolean.FALSE.equals(lockAcquired)) {
                // TODO 自旋锁效率低，可能在其他线程更新缓存期间一直等待，影响客户体验，应设置最大重试次数或超时时间，超时则放弃获取锁
                try {
                    Thread.sleep(100);
                    log.info("{} Waiting for COMMUNITY_NAME_LIST_LOCK to be released...", uuid);
                } catch (InterruptedException e) {
                    log.error("{}", e.toString());
                    return Collections.emptyList();
                }
                lockAcquired = nameListLockRedisTemplate.opsForValue().setIfAbsent(COMMUNITY_NAME_LIST_LOCK_KEY, uuid, 30, TimeUnit.SECONDS);
            }
            try {
                communityNameList = Optional.ofNullable(nameListRedisTemplate.opsForValue().get(COMMUNITY_NAME_LIST_KEY))
                        .orElseGet(this::ListNotEnteredCommunityNameWithNoCache);
            } finally {
                String script = "if redis.call('get', KEYS[1]) == ARGV[1] then return redis.call('del', KEYS[1]) else return 0 end";
                nameListLockRedisTemplate.execute(new DefaultRedisScript<>(script, Long.class), Collections.singletonList(COMMUNITY_NAME_LIST_LOCK_KEY), uuid);
            }
            log.info("Cache miss. {} Retrieved not entered community name list from database.", uuid);
        }

        return communityNameList;
    }

    public List<CommunityNameVO> ListNotEnteredCommunityNameWithNoCache() {
        List<CommunityNameVO> list = communityInfoMapper.selectNotEnteredCommunityName();
        nameListRedisTemplate.opsForValue().set(COMMUNITY_NAME_LIST_KEY, list, new Random().nextInt(1) + 1, TimeUnit.MINUTES);
        return list;
    }

    @Override
    public List<CityAreaVO> listCityAreas(CityAreaQuery query) {
        LambdaQueryWrapper<CityArea> queryWrapper = new LambdaQueryWrapper<>();
        queryWrapper
                .like(!StringUtils.isEmpty(query.getAreaLevel()),CityArea::getAreaLevel,query.getAreaLevel())
                .like(!StringUtils.isEmpty(query.getParentAreaCode()), CityArea::getParentAreaCode, query.getParentAreaCode());
        List<CityArea> cityAreas = cityAreaMapper.selectList(queryWrapper);
        return cityAreas.stream().map(src -> msCityAreaMapper.cityAreaToVO(src)).collect(Collectors.toList());
    }
}
