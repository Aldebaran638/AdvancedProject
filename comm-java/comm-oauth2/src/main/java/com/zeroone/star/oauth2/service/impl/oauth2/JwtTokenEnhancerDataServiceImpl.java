package com.zeroone.star.oauth2.service.impl.oauth2;

import com.baomidou.mybatisplus.core.conditions.query.QueryWrapper;
import com.zeroone.cloud.oauth2.entity.SecurityUser;
import com.zeroone.cloud.starter.oauth2.service.JwtTokenEnhancerDataService;
import com.zeroone.star.oauth2.entity.User;
import com.zeroone.star.oauth2.mapper.UserMapper;
import org.slf4j.Logger;
import org.slf4j.LoggerFactory;
import org.springframework.stereotype.Service;

import javax.annotation.Resource;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

/**
 * <p>
 * 描述：Jwt Token增强数据处理服务实现
 * </p>
 * <p>版权：&copy;01星球</p>
 * <p>地址：01星球总部</p>
 * @author 阿伟学长
 * @version 1.0.0
 */
@Service
public class JwtTokenEnhancerDataServiceImpl implements JwtTokenEnhancerDataService {

    private static final Logger log = LoggerFactory.getLogger(JwtTokenEnhancerDataServiceImpl.class);
    @Resource
    UserMapper userMapper;
    
    @Override
    public Map<String, Object> enhance(SecurityUser securityUser) {
        // 获取数据库用户DO对象（现在User实体映射到u_user表）
        User user = (User) securityUser.getExtendsObject();
        Map<String, Object> info = new HashMap<>(2);
        // FIXME: 如果要扩展凭证中的负载数据,需要修改这里的代码
        // 把用户业务ID（user_id）设置到JWT中
        info.put("id", user.getUserId());
        
        // 查询用户关联的商店ID列表
        List<String> storeIds = userMapper.selectStoreIdsByUserId(user.getUserId());
        if (storeIds != null && !storeIds.isEmpty()) {
            // 设置商店ID列表到JWT中
            log.warn(storeIds.toString());
            info.put("storeIds", storeIds);
        }
        
        return info;
    }
}
