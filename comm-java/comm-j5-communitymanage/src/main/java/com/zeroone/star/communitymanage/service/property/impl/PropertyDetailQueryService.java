package com.zeroone.star.communitymanage.service.property.impl;

import com.baomidou.mybatisplus.core.conditions.query.QueryWrapper;
import com.baomidou.mybatisplus.extension.plugins.pagination.Page;
import com.baomidou.mybatisplus.extension.service.impl.ServiceImpl;
import com.zeroone.star.communitymanage.service.property.IPropertyDetailQueryService;
import com.zeroone.star.project.dto.PageDTO;
import com.zeroone.star.project.dto.j5.community.property.PropertyDetailDTO;
import com.zeroone.star.project.query.j5.community.property.PropertyDetailQuery;
import com.zeroone.star.communitymanage.entity.property.PropertyRightRegistrationDetail;
import com.zeroone.star.communitymanage.mapper.property.PropertyDetailQueryMapper;
import com.zeroone.star.communitymanage.mapper.property.PropertyRightRegistrationDetailMapper;
import org.springframework.stereotype.Service;

import javax.annotation.Resource;

/**
 * <p>
 * 描述：
 * </p>
 *
 * @author Jungle
 * @version 1.0.0
 */
@Service
public class PropertyDetailQueryService extends ServiceImpl<PropertyRightRegistrationDetailMapper, PropertyRightRegistrationDetail>
        implements IPropertyDetailQueryService {


    @Resource
    MsPropertyMapper ms;
    @Resource
    PropertyDetailQueryMapper propertyDetailQueryMapper;

    /**
     * 获取房屋产权详情
     *
     * @param query 房屋产权详情查询条件
     */
    public PageDTO<PropertyDetailDTO> listPropertyDetail(PropertyDetailQuery query)
    {
        //构建分页查询对象
        Page<PropertyRightRegistrationDetail> page=new Page<>(query.getPageIndex(),query.getPageSize());

        //构建查询条件
        //TODO 这个地方缺少图片显示
        QueryWrapper<PropertyRightRegistrationDetail> wrapper=new QueryWrapper<>();

        //只有有效的才会被查询到
        wrapper.eq("p.status_cd",0);
        wrapper.eq("p.prr_id",query.getPrrId());

        //获得查询结果
//        Page<PropertyRightRegistrationDetail> result=baseMapper.selectPage(page,wrapper);
         Page<PropertyRightRegistrationDetail> result= propertyDetailQueryMapper.selectById(page,wrapper);
        return  PageDTO.create(result, src -> ms.propertyRightRegistrationDetailToDTO(src));
    }
}
