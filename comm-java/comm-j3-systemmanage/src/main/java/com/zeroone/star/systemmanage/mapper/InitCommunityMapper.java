package com.zeroone.star.systemmanage.mapper;

import com.baomidou.mybatisplus.core.mapper.BaseMapper;
import com.zeroone.star.project.query.j3.systemmanage.initcommunity.InitializedCommunityPageQuery;
import com.zeroone.star.systemmanage.entity.SCommunityDO;
import org.apache.ibatis.annotations.Mapper;

import java.util.List;

@Mapper
public interface InitCommunityMapper extends BaseMapper<SCommunityDO> {
    List<SCommunityDO> queryList(InitializedCommunityPageQuery query);
}
