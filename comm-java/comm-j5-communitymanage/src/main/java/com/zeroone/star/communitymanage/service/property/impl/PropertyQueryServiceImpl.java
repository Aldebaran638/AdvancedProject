package com.zeroone.star.communitymanage.service.property.impl;

import com.alibaba.cloud.commons.lang.StringUtils;
import com.baomidou.mybatisplus.core.conditions.query.QueryWrapper;
import com.baomidou.mybatisplus.extension.plugins.pagination.Page;
import com.baomidou.mybatisplus.extension.service.impl.ServiceImpl;
import com.zeroone.star.communitymanage.service.property.IPropertyQueryService;
import com.zeroone.star.project.dto.PageDTO;
import com.zeroone.star.project.dto.j5.community.property.PropertyPageDTO;
import com.zeroone.star.project.query.j5.community.property.PropertyQuery;
import com.zeroone.star.communitymanage.entity.property.PropertyRightRegistration;
import com.zeroone.star.communitymanage.mapper.property.PropertyQueryMapper;
import com.zeroone.star.communitymanage.mapper.property.PropertyRightRegistrationMapper;

import org.springframework.stereotype.Service;

import javax.annotation.Resource;

/**
 *<p>
 * 描述：房屋产权服务接口
 *      supoman : 获取房屋产权列表（条件+分页）、获取房屋产权详情
 *</p>
 * @author supoman
 * @version 1.0.0
 */
@Service
public class PropertyQueryServiceImpl
        extends ServiceImpl<PropertyRightRegistrationMapper,PropertyRightRegistration>
        implements IPropertyQueryService {
    @Resource
    PropertyQueryMapper propertyQueryMapper;

    @Resource
    MsPropertyMapper ms;


    @Override
    public PageDTO<PropertyPageDTO> listPropertyPage(PropertyQuery query) {

        //构建分页查询对象
        Page<PropertyRightRegistration> page=new Page<>(query.getPageIndex(),query.getPageSize());

        //构建查询条件
        QueryWrapper<PropertyRightRegistration> wrapper=new QueryWrapper<>();
        wrapper.like(StringUtils.isNotBlank(query.getName()),"name",query.getName())
                .eq(query.getRoomId() != null,"prr.room_id",query.getRoomId())
                .eq(StringUtils.isNotBlank(query.getRoomNum()),"room_num",query.getRoomNum());
        //获得查询结果
        Page<PropertyRightRegistration> result=propertyQueryMapper.selectWithRoomNum(page,wrapper);
        return  PageDTO.create(result, src -> ms.propertyRightRegistrationToDTO(src));

    }
}
