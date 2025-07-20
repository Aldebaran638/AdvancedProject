package com.zeroone.star.communitymanage.service.building.impl;

import com.zeroone.star.communitymanage.entity.building.TDict;
import com.zeroone.star.communitymanage.mapper.building.TDictMapper;
import com.zeroone.star.communitymanage.service.building.ITDictService;
import com.baomidou.mybatisplus.extension.service.impl.ServiceImpl;
import com.zeroone.star.project.dto.j5.community.building.TDictDTO;
import org.springframework.stereotype.Service;

import javax.annotation.Resource;

/**
 * <p>
 *  服务实现类
 * </p>
 *
 * @author langzi
 * @since 2025-05-23
 */
@Service
public class TDictServiceImpl extends ServiceImpl<TDictMapper, TDict> implements ITDictService {

    @Resource
    TDictMapper tDictMapper;
    @Override
    public TDictDTO getNameByState(String state) {
        return tDictMapper.getNameByState(state);
    }
}
