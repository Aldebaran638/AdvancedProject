package com.zeroone.star.systemmanage.service.impl;


import com.baomidou.mybatisplus.core.conditions.query.LambdaQueryWrapper;
import com.zeroone.star.project.vo.j3.systemmanage.communitysetting.CommunitySettingKeyVo;
import com.zeroone.star.systemmanage.entity.CommunitySetting;
import com.zeroone.star.systemmanage.mapper.CommunitySettingKeyMapper;
import com.zeroone.star.systemmanage.mapper.CommunitySettingMapper;
import com.zeroone.star.systemmanage.service.CommunitySettingKeyService;
import org.slf4j.Logger;
import org.slf4j.LoggerFactory;
import org.springframework.data.redis.core.RedisTemplate;
import org.springframework.stereotype.Service;
import org.springframework.util.StringUtils;

import javax.annotation.Resource;
import java.util.ArrayList;
import java.util.List;
import java.util.Map;
import java.util.concurrent.TimeUnit;
import java.util.stream.Collectors;

/**
 * 获取配置项列表
 */
@Service
public class CommunitySettingKeyServiceImpl implements CommunitySettingKeyService {

    private static final Logger log = LoggerFactory.getLogger(CommunitySettingKeyServiceImpl.class);

    @Resource
    private CommunitySettingKeyMapper communitySettingKeyMapper;
    
    @Resource
    private CommunitySettingMapper communitySettingMapper;
    
    @Resource
    private RedisTemplate<String, Object> redisTemplate;

    // 小区配置键前缀
    String COMMUNITY_SETTING_KEY_PREFIX = "COMMUNITY:SETTING_KEY:";

    // 小区配置键缓存过期时间（秒）
    long COMMUNITY_SETTING_KEY_EXPIRE = 5;

    @Override
    public List<CommunitySettingKeyVo> queryCommunitySettingKeyList(String communityId) {
        // 参数校验
        if (!StringUtils.hasText(communityId)) {
            throw new IllegalArgumentException("小区ID不能为空");
        }
        
        // 构建缓存键
        String cacheKey = COMMUNITY_SETTING_KEY_PREFIX + communityId;
        
        // 先从Redis缓存中查询
        Map<Object, Object> cacheMap = redisTemplate.opsForHash().entries(cacheKey);
        
        // 如果缓存不为空，则直接返回所有缓存数据
        if (!cacheMap.isEmpty()) {
            return cacheMap.values().stream()
                    .map(obj -> (CommunitySettingKeyVo) obj)
                    .collect(Collectors.toList());
        }
        
        // 缓存未命中，首先校验community_id是否合法
        // 使用MyBatisPlus的LambdaQueryWrapper来查询
        LambdaQueryWrapper<CommunitySetting> queryWrapper = new LambdaQueryWrapper<>();
        queryWrapper.eq(CommunitySetting::getCommunityId, communityId)
                   .eq(CommunitySetting::getStatusCd, "0")
                   .last("LIMIT 1"); // 只需要确认是否存在，使用LIMIT 1提高查询效率
        
        CommunitySetting communitySetting = communitySettingMapper.selectOne(queryWrapper);
        if (communitySetting == null) {
            throw new IllegalArgumentException("小区ID不存在或已失效");
        }
        
        // 查询符合条件的数据
        List<CommunitySettingKeyVo> communitySettings = communitySettingKeyMapper.queryDictSettings();
        
        if (communitySettings.isEmpty()) {
            return new ArrayList<>();
        }
        
        // 更新缓存
        for (CommunitySettingKeyVo settingKey : communitySettings) {
            // 使用setting_type作为缓存键
            redisTemplate.opsForHash().put(cacheKey, settingKey.getStatusCd(), settingKey);
        }
        
        // 设置缓存过期时间
        redisTemplate.expire(cacheKey, COMMUNITY_SETTING_KEY_EXPIRE, TimeUnit.SECONDS);
        
        return communitySettings;
    }
}
