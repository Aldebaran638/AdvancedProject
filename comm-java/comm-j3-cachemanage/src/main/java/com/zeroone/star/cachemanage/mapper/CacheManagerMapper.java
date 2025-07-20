package com.zeroone.star.cachemanage.mapper;

import com.baomidou.mybatisplus.core.mapper.BaseMapper;
import com.baomidou.mybatisplus.extension.plugins.pagination.Page;
import com.zeroone.star.cachemanage.entity.CCacheDO;
import com.zeroone.star.project.query.j3.cachemanage.CacheQuery;
import org.apache.ibatis.annotations.Mapper;
import org.apache.ibatis.annotations.Param;

@Mapper
public interface CacheManagerMapper extends BaseMapper<CCacheDO> {
    Page<CCacheDO> selectAllCaches(@Param("page")Page<CCacheDO> page,CacheQuery cacheQuery);
}
