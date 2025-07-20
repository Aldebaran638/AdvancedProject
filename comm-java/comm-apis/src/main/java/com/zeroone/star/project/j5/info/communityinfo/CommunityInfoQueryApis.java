package com.zeroone.star.project.j5.info.communityinfo;

import com.zeroone.star.project.dto.PageDTO;
import com.zeroone.star.project.query.j5.info.communityinfo.CityAreaQuery;
import com.zeroone.star.project.query.j5.info.communityinfo.CommunityInfoQuery;
import com.zeroone.star.project.vo.JsonVO;
import com.zeroone.star.project.vo.j5.info.communityinfo.CityAreaVO;
import com.zeroone.star.project.vo.j5.info.communityinfo.CommunityInfoVO;
import com.zeroone.star.project.vo.j5.info.communityinfo.CommunityNameVO;

import java.util.List;


/**
 * <p>
 * 描述：小区信息接口
 *      yuezi : 获取小区列表（条件+分页）、获取未入驻物业的小区名称列表
 * </p>
 * @author yuezi
 * @version 1.0.0
 */
public interface CommunityInfoQueryApis {

    /**
     * 获取小区列表（条件+分页）接口
     * @param query 查询数据
     * @return 小区列表分页数据
     */
    JsonVO<PageDTO<CommunityInfoVO>> queryCommunityInfoList(CommunityInfoQuery query);

    /**
     * 获取未入驻物业的小区名称列表接口
     * @return 未入驻物业的小区名称
     */
    JsonVO<List<CommunityNameVO>> queryNotEnteredCommunityNameList();

    /**
     * 获取城市地名列表接口
     * @param query 小区信息查询数据查询模型
     * @return 城市地名信息列表
     */
    JsonVO<List<CityAreaVO>> queryCityAreas(CityAreaQuery query);

}
