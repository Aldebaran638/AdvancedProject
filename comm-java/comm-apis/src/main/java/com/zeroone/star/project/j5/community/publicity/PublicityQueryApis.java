package com.zeroone.star.project.j5.community.publicity;

import com.zeroone.star.project.dto.PageDTO;

import com.zeroone.star.project.dto.j5.community.publicity.PublicityDTO;
import com.zeroone.star.project.dto.j5.community.publicity.PublicityDetailDTO;
import com.zeroone.star.project.query.j5.community.publicity.PublicityDetailQuery;
import com.zeroone.star.project.query.j5.community.publicity.PublicityQuery;
import com.zeroone.star.project.vo.JsonVO;

import java.util.List;

/**
 * <p>
 * 描述：小区公示接口
 *      无关风月：获取公示列表（条件+分页）、获取公示详情
 * </p>
 * @author 无关风月
 * @version 1.0.0
 */
public interface PublicityQueryApis {
    /**
     * 获取公示列表
     *
     * @param query 查询条件
     * @return 公示列表
     */
    JsonVO<PageDTO<PublicityDTO>> queryPublicityList(PublicityQuery query);
    /**
     * 获取公示详情
     *
     * @param query 查询条件
     * @return 公示详情
     */
    JsonVO<PublicityDetailDTO> queryPublicityDetail(PublicityDetailQuery query);
}
