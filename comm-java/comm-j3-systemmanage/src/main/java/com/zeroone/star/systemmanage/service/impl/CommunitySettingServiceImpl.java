package com.zeroone.star.systemmanage.service.impl;

import com.baomidou.mybatisplus.core.conditions.query.LambdaQueryWrapper;
import com.zeroone.star.project.dto.j3.systemmanage.communitysetting.UpdateCommunitySettingItemDTO;
import com.zeroone.star.project.vo.j3.systemmanage.communitysetting.CommunitySettingVo;
import com.zeroone.star.systemmanage.entity.CommunitySetting;
import com.zeroone.star.systemmanage.mapper.CommunitySettingMapper;
import com.zeroone.star.systemmanage.service.CommunitySettingService;
import org.slf4j.Logger;
import org.slf4j.LoggerFactory;
import org.springframework.data.redis.core.RedisTemplate;
import org.springframework.stereotype.Service;
import org.springframework.transaction.annotation.Transactional;
import org.springframework.util.CollectionUtils;
import org.springframework.util.StringUtils;

import javax.annotation.Resource;
import java.util.*;
import java.util.concurrent.TimeUnit;
import java.util.stream.Collectors;

/**
 * 小区配置服务实现类
 */
@Service
public class CommunitySettingServiceImpl implements CommunitySettingService {

    private static final Logger log = LoggerFactory.getLogger(CommunitySettingServiceImpl.class);

    @Resource
    private CommunitySettingMapper communitySettingMapper;

    @Resource
    private RedisTemplate<String, Object> redisTemplate;

    // 小区配置缓存键前缀
    private static final String COMMUNITY_SETTING_PREFIX = "COMMUNITY:SETTING:";

    // 小区配置缓存过期时间（秒）
    private static final long CACHE_EXPIRE_SECONDS = 3;

    /**
     * 查询小区相关设置
     *
     * @param communityId 小区ID
     * @param settingType 设置类型
     * @return
     */
    @Override
    public List<CommunitySettingVo> queryCommunitySettingList(String communityId, String settingType) {
        // 参数校验
        if (!StringUtils.hasText(communityId)) {
            throw new IllegalArgumentException("小区ID不能为空");
        }else if (!StringUtils.hasText(settingType)) {
            throw new IllegalArgumentException("设置类型不能为空");
        }

        String cacheKey = COMMUNITY_SETTING_PREFIX + communityId;

        // 从缓存获取
        if (redisTemplate.hasKey(cacheKey)) {
            Map<Object, Object> entries = redisTemplate.opsForHash().entries(cacheKey);
            if (entries.isEmpty()) {
                return Collections.emptyList();
            }

            return entries.entrySet().stream()
                    .filter(entry -> !StringUtils.hasText(settingType) ||
                            ((String) entry.getKey()).startsWith(settingType + ":"))
                    .map(entry -> (CommunitySettingVo) entry.getValue())
                    .collect(Collectors.toList());
        }

        // 缓存未命中，首先校验community_id是否合法
        LambdaQueryWrapper<CommunitySetting> queryCheck = new LambdaQueryWrapper<>();
        queryCheck.eq(CommunitySetting::getCommunityId, communityId)
                .eq(CommunitySetting::getStatusCd, "0")
                .eq(CommunitySetting::getSettingType, settingType)
                .last("LIMIT 1"); // 只需要确认是否存在，使用LIMIT 1提高查询效率

        CommunitySetting checkResult = communitySettingMapper.selectOne(queryCheck);
        if (checkResult == null) {
            throw new IllegalArgumentException("小区ID或设置类型不存在");
        }

        // 从数据库获取配置数据
        LambdaQueryWrapper<CommunitySetting> query = new LambdaQueryWrapper<CommunitySetting>()
                .eq(CommunitySetting::getCommunityId, communityId)
                .eq(CommunitySetting::getStatusCd, "0")
                .eq(StringUtils.hasText(settingType), CommunitySetting::getSettingType, settingType);

        // 转换并返回
        List<CommunitySetting> settings = communitySettingMapper.selectList(query);
        if (settings.isEmpty()) {
            return Collections.emptyList();
        }

        // 转换并缓存
        Map<String, Object> cacheMap = new HashMap<>();
        List<CommunitySettingVo> result = settings.stream()
                .map(setting -> {
                    CommunitySettingVo vo = new CommunitySettingVo();
                    vo.setSettingName(setting.getSettingName());
                    vo.setSettingValue(setting.getSettingValue());
                    vo.setRemark(setting.getRemark());
                    vo.setCsId(setting.getCsId());

                    String cacheField = setting.getSettingType() + ":" + setting.getSettingKey();
                    cacheMap.put(cacheField, vo);
                    // 直接返回，不缓存
                    return vo;
                })
                .collect(Collectors.toList());
        // 如果缓存不为空，则更新缓存
        if (!cacheMap.isEmpty()) {
            try {
                redisTemplate.opsForHash().putAll(cacheKey, cacheMap);
                redisTemplate.expire(cacheKey, CACHE_EXPIRE_SECONDS, TimeUnit.SECONDS);
            } catch (Exception e) {
                log.error("缓存更新失败", e);
            }
        }

        return result;
    }

    /**
     * 批量更新小区配置项
     *
     * @param dtoList 配置项DTO列表
     * @return 成功返回"success"，失败返回错误信息
     */
    @Override
    @Transactional(rollbackFor = Exception.class)
    public String updateCommunitySetting(List<UpdateCommunitySettingItemDTO> dtoList) {
        // 参数校验
        if (CollectionUtils.isEmpty(dtoList)) {
            return "更新失败：参数列表不能为空";
        }

        // 校验DTO并同时收集有效的csIds
        List<String> csIds = new ArrayList<>();
        List<UpdateCommunitySettingItemDTO> validDtos = new ArrayList<>();
        StringBuilder errorMsg = new StringBuilder();
        
        for (int i = 0; i < dtoList.size(); i++) {
            UpdateCommunitySettingItemDTO dto = dtoList.get(i);
            if (dto == null) {
                if (errorMsg.length() > 0) errorMsg.append("；");
                errorMsg.append("第").append(i + 1).append("项为空");
            } else if (!StringUtils.hasText(dto.getCsId())) {
                if (errorMsg.length() > 0) errorMsg.append("；");
                errorMsg.append("第").append(i + 1).append("项的配置项ID为空");
            } else if (!StringUtils.hasText(dto.getSettingValue())) {
                if (errorMsg.length() > 0) errorMsg.append("；");
                errorMsg.append("配置项ID为").append(dto.getCsId()).append("的设置值为空");
            } else {
                validDtos.add(dto);
                csIds.add(dto.getCsId());
            }
        }
        
        if (errorMsg.length() > 0) {
            return "更新失败：" + errorMsg;
        }
        
        // 查询并验证配置项
        List<CommunitySetting> settings = communitySettingMapper.selectList(
                new LambdaQueryWrapper<CommunitySetting>()
                        .in(CommunitySetting::getCsId, csIds)
                        .eq(CommunitySetting::getStatusCd, "0"));

        if (settings.isEmpty()) {
            return "更新失败：配置项ID不存在";
        }

        // 获取小区ID
        String communityId = settings.get(0).getCommunityId();
        if (!StringUtils.hasText(communityId)) {
            return "更新失败：无法获取小区ID";
        }
        
        // 创建csId到配置项的映射并检查不存在的ID
        Map<String, CommunitySetting> idMap = settings.stream()
                .collect(Collectors.toMap(CommunitySetting::getCsId, s -> s, (s1, s2) -> s1));
        
        // 找出不存在的csId
        Set<String> dbCsIds = idMap.keySet();
        List<String> notFoundIds = csIds.stream()
                .filter(id -> !dbCsIds.contains(id))
                .collect(Collectors.toList());
        
        if (!notFoundIds.isEmpty()) {
            return "更新失败：以下配置项ID不存在：" + String.join("，", notFoundIds);
        }

        // 执行更新
        try {
            for (UpdateCommunitySettingItemDTO dto : validDtos) {
                CommunitySetting setting = idMap.get(dto.getCsId());
                setting.setSettingValue(dto.getSettingValue());
                communitySettingMapper.updateById(setting);
            }
        } catch (Exception e) {
            log.error("更新配置项失败：{}", e.getMessage());
            return "更新失败：数据库操作异常";
        }
        
        // 更新成功后清除缓存
        try {
            redisTemplate.delete(COMMUNITY_SETTING_PREFIX + communityId);
        } catch (Exception e) {
            log.error("缓存清除失败：{}",e.getMessage());
        }

        return "success";
    }
}
