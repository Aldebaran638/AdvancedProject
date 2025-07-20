package com.zeroone.star.parkmanage.service.impl;

import cn.hutool.core.bean.BeanUtil;
import com.baomidou.mybatisplus.core.conditions.query.QueryWrapper;
import com.baomidou.mybatisplus.extension.plugins.pagination.Page;
import com.zeroone.star.parkmanage.entity.BusinessOwnerCar;
import com.zeroone.star.parkmanage.mapper.BusinessOwnerCarMapper;
import com.zeroone.star.parkmanage.service.IBusinessOwnerCarService;
import com.baomidou.mybatisplus.extension.service.impl.ServiceImpl;
import com.zeroone.star.parkmanage.service.IOwnerAppUserService;
import com.zeroone.star.project.dto.PageDTO;
import com.zeroone.star.project.dto.j7.parkmanage.ownervehicle.ModifyRecordDTO;
import com.zeroone.star.project.query.j7.parkmanage.ownervehicle.ModifyRecordQuery;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Service;

/**
 * <p>
 *  服务实现类
 * </p>
 *
 * @author daimon
 * @since 2025-06-02
 */
@Service
public class BusinessOwnerCarServiceImpl extends ServiceImpl<BusinessOwnerCarMapper, BusinessOwnerCar> implements IBusinessOwnerCarService {

    @Autowired
    IOwnerAppUserService ownerAppUserService;

    @Override
    public PageDTO<ModifyRecordDTO> listModifyRecord(ModifyRecordQuery query) {
        Page<BusinessOwnerCar> page = new Page<>(query.getPageIndex(), query.getPageSize());
        QueryWrapper<BusinessOwnerCar> wrapper = new QueryWrapper<>();
        wrapper.eq("car_id", query.getCarId()).eq("member_id",query.getMemberId());
        Page<BusinessOwnerCar> pageResult = baseMapper.selectPage(page, wrapper);

        return PageDTO.create(pageResult, businessOwnerCar -> {
            ModifyRecordDTO dto = new ModifyRecordDTO();
            BeanUtil.copyProperties(businessOwnerCar, dto);

            QueryWrapper<BusinessOwnerCar> queryWrapper = new QueryWrapper<>();
            queryWrapper.eq("car_id", query.getCarId()).eq("member_id",query.getMemberId());
            BusinessOwnerCar car = baseMapper.selectOne(queryWrapper);

            String communityId = car.getCommunityId();
            String memberId = query.getMemberId();
            dto.setUserName(ownerAppUserService.getUserName(communityId,memberId));
            dto.setUserTel(ownerAppUserService.getUserTel(communityId,memberId));

            return dto;
        });
    }
}
