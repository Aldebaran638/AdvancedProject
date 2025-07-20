package com.zeroone.star.communitymanage.mapper.publicity;

import com.baomidou.mybatisplus.extension.plugins.pagination.Page;
import com.zeroone.star.project.dto.j5.community.publicity.PublicityDTO;
import com.zeroone.star.project.dto.j5.community.publicity.PublicityDetailDTO;
import com.zeroone.star.communitymanage.entity.publicity.CommunityPublicity;
import com.baomidou.mybatisplus.core.mapper.BaseMapper;
import org.apache.ibatis.annotations.Mapper;
import org.apache.ibatis.annotations.Param;

/**
 * <p>
 *  Mapper 接口
 * </p>
 *
 * @author wuguanfengyue
 * @since 2025-05-25
 */
@Mapper
public interface PublicityMapper extends BaseMapper<CommunityPublicity> {
    /**
     * 查询公示列表
     * @return 公示列表
     */
    Page<PublicityDTO> listPublicity(Page<?> page, @Param("communityId") String communityId,
                                        @Param("pubType") String pubType,
                                        @Param("title") String title);
    /**
     * 根据 pubId 和communityId查询单条公示详情
     * @param pubId 公示主键
     * @param communityId 小区id
     * @return 公示详情
     */
    PublicityDetailDTO getPublicityDetail(@Param("pubId") String pubId, @Param("communityId") String communityId);
}
