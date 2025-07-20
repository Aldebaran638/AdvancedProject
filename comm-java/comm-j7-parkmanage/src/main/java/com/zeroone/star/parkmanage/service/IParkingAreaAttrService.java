package com.zeroone.star.parkmanage.service;

import com.zeroone.star.parkmanage.entity.ParkingAreaAttr;
import com.baomidou.mybatisplus.extension.service.IService;

/**
 * <p>
 *  服务类
 * </p>
 *
 * @author wuven
 * @since 2025-05-26
 */
public interface IParkingAreaAttrService extends IService<ParkingAreaAttr> {

    String getOutNum(String padId);

}
