package com.zeroone.star.communityinfo.mapper;

import com.baomidou.mybatisplus.core.mapper.BaseMapper;
import com.baomidou.mybatisplus.extension.plugins.pagination.Page;
import com.zeroone.star.communityinfo.entity.SCommunity;
import com.zeroone.star.project.vo.j5.info.communityinfo.CityAreaVO;
import com.zeroone.star.project.vo.j5.info.communityinfo.CommunityInfoVO;
import com.zeroone.star.project.vo.j5.info.communityinfo.CommunityNameVO;
import org.apache.ibatis.annotations.Param;

import java.util.List;


/**
 * <p>
 * 描述：小区信息查询的mapper接口
 * </p>
 * @author yuezi
 * @version 1.0.0
 */
public interface CommunityInfoMapper extends BaseMapper<SCommunity> {

    /**
     * 分页查询社区信息（含物业名称）
     */
    Page<CommunityInfoVO> selectCommunityWithProperty(
            @Param("page") Page<CommunityInfoVO> page,
            @Param("communityId") String communityId,
            @Param("cityCode") String cityCode,
            @Param("name") String name
    );

     /**
     * 获取未入驻物业的小区名称列表
     * @return 小区名称列表
     */
    List<CommunityNameVO> selectNotEnteredCommunityName();
}
