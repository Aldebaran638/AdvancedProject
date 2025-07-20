package com.zeroone.star.patrolmgt.service;

import com.zeroone.star.patrolmgt.entity.yuxixia_DO;
import com.baomidou.mybatisplus.extension.service.IService;
import com.zeroone.star.project.j8.patrolmgt.route.dto.routepointrel.RemoveRoutePointDTO;
import com.zeroone.star.project.j8.patrolmgt.route.dto.routepointrel.RoutePointRelModifyImagesDTO;
import com.zeroone.star.project.j8.patrolmgt.route.dto.routepointrel.AddRoutePointRelListDTO;
import com.zeroone.star.project.vo.JsonVO;
import org.springframework.stereotype.Service;

import java.util.List;

/**
 * <p>
 *  服务类
 * </p>
 *
 * @author 阿伟
 * @since 2025-05-20
 */
@Service
public interface RoutePointRelService extends IService<yuxixia_DO> {

// 分页查询并添加可加入巡检路线点
    public JsonVO<List<String>>addRoutePointRelListService(List<AddRoutePointRelListDTO> addRoutePointRelListDTO);
// 修改巡检点的信息
    public JsonVO<String> modifyRoutePointRelService(RoutePointRelModifyImagesDTO routePointRelModifyImagesDTO);

    public JsonVO<String> removeRoutePointRelService(RemoveRoutePointDTO removeInspectionId);

}
