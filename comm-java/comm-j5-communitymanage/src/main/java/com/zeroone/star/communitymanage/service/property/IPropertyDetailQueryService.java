package com.zeroone.star.communitymanage.service.property;

import com.zeroone.star.project.dto.PageDTO;
import com.zeroone.star.project.dto.j5.community.property.PropertyDetailDTO;
import com.zeroone.star.project.query.j5.community.property.PropertyDetailQuery;

/**
 * <p>
 * 描述：
 * </p>
 *
 * @author Jungle
 * @version 1.0.0
 */
public interface IPropertyDetailQueryService {
    /**
     * 获取房屋产权详情
     *
     * @param query 房屋产权详情查询条件
     * @return 房屋产权详情
     */
    public PageDTO<PropertyDetailDTO> listPropertyDetail(PropertyDetailQuery query);

}
