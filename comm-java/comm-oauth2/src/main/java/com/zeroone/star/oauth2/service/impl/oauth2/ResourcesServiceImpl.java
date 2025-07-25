package com.zeroone.star.oauth2.service.impl.oauth2;

import com.zeroone.star.oauth2.entity.Menu;
import com.zeroone.star.oauth2.entity.Store;
import com.zeroone.star.oauth2.service.IMenuService;
import com.zeroone.star.oauth2.service.IStoreService;
import com.zeroone.star.project.constant.RedisConstant;
import org.springframework.data.redis.core.RedisTemplate;
import org.springframework.stereotype.Service;

import javax.annotation.PostConstruct;
import javax.annotation.Resource;
import java.util.ArrayList;
import java.util.List;
import java.util.Map;
import java.util.TreeMap;

/**
 * <p>
 * 描述：资源与角色缓存初始化服务
 * </p>
 * <p>版权：&copy;01星球</p>
 * <p>地址：01星球总部</p>
 * @author 阿伟学长
 * @version 1.0.0
 */
@Service
public class ResourcesServiceImpl {
    @Resource
    private RedisTemplate<String, Object> redisTemplate;
    @Resource
    private IMenuService menuService;
    @Resource
    private IStoreService storeService;

    /**
     * 加载资源与角色缓存
     * @param isClearCacheBeforeLoad 加载前是否清除缓存
     */
    public void loadData(boolean isClearCacheBeforeLoad) {
        // 清除缓存
        if (isClearCacheBeforeLoad) {
            redisTemplate.delete(RedisConstant.RESOURCE_ROLES_MAP);
        }

        // 缓存权限资源逻辑：菜单路径与角色的映射关系
        // 定义缓存map
        Map<String, List<String>> resourceRolesMap = new TreeMap<>();
        // 1 获取所有菜单
        List<Menu> tMenus = menuService.listAllLinkUrl();
        tMenus.forEach(menu -> {
            // 2 获取菜单对应的角色
            List<Store> rolesMenu = storeService.listRoleByMenuPath(menu.getLinkUrl());
            List<String> roles = new ArrayList<>();
            rolesMenu.forEach(role -> roles.add(role.getName()));
            resourceRolesMap.put(menu.getLinkUrl(), roles);
        });

        // 将资源缓存到redis
        redisTemplate.opsForHash().putAll(RedisConstant.RESOURCE_ROLES_MAP, resourceRolesMap);
    }

    @PostConstruct
    public void init() {
        loadData(false);
    }
}
