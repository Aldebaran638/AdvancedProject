package com.zeroone.star.project.j8.patrolmgt.route;


import com.zeroone.star.project.j8.patrolmgt.route.dto.AddRouteDTO;
import com.zeroone.star.project.j8.patrolmgt.route.dto.RouteDTO;
import com.zeroone.star.project.vo.JsonVO;

import com.zeroone.star.project.dto.PageDTO;
import com.zeroone.star.project.j8.patrolmgt.route.dto.zhangyvsen_RouteDTO;
import com.zeroone.star.project.j8.patrolmgt.route.query.RouteNameQuery;
import com.zeroone.star.project.j8.patrolmgt.route.query.RouteQuery;
import com.zeroone.star.project.vo.JsonVO;

import java.util.List;

/**
 * <p>
 * 描述：巡检路线接口
 * </p>
 * <p>版权：&copy;01星球</p>
 * <p>地址：01星球总部</p>
 * @author Niu - 1,zhangyvsen - 2
 * @version 1.0.0
 */
public interface RouteApis {

    /**1
     * 添加巡检路线
     *
     * @param addRouteDTO 添加巡检路线数据对象
     * @return 返回添加成功的 id
     */
    JsonVO<String> addRoute(AddRouteDTO addRouteDTO);

    /**1
     * 修改巡检路线
     *
     * @param routeDTO 修改巡检路线数据对象
     * @return 修改结果：成功or失败
     */
    JsonVO<String> modifyRoute(RouteDTO routeDTO);

    /**1
     * 删除巡检路线
     * @param inspectionRouteId 巡检路线编号
     * @return 删除结果：成功or失败
     */
    JsonVO<String> removeRoute(String inspectionRouteId);

    /**2
     *分页查询巡检路线列表
     * @param query 查询对象 查询条件为空查询所有
     * @return 查询结果
     */
    JsonVO<PageDTO<zhangyvsen_RouteDTO>> queryRouteList(RouteQuery query);
    /**
     *按照名称查询巡检路线
     * @param
     * @return 查询结果
     */

    JsonVO<List<String>> queryRouteNameList(RouteNameQuery query);
}


