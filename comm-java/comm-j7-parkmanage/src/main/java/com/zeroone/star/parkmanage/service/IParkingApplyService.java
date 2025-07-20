package com.zeroone.star.parkmanage.service;

import com.zeroone.star.parkmanage.entity.ParkingApply;
import com.baomidou.mybatisplus.extension.service.IService;
import com.zeroone.star.project.dto.PageDTO;
import com.zeroone.star.project.dto.j7.parkmanage.parkingapply.AddApplyDTO;
import com.zeroone.star.project.dto.j7.parkmanage.parkingapply.ApplyDTO;
import com.zeroone.star.project.query.j7.parkmanage.parkingapply.GetParkingApplyQuery;

/**
 * <p>
 * 车位申请记录表 服务类
 * </p>
 *
 * @author zhangjiaqi
 * @since 2025-05-25
 */
public interface IParkingApplyService extends IService<ParkingApply> {



    /**
     * 获取申请列表（分页+条件）
     *
     * @param query 查询条件
     * @return 申请列表
     */
    PageDTO<ApplyDTO> queryParkingApplyQuery(GetParkingApplyQuery query,String id, String apply_person_name, String car_Brand);

}
