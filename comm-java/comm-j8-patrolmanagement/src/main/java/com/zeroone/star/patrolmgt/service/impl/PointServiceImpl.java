package com.zeroone.star.patrolmgt.service.impl;

import cn.hutool.core.bean.BeanUtil;
import com.baomidou.mybatisplus.core.conditions.query.LambdaQueryWrapper;
import com.baomidou.mybatisplus.extension.service.impl.ServiceImpl;
import com.zeroone.star.patrolmgt.entity.*;
import com.zeroone.star.patrolmgt.mapper.CommunityMapper;
import com.zeroone.star.patrolmgt.mapper.InspectionItemMapper;
import com.zeroone.star.patrolmgt.mapper.InspectionPointMapper;
import com.zeroone.star.patrolmgt.service.PointService;
import com.zeroone.star.project.j8.patrolmgt.point.dto.AddPointDTO;
import com.zeroone.star.project.vo.JsonVO;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Service;
import org.springframework.transaction.annotation.Transactional;

import javax.annotation.Resource;


@Service
public class PointServiceImpl extends ServiceImpl<InspectionPointMapper, Susu_InspectionPoint> implements PointService{
    @Resource
    private InspectionPointMapper inspectionPointMapper;
    @Resource
    private CommunityMapper communityMapper;
    @Autowired
    private InspectionItemMapper inspectionItemMapper;

    @Override
    @Transactional
    public JsonVO<String> savePoint(AddPointDTO addPointDTO) {
        // 判断小区id是否存在
        String communityId = addPointDTO.getCommunityId();
        LambdaQueryWrapper<RenYiFei_SCommunity> wrapper = new LambdaQueryWrapper<>();
        wrapper.eq(RenYiFei_SCommunity::getCommunityId,communityId);
        Long communityIdNum = communityMapper.selectCount(wrapper);
        if(communityIdNum!=1){
            return JsonVO.fail("失败");
        }

        //判断巡检项目是否存在（巡检项目和小区id共同作用）
        String itemId = addPointDTO.getItemId();
        LambdaQueryWrapper<InspectionItem> wrapperItem = new LambdaQueryWrapper<>();
        wrapperItem.eq(InspectionItem::getItemId,itemId).eq(InspectionItem::getCommunityId,communityId);
        Long itemNum = inspectionItemMapper.selectCount(wrapperItem);
        if(itemNum!=1){
            return JsonVO.fail("失败");
        }

        /**
         * 环境巡检参数设置
         */
        if(!("2002".equals(addPointDTO.getPointObjType())&&"-1".equals(addPointDTO.getPointObjId()))){
            return JsonVO.fail("失败");
        }

        Susu_InspectionPoint inspectionPoint = new Susu_InspectionPoint();
        BeanUtil.copyProperties(addPointDTO, inspectionPoint, false);
        int flag = inspectionPointMapper.insert(inspectionPoint);
        if(flag != 1){
            return JsonVO.fail("添加失败");
        }
        return JsonVO.success("添加成功");
    }
}
