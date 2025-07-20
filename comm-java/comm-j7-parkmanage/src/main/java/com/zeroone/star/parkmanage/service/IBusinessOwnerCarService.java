package com.zeroone.star.parkmanage.service;

import com.zeroone.star.parkmanage.entity.BusinessOwnerCar;
import com.baomidou.mybatisplus.extension.service.IService;
import com.zeroone.star.project.dto.PageDTO;
import com.zeroone.star.project.dto.j7.parkmanage.ownervehicle.ModifyRecordDTO;
import com.zeroone.star.project.query.j7.parkmanage.ownervehicle.ModifyRecordQuery;

/**
 * <p>
 *  服务类
 * </p>
 *
 * @author daimon
 * @since 2025-06-02
 */
public interface IBusinessOwnerCarService extends IService<BusinessOwnerCar> {

    PageDTO<ModifyRecordDTO> listModifyRecord(ModifyRecordQuery query);
}
