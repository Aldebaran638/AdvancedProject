package com.zeroone.star.communitymanage.service.publicity.impl;

import com.baomidou.mybatisplus.extension.plugins.pagination.Page;
import com.zeroone.star.communitymanage.service.publicity.PublicityQueryService;
import com.zeroone.star.project.dto.PageDTO;
import com.zeroone.star.project.dto.j5.community.publicity.PublicityDTO;
import com.zeroone.star.project.dto.j5.community.publicity.PublicityDetailDTO;
import com.zeroone.star.project.query.j5.community.publicity.PublicityDetailQuery;
import com.zeroone.star.project.query.j5.community.publicity.PublicityQuery;
import com.zeroone.star.communitymanage.entity.publicity.CommunityPublicity;
import com.zeroone.star.communitymanage.mapper.publicity.PublicityMapper;
import org.springframework.stereotype.Service;
import com.zeroone.star.communitymanage.mapper.publicity.msPublicityMapper;
import javax.annotation.Resource;

/**
 * <p>
 *  服务实现类
 * </p>
 *
 * @author wuguanfengyue
 * @since 2025-05-25
 */
@Service
public class PublicityQueryServiceImpl  implements PublicityQueryService {
    @Resource
    private PublicityMapper publicityMapper;
    @Resource
    private msPublicityMapper msPublicityMapper;

    @Override
    public PageDTO<PublicityDTO> listPublicity(PublicityQuery query) {

        Page<CommunityPublicity> page = new Page<>(query.getPageIndex(), query.getPageSize());

        return PageDTO.create(
                publicityMapper.listPublicity(page, query.getCommunityId(), query.getPubType(), query.getTitle())
        );
    }

    @Override
    public PublicityDetailDTO getPublicityDetail(PublicityDetailQuery query)
    {
        return publicityMapper.getPublicityDetail(query.getPubId(), query.getCommunityId());
    }
}
