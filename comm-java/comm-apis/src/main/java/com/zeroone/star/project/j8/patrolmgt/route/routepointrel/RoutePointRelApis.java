package com.zeroone.star.project.j8.patrolmgt.route.routepointrel;

import com.zeroone.star.project.j8.patrolmgt.route.dto.routepointrel.RemoveRoutePointDTO;
import com.zeroone.star.project.j8.patrolmgt.route.dto.routepointrel.RoutePointRelModifyImagesDTO;
import com.zeroone.star.project.j8.patrolmgt.route.dto.routepointrel.AddRoutePointRelListDTO;
import com.zeroone.star.project.vo.JsonVO;

import java.util.List;

public interface RoutePointRelApis {


    //新可增巡检路线巡检点
    JsonVO<List<String>> addRoutePointRelList(List<AddRoutePointRelListDTO> addRoutePointRelListDTO);

    // 根据传入的RoutePointRelImagesDTO对象，修改对应的路巡检点的，并返回修改后的JsonVO<String>对象
    JsonVO<String>  modifyRoutePointRelImages(RoutePointRelModifyImagesDTO routePointRelModifyImagesDTO);
    //根据传入的RoutePointRelImagesDTO对象，删除对应的路巡检点的，并返回删除后的JsonVO<String>对象
    JsonVO<String>removeRoutePointRelImages(RemoveRoutePointDTO removeInspectionId);


}
