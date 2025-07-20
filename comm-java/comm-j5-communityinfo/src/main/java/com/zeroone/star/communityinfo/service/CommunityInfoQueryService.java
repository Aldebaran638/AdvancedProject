package com.zeroone.star.communityinfo.service;

import com.zeroone.star.project.dto.PageDTO;
import com.zeroone.star.project.dto.j5.info.communityinfo.CommunityDTO;
import com.zeroone.star.project.query.j5.info.communityinfo.CityAreaQuery;
import com.zeroone.star.project.query.j5.info.communityinfo.CommunityInfoQuery;
import com.zeroone.star.project.vo.JsonVO;
import com.zeroone.star.project.vo.j5.info.communityinfo.CityAreaVO;
import com.zeroone.star.project.vo.j5.info.communityinfo.CommunityInfoVO;
import com.zeroone.star.project.vo.j5.info.communityinfo.CommunityNameVO;

import java.util.List;

/**
 * <p>
 * 描述：小区信息服务接口
 *      yuezi : 获取小区列表（条件+分页）、获取未入驻物业的小区名称列表
 * </p>
 * @author yuezi
 * @version 1.0.0
 */
public interface CommunityInfoQueryService {

    /**
     * 获取小区列表（条件+分页）
     * @param query 小区信息查询条件
     * @return 小区信息列表
     */
    public PageDTO<CommunityInfoVO> listCommunityInfo(CommunityInfoQuery query);

    /**
     * 获取未入驻物业的小区名称列表
     * @return 小区名称列表(含id信息)
     */
    public List<CommunityNameVO> ListNotEnteredCommunityNameWithNoCache();
    public List<CommunityNameVO> listNotEnteredCommunityNameWithCache();

    /**
     * 获取城市地名列表
     * @param query 城市地名查询条件
     * @return 城市地名列表
     */
    public List<CityAreaVO> listCityAreas(CityAreaQuery query);

}
