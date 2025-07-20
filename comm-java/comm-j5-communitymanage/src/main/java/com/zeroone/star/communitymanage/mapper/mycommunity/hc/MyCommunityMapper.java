package com.zeroone.star.communitymanage.mapper.mycommunity.hc;

import com.baomidou.mybatisplus.core.mapper.BaseMapper;
import com.baomidou.mybatisplus.core.metadata.IPage;
import com.baomidou.mybatisplus.extension.plugins.pagination.Page;
import com.zeroone.star.communitymanage.entity.mycommunity.SCommunity;
import com.zeroone.star.project.vo.j5.community.mycommunity.AllMyCommunityVO;
import com.zeroone.star.project.vo.j5.community.mycommunity.MyCommunityVO;

import java.util.List;

public interface MyCommunityMapper extends BaseMapper<SCommunity> {

    IPage<MyCommunityVO> selectMyCommunity(Page<MyCommunityVO> page, String communityId, List<String> storeIds);

    IPage<AllMyCommunityVO> selectAllMyCommunity(Page<AllMyCommunityVO> page, String name, List<String> storeIds);
}
