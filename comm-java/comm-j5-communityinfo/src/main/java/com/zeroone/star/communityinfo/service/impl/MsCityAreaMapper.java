package com.zeroone.star.communityinfo.service.impl;

import com.zeroone.star.communityinfo.entity.CityArea;
import com.zeroone.star.communityinfo.entity.SCommunity;
import com.zeroone.star.project.vo.j5.info.communityinfo.CityAreaVO;
import org.mapstruct.Mapper;

/**
 * <p>
 * 描述：城市区域 数据类型转换映射接口
 * </p>
 * @author yuezi
 * @version 1.0.0
 */
@Mapper(componentModel = "spring")
public interface MsCityAreaMapper {
    /**
     * 将实体类转换为CityArea
     * @param cityArea 城市实体类
     * @return 转换结果
     */
    CityAreaVO cityAreaToVO(CityArea cityArea);

}
