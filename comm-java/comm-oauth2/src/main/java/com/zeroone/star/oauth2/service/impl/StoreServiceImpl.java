package com.zeroone.star.oauth2.service.impl;

import com.baomidou.mybatisplus.extension.service.impl.ServiceImpl;
import com.zeroone.star.oauth2.entity.Store;
import com.zeroone.star.oauth2.mapper.StoreMapper;
import com.zeroone.star.oauth2.service.IStoreService;
import org.springframework.stereotype.Service;

import java.util.List;

@Service
public class StoreServiceImpl extends ServiceImpl<StoreMapper, Store> implements IStoreService {

    public List<Store> listRoleByUserId(int userId) {
        return baseMapper.selectRolesByUserId(userId);
    }

    @Override
    public List<Store> listRoleByMenuPath(String path) {
        return baseMapper.selectByMenuPath(path);
    }
}
