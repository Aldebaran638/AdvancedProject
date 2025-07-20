package com.zeroone.star.menumana.service.impl;

import com.baomidou.mybatisplus.core.conditions.query.LambdaQueryWrapper;
import com.baomidou.mybatisplus.core.conditions.query.QueryWrapper;
import com.baomidou.mybatisplus.extension.plugins.pagination.Page;
import com.baomidou.mybatisplus.extension.service.impl.ServiceImpl;
import com.zeroone.star.menumana.entity.Privilege;
import com.zeroone.star.menumana.entity.StoreType;
import com.zeroone.star.menumana.mapper.MsPrivilegeMapper;
import com.zeroone.star.menumana.mapper.PrivilegeMapper;
import com.zeroone.star.menumana.mapper.StoreTypeMapper;
import com.zeroone.star.menumana.service.IPrivilegeService;
import com.zeroone.star.project.dto.j1.menumana.privilege.PrivilegeAddDTO;
import com.zeroone.star.project.dto.j1.menumana.privilege.PrivilegeDTO;

import com.zeroone.star.project.query.j1.menumana.privilege.PrivilegeQuery;
import lombok.extern.slf4j.Slf4j;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.data.redis.core.HashOperations;
import org.springframework.data.redis.core.RedisTemplate;
import org.springframework.stereotype.Service;
import org.springframework.transaction.annotation.Transactional;
import org.springframework.util.StringUtils;

import javax.annotation.Resource;
import java.util.*;
import java.util.concurrent.TimeUnit;
import java.util.stream.Collectors;

/**
 * @author cv
 * @description 针对表【p_privilege】的数据库操作Service实现
 * @createDate 2025-05-20 17:05:06
 */
@Service
@Slf4j
public class PrivilegeServiceImpl extends ServiceImpl<PrivilegeMapper,Privilege> implements IPrivilegeService {

    @Resource
    MsPrivilegeMapper ms;

    @Autowired
    private PrivilegeMapper privilegeMapper;

    @Autowired
    private RedisTemplate redisTemplate;

    @Autowired
    private StoreTypeMapper storeTypeMapper ;

    /*
     * 缓存前缀
     * */
    private static final String PRIVILEGE_CACHE_KEY = "privilege:cache:";
    /*
     * 将权限域转换为对应的商家名称
     * */
    private static final long CACHE_TTL = 24 * 60 * 60; // 缓存过期时间（秒）
    /*
     * 缓存过期时间
     * */
    private static final long CACHE_EXPIRE_TIME = 30;

    /*
     * 实现查询代码（分页+条件）
     * */
    public Page<PrivilegeDTO> listByCondition(PrivilegeQuery query) {
        if (query.getMid() == null) {
            throw new IllegalArgumentException("mId不能为空");
        }
        String cacheKey = generateCacheKey(query);
        Map<Object, Object> cacheMap = redisTemplate.opsForHash().entries(cacheKey);

        // 缓存存在则直接返回
        if (!cacheMap.isEmpty()) {
            return buildPageDTOFromCache(cacheMap, query);
        }
        // 缓存不存在，查询数据库
        QueryWrapper<Privilege> wrapper = new QueryWrapper<>();
        wrapper.eq("m_id", query.getMid())
                .eq(query.getPid() != null, "p_id", query.getPid())
                .eq("status_cd","0")
                .like(!StringUtils.isEmpty(query.getName()), "name", query.getName())
                .orderBy(true, true, "p_id");

        long pageIndex = query.getPageIndex() > 0 ? query.getPageIndex() : 1;
        long pageSize = query.getPageSize() > 0 ? query.getPageSize() : 10;
        Page<Privilege> entityPage = new Page<>(pageIndex, pageSize);
        Page<Privilege> pageResult = privilegeMapper.selectPage(entityPage, wrapper);

        List<PrivilegeDTO> dtoList = pageResult.getRecords().stream()
                .map(privilege -> {
                    PrivilegeDTO dto = ms.PrivilegeToDto(privilege);
                    // 实时查询商家名称（每次查询都访问数据库）
                    dto.setStoreTypeName(getStoreTypeNameByDomain(privilege.getDomain()));
                    return dto;
                })
                .collect(Collectors.toList());

        Page<PrivilegeDTO> dtoPage = new Page<>(pageIndex, pageSize);
        dtoPage.setTotal(pageResult.getTotal());
        dtoPage.setRecords(dtoList);
        saveResultToRedis(cacheKey, dtoPage);

        return dtoPage;
    }
    /*
     *
     * 实现添加代码
     * */
    @Override
    @Transactional
    public String addPrivilege(PrivilegeAddDTO privilegeAddDTO) {
        // 1. 将前端传递的 storeTypeName 转换为 domain
        String storeTypeName = privilegeAddDTO.getStoreTypeName();
        String domain = getDomainByStoreTypeName(storeTypeName);

        // 2. 校验 storeTypeName 是否有效
        if (domain == null) {
            throw new IllegalArgumentException("无效的商家名称: " + storeTypeName);
        }

        // 3. 设置转换后的 domain
        Privilege privilege = ms.addDtoToPrivilege(privilegeAddDTO);
        privilege.setDomain(domain);

        if (save(privilege)) {
            // 清除关联缓存
            PrivilegeQuery query = new PrivilegeQuery();
            query.setMid(privilege.getMId());
            clearCache(query);
            return privilege.getPId();
        }
        return null;
    }
    /*
     * 实现修改方法
     * */
    @Override
    @Transactional
    public boolean modifyPrivilege(PrivilegeDTO privilegeDTO) {
        // 1. 如果 storeTypeName 不为空，转换为 domain
        if (privilegeDTO.getStoreTypeName() != null) {
            String domain = getDomainByStoreTypeName(privilegeDTO.getStoreTypeName());

            if (domain == null) {
                throw new IllegalArgumentException("无效的商家名称: " + privilegeDTO.getStoreTypeName());
            }

            privilegeDTO.setDomain(domain); // 设置转换后的 domain
        }

        // 2. 转换为实体并更新
        Privilege privilege = ms.dtoToDo(privilegeDTO);
        boolean result = updateById(privilege);

        if (result) {
            // 清除关联缓存
            PrivilegeQuery query = new PrivilegeQuery();
            query.setMid(privilege.getMId());
            clearCache(query);
        }
        return result;
    }

    /*
     * 实现删除方法
     * */
    @Override
    @Transactional
    public boolean deletePrivilege(String id) {
        Privilege privilege = getById(id);
        if (privilege == null) return false;

        boolean result = removeById(id);
        if (result) {
            // 清除关联菜单的缓存
            PrivilegeQuery query = new PrivilegeQuery();
            query.setMid(privilege.getMId());
            clearCache(query);
        }
        return result;
    }

    /*
     * 将查询结果存入Redis
     * */
    private void saveResultToRedis(String cacheKey, Page<PrivilegeDTO> dtoPage) { // 参数改为Page<PrivilegeDTO>
        HashOperations<String, Object, Object> hashOps = redisTemplate.opsForHash();
        hashOps.put(cacheKey, "total", dtoPage.getTotal());
        hashOps.put(cacheKey, "size", dtoPage.getSize());
        hashOps.put(cacheKey, "current", dtoPage.getCurrent());
        hashOps.put(cacheKey, "records", dtoPage.getRecords()); // 直接存储DTO列表
        redisTemplate.expire(cacheKey, CACHE_EXPIRE_TIME, TimeUnit.MINUTES);
    }
    /*
     * 生成缓存key
     * */
    private String generateCacheKey(PrivilegeQuery query) {
        StringBuilder keyBuilder = new StringBuilder();
        keyBuilder.append("mid:").append(query.getMid());

        if(query.getPid()!=null){
            keyBuilder.append(",pid:").append(query.getPid());
        }
        if(!StringUtils.isEmpty(query.getName())){
            keyBuilder.append(",name:").append(query.getName());
        }
        long pageIndex = query.getPageIndex() > 0 ? query.getPageIndex() : 1;
        long pageSize = query.getPageSize() > 0 ? query.getPageSize() : 10;
        keyBuilder.append(",page:").append(pageIndex).append(",pageSize:").append(pageSize);
        return keyBuilder.toString();
    }

    /*
     * 从缓存构建PageDTO
     * */
    private Page<PrivilegeDTO> buildPageDTOFromCache(Map<Object, Object> cacheMap, PrivilegeQuery query) { // 返回Page类型
        long total = Long.valueOf(cacheMap.get("total").toString());
        long current = Long.valueOf(cacheMap.get("current").toString());
        long size = Long.valueOf(cacheMap.get("size").toString());
        @SuppressWarnings("unchecked")
        List<PrivilegeDTO> records = (List<PrivilegeDTO>) cacheMap.get("records");
        if (records == null) { // 添加空值校验
            records = new ArrayList<>();
        }
        Page<PrivilegeDTO> page = new Page<>(current, size, total);
        page.setRecords(records);
        return page; // 直接返回Page对象
    }
    /*
     * 清除缓存
     * */
    public void clearCache(PrivilegeQuery query) {
        String cacheKeyPattern = PRIVILEGE_CACHE_KEY + "mid:" + query.getMid() + "*";
        Set<String> keys = redisTemplate.keys(cacheKeyPattern);

        if (keys != null && !keys.isEmpty()) {
            redisTemplate.delete(keys);
        }
    }

    /**
     * 根据 domain 查询商家名称（实时查询数据库）
     */
    private String getStoreTypeNameByDomain(String domain) {
        if (domain == null) return null;
        QueryWrapper<StoreType> wrapper = new QueryWrapper<>();
        wrapper.eq("store_type_cd", domain);
        StoreType storeType = storeTypeMapper.selectOne(wrapper);
        return storeType != null ? storeType.getName() : null;
    }
    /**
     * 根据 store_type.name 查询对应的 domain
     */
    private String getDomainByStoreTypeName(String storeTypeName) {
        if (storeTypeName == null) return null;
        QueryWrapper<StoreType> wrapper = new QueryWrapper<>();
        wrapper.eq("name", storeTypeName); // 查询条件：name = 前端传递的名称
        StoreType storeType = storeTypeMapper.selectOne(wrapper); // 执行查询
        log.info("getDomainByStoreType:{}", storeType);
        return storeType != null ? storeType.getStoreTypeCd() : null; // 返回对应的 domain

    }

}
