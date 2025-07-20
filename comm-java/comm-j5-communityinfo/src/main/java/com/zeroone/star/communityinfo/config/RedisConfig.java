package com.zeroone.star.communityinfo.config;

import com.fasterxml.jackson.annotation.JsonAutoDetect;
import com.fasterxml.jackson.annotation.PropertyAccessor;
import com.fasterxml.jackson.databind.ObjectMapper;
import com.zeroone.star.project.vo.j5.info.communityinfo.CommunityNameVO;
import org.springframework.cache.annotation.EnableCaching;
import org.springframework.context.annotation.Bean;
import org.springframework.context.annotation.ComponentScan;
import org.springframework.context.annotation.Configuration;
import org.springframework.data.redis.connection.RedisConnectionFactory;
import org.springframework.data.redis.core.RedisTemplate;
import org.springframework.data.redis.serializer.GenericJackson2JsonRedisSerializer;
import org.springframework.data.redis.serializer.Jackson2JsonRedisSerializer;
import org.springframework.data.redis.serializer.StringRedisSerializer;

import java.util.List;

/**
 * <p>
 * 描述：Redis配置
 * </p>
 * <p>版权：&copy;01星球</p>
 * <p>地址：01星球总部</p>
 *
 * @author yuezi
 * @version 1.0.0
 */
@Configuration
@EnableCaching
public class RedisConfig {

    @Bean("nameListRedisTemplate")
    public RedisTemplate<String, List<CommunityNameVO>> nameListRedisTemplate(RedisConnectionFactory redisConnectionFactory) {
        RedisTemplate<String, List<CommunityNameVO>> template = new RedisTemplate<>();
        template.setConnectionFactory(redisConnectionFactory);
        // 配置序列化器
        template.setKeySerializer(new StringRedisSerializer());
        template.setValueSerializer(new GenericJackson2JsonRedisSerializer());
        return template;
    }

    @Bean("nameListLockRedisTemplate")
    public RedisTemplate<String, String> nameListLockRedisTemplate(RedisConnectionFactory redisConnectionFactory) {
        RedisTemplate<String, String> template = new RedisTemplate<>();
        template.setConnectionFactory(redisConnectionFactory);
        // 配置序列化器
        template.setKeySerializer(new StringRedisSerializer());
        template.setValueSerializer(new StringRedisSerializer());
        return template;
    }
}
