package com.zeroone.star.patrolmgt.mapper;

import com.baomidou.mybatisplus.core.mapper.BaseMapper;
import com.zeroone.star.patrolmgt.entity.Susu_TDict; // 确保TDict实体类已定义
import org.apache.ibatis.annotations.Mapper;

@Mapper
public interface TDictMapper extends BaseMapper<Susu_TDict> {
    // 通常不需要额外方法，BaseMapper 配合 QueryWrapper 够用
}