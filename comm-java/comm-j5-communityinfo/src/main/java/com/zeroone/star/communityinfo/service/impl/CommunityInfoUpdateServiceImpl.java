package com.zeroone.star.communityinfo.service.impl;

import com.zeroone.star.communityinfo.comp.RmqPublish;
import com.zeroone.star.communityinfo.entity.SCommunity;
import com.zeroone.star.communityinfo.mapper.CommunityInfoUpdateMapper;
import com.zeroone.star.communityinfo.service.CommunityInfoUpdateService;
import com.baomidou.mybatisplus.extension.service.impl.ServiceImpl;
import com.zeroone.star.project.dto.j5.info.communityinfo.AddCommunityDTO;
import com.zeroone.star.project.dto.j5.info.communityinfo.CommunityDTO;
import com.zeroone.star.project.dto.j5.info.communityinfo.CommunityNotifyDTO;
import lombok.extern.slf4j.Slf4j;
import org.springframework.data.redis.core.StringRedisTemplate;
import org.springframework.stereotype.Service;
import org.springframework.transaction.annotation.Transactional;

import javax.annotation.Resource;
import java.util.Map;
import java.util.concurrent.TimeUnit;

/**
 * <p>
 *  服务实现类
 * </p>
 *
 * @author j5-guoba
 * @since 2025-05-23
 */
@Service
@Slf4j
public class CommunityInfoUpdateServiceImpl extends ServiceImpl<CommunityInfoUpdateMapper, SCommunity> implements CommunityInfoUpdateService {
    @Resource
    private CommunityInfoUpdateMapper mapper;
    @Resource
    private MsCommunityInfoMapper msMapper;
    @Resource
    private StringRedisTemplate stringRedisTemplate;
    @Resource
    private RmqPublish  rmqPublish;

    @Override
    @Transactional
    public String saveCommunity(AddCommunityDTO addCommunityDTO) {
        //  DTO转DO
        SCommunity community = msMapper.addDtoToDo(addCommunityDTO);
        //  更新经纬度
        updateLonAndLat(community);
        community.setStatusCd("1");
        community.setState("1000");
        if (mapper.insert(community) != 1) {
            throw new RuntimeException("添加小区数据失败");
        }
        if(! rmqPublish.publishNotify(new CommunityNotifyDTO(community.getCommunityId(), "COMMUNITY_ADD_SUCCESS"))) {
            log.info("添加小区消息发送失败：{}", community.getCommunityId());
        }
        return community.getCommunityId();
    }

    @Override
    @Transactional
    public String updateCommunity(CommunityDTO communityDTO) {
        SCommunity community = msMapper.dtoToDo(communityDTO);
        //  更新经纬度
        updateLonAndLat(community);
        if (mapper.updateById(community) == 0) {
            throw new RuntimeException("更新小区数据失败");
        }
        if(!rmqPublish.publishNotify(new CommunityNotifyDTO(community.getCommunityId(), "COMMUNITY_UPDATE_SUCCESS"))){
            log.info("更新小区消息发送失败：{}", community.getCommunityId());
        }
        return community.getCommunityId();
    }

    @Override
    @Transactional
    public String removeCommunity(String communityId) {
        SCommunity  community = mapper.selectById(communityId);
        if(community == null){
            throw new RuntimeException("小区不存在");
        }
        community.setStatusCd("1");
        if (mapper.updateById(community) == 0) {
            throw new RuntimeException("删除小区失败");
        }
        if(!rmqPublish.publishNotify(new CommunityNotifyDTO(community.getCommunityId(), "COMMUNITY_REMOVE_SUCCESS"))){
            log.info("删除小区消息发送失败：{}", communityId);
        }
        return communityId;
    }

    public Map<Object, Object> listLonAndLatByAreaCode(String areaCode) {
        String areaCodeKey = "cityArea:" + areaCode;

        // 先从缓存获取
        Map<Object, Object> lonAndLat = stringRedisTemplate.opsForHash().entries(areaCodeKey);
        if (!lonAndLat.isEmpty()) {
            return lonAndLat;
        }

        // 缓存没有则查询数据库
        lonAndLat = mapper.listLonAndLatByAreaCode(areaCode);
        if (lonAndLat != null && !lonAndLat.isEmpty()) {
            // 存入缓存，设置过期时间(30天)
            stringRedisTemplate.opsForHash().putAll(areaCodeKey, lonAndLat);
            stringRedisTemplate.expire(areaCodeKey, 30, TimeUnit.DAYS);
        }
        return lonAndLat;
    }

    public void updateLonAndLat(SCommunity community){
        // 获取经纬度
        Map<Object, Object> lonAndLat = listLonAndLatByAreaCode(community.getCityCode());
        // 判断城市编码是否合法
        if (lonAndLat == null || lonAndLat.get("lon") == null || lonAndLat.get("lat") == null) {
            throw new IllegalArgumentException("无效的城市编码或缺少经纬度数据");
        }
        community.setMapY((String) lonAndLat.get("lon"));
        community.setMapX((String) lonAndLat.get("lat"));
    }
}
