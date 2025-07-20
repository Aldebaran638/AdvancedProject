package com.zeroone.star.oauth2.service.impl.oauth2;

import com.baomidou.mybatisplus.core.conditions.query.QueryWrapper;
import com.zeroone.cloud.oauth2.entity.SecurityUser;
import com.zeroone.cloud.starter.oauth2.service.LoadUserDetailService;
import com.zeroone.star.oauth2.entity.Store;
import com.zeroone.star.oauth2.entity.User;
import com.zeroone.star.oauth2.service.IStoreService;
import com.zeroone.star.oauth2.service.IUserService;
import org.springframework.security.core.userdetails.UsernameNotFoundException;
import org.springframework.stereotype.Service;

import javax.annotation.Resource;
import java.util.List;
import java.util.stream.Collectors;

/**
 * <p>
 * 描述：加载用户信息服务实现
 * </p>
 * <p>版权：&copy;01星球</p>
 * <p>地址：01星球总部</p>
 * @author 阿伟学长
 * @version 1.0.0
 */
@Service
public class LoadUserDetailServiceImpl implements LoadUserDetailService {
    @Resource
    IUserService userService;
    @Resource
    IStoreService storeService;

    @Override
    public SecurityUser loadUserDetailForMgr(String username) throws UsernameNotFoundException {
        // 1 通过用户名查找用户对象（从u_user表）
        User user = userService.getOne(new QueryWrapper<User>().eq("name", username));
        if (user == null) {
            throw new UsernameNotFoundException("用户名或密码错误");
        }
        
        // 2 通过用户ID获取角色列表（使用原有的角色查询逻辑）
        List<Store> roles = storeService.listRoleByUserId(Integer.parseInt(user.getUserId()));
        
        // 3 构建权限角色对象
        return SecurityUser.create(user, user.getUsername(), user.getPassword(), roles.stream().map(Store::getName).collect(Collectors.toList()));
    }

    @Override
    public SecurityUser loadUserDetailForUser(String username) throws UsernameNotFoundException {
        throw new UsernameNotFoundException("用户端查找用户尚未实现");
    }
}
