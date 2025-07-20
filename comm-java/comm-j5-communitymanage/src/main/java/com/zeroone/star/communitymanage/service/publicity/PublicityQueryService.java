package com.zeroone.star.communitymanage.service.publicity;

import com.zeroone.star.project.dto.PageDTO;
import com.zeroone.star.project.dto.j5.community.publicity.PublicityDTO;
import com.zeroone.star.project.dto.j5.community.publicity.PublicityDetailDTO;
import com.zeroone.star.project.query.j5.community.publicity.PublicityDetailQuery;
import com.zeroone.star.project.query.j5.community.publicity.PublicityQuery;

/**
 * <p>
 *  服务类
 * </p>
 *
 * @author wuguanfengyue
 * @since 2025-05-25
 */
public interface PublicityQueryService {

    /**
     * 获取小区公示列表（条件+分页）
     * @param query 小区公示查询条件
     * @return 小区公示列表
     */
    PageDTO<PublicityDTO> listPublicity(PublicityQuery query);
    /**
     * 获取小区公示详情
     * @param query 小区公示详情查询条件
     * @return 小区公示详情
     */
    PublicityDetailDTO getPublicityDetail(PublicityDetailQuery query);
}
