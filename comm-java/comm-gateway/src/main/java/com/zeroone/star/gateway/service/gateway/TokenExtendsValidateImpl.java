package com.zeroone.star.gateway.service.gateway;

import com.zeroone.cloud.starter.gateway.service.TokenExtendsValidate;
import com.zeroone.star.project.constant.RedisConstant;
import org.springframework.data.redis.core.StringRedisTemplate;
import org.springframework.stereotype.Service;

import javax.annotation.Resource;

/**
 * <p>
 * 描述：这里实现注销凭证校验处理
 * </p>
 * <p>版权：&copy;01星球</p>
 * <p>地址：01星球总部</p>
 * @author 阿伟学长
 * @version 1.0.0
 */
@Service
public class TokenExtendsValidateImpl implements TokenExtendsValidate {

    @Resource
    private StringRedisTemplate stringRedisTemplate;

    @Override
    public boolean isLogout(String token) {
        // 判断凭证是否注销：如果Redis中没有对应的token记录或状态不是active，则认为已注销
        String tokenStatus = stringRedisTemplate.opsForValue().get(
                RedisConstant.LOGOUT_TOKEN_PREFIX + token
        );
        
        return tokenStatus == null || !"active".equals(tokenStatus);
    }
}
