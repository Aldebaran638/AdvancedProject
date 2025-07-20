package com.zeroone.star.communitymanage.service.parking.impl;

import com.zeroone.star.communitymanage.mapper.building.BuildingUnitMapper;
import com.zeroone.star.communitymanage.entity.building.BuildingUnit;
import com.zeroone.star.communitymanage.service.parking.IBuildingUnitService;
import com.baomidou.mybatisplus.extension.service.impl.ServiceImpl;
import com.zeroone.star.project.query.j5.community.parking.ParkingQuery;
import org.springframework.stereotype.Service;

import javax.annotation.Resource;

/**
 * <p>
 *  服务实现类
 * </p>
 *
 * @author hh
 * @since 2025-05-23
 */
@Service
public class BuildingUnit4PServiceImpl extends ServiceImpl<BuildingUnitMapper, BuildingUnit> implements IBuildingUnitService {


    @Resource
    private BuildingUnitMapper buildingUnitMapper;

    @Resource
    private MsMapper msBuildingUnitMapper;

    /**
     * 获取单元编号
     * @param query
     * @return
     */
    @Override
    public BuildingUnit getunitnum(ParkingQuery query) {
        //类型转换成buildingunit实体类
       BuildingUnit buildingUnit = msBuildingUnitMapper.toBuildingUnit(query);

       BuildingUnit unit =  buildingUnitMapper.listunitnum(buildingUnit);
       return unit;
    }
}
