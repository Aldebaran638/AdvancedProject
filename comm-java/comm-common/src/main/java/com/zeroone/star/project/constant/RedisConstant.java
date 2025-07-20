package com.zeroone.star.project.constant;

/**
 * <p>
 * 描述：Redis相关常量
 * </p>
 * <p>版权：&copy;01星球</p>
 * <p>地址：01星球总部</p>
 *
 * @author 阿伟学长
 * @version 1.0.0
 */
public interface RedisConstant {
    /**
     * 角色资源映射Map的key
     */
    String RESOURCE_ROLES_MAP = "AUTH:RESOURCE_ROLES";

    /**
     * 注销token的key前缀
     */
    String LOGOUT_TOKEN_PREFIX = "AUTH:LOGOUT_TOKEN:";

    /**
     * 验证码的key前缀
     */
    String CAPTCHA_PREFIX = "AUTH:CAPTCHA:";
    /**
     * 平台统计数据缓存键前缀
     */
    String CACHE_PLATFORM_STATISTICS = "db:platform:statistics";
    
    /**
     * 小区缴费统计数据缓存键前缀
     */
    String CACHE_COMMUNITY_PAYMENT = "db:community:payment";
    
    /**
     * 小区报修统计数据缓存键前缀
     */
    String CACHE_COMMUNITY_REPAIR = "db:community:repair";}
