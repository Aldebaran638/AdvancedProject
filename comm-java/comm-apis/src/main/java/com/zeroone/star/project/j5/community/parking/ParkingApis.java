package com.zeroone.star.project.j5.community.parking;

import com.zeroone.star.project.query.j5.community.parking.ParkingQuery;
import com.zeroone.star.project.vo.JsonVO;
import com.zeroone.star.project.vo.j5.community.parking.ParkingVO;

import java.util.List;

/**
 * <p>
 * 描述：车位结构图接口
 *      . :  获取指定单元车位结构————并待命协助其他组员未完成的接口与数据定义
 * </p>
 * @author hh
 * @version 1.0.0
 */
public interface ParkingApis {

    /**
     * 获取车位结构图接口
     * @param query 接受前面传的数据
     * @return
     */
    public JsonVO<List<ParkingVO>> queryParking(ParkingQuery query);

}
