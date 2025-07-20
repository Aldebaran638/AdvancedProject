package com.zeroone.star.project.j8.patrolmgt.point;

import com.zeroone.star.project.dto.PageDTO;
import com.zeroone.star.project.j8.patrolmgt.point.query.RoutePointQuery;
import com.zeroone.star.project.j8.patrolmgt.point.dto.RoutePointDTO;
import com.zeroone.star.project.vo.JsonVO;

/**
 *描述：巡检路线巡检点查询接口
 *
 */

public interface RoutePointApis {
    /**
     * zhangyvsen
     * @param query 查询对象 当所有字段为空时，不查询数据
     * @return 查询结果
     */
    JsonVO<PageDTO<RoutePointDTO>> queryRoutePointList(RoutePointQuery query);

}

