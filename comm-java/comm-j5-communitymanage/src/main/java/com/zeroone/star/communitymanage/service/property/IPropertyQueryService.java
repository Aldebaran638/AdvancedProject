package com.zeroone.star.communitymanage.service.property;


import com.zeroone.star.project.dto.PageDTO;
import com.zeroone.star.project.dto.j5.community.property.PropertyPageDTO;
import com.zeroone.star.project.query.j5.community.property.PropertyQuery;

/**
 *<p>
 * 描述：房屋产权服务接口
 *      supoman : 获取房屋产权列表（条件+分页）、获取房屋产权详情
 *</p>
 * @author supoman
 * @version 1.0.0
 */

public interface IPropertyQueryService  {
    /**
     * 获取房屋产权列表（条件+分页）
     * @param query 房屋产权列表查询条件
     * @return 房屋产权列表
     */
    public PageDTO<PropertyPageDTO> listPropertyPage(PropertyQuery query);


}
