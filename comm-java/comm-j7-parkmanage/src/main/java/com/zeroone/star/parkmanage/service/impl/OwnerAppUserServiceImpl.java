package com.zeroone.star.parkmanage.service.impl;

import com.baomidou.mybatisplus.core.conditions.query.QueryWrapper;
import com.zeroone.star.parkmanage.entity.OwnerAppUser;
import com.zeroone.star.parkmanage.entity.OwnerCar;
import com.zeroone.star.parkmanage.mapper.OwnerAppUserMapper;
import com.zeroone.star.parkmanage.service.IOwnerAppUserService;
import com.baomidou.mybatisplus.extension.service.impl.ServiceImpl;
import org.springframework.stereotype.Service;

/**
 * <p>
 * 服务实现类
 * </p>
 *
 * @author daimon
 * @since 2025-06-02
 */
@Service
public class OwnerAppUserServiceImpl extends ServiceImpl<OwnerAppUserMapper, OwnerAppUser> implements IOwnerAppUserService {

    @Override
    public String getUserName(String communityId, String memberId) {
        QueryWrapper<OwnerAppUser> queryWrapper = new QueryWrapper<>();
        queryWrapper.eq("community_id", communityId).eq("member_id", memberId);
        OwnerAppUser ownerAppUser = baseMapper.selectOne(queryWrapper);
        if (ownerAppUser == null) {
            return "";
        }
        return ownerAppUser.getAppUserName();
    }

    @Override
    public String getUserTel(String communityId, String memberId) {
        QueryWrapper<OwnerAppUser> queryWrapper = new QueryWrapper<>();
        queryWrapper.eq("community_id", communityId).eq("member_id", memberId);
        OwnerAppUser ownerAppUser = baseMapper.selectOne(queryWrapper);
        if (ownerAppUser == null) {
            return "";
        }
        return ownerAppUser.getLink();
    }
}
