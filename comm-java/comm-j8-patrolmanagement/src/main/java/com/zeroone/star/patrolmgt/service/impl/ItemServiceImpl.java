package com.zeroone.star.patrolmgt.service.impl;

import cn.hutool.core.bean.BeanUtil;
import com.baomidou.mybatisplus.core.conditions.query.LambdaQueryWrapper;
import com.baomidou.mybatisplus.extension.service.impl.ServiceImpl;
import com.zeroone.star.patrolmgt.entity.InspectionItem;
import com.zeroone.star.patrolmgt.entity.RenYiFei_InspectionItem;
import com.zeroone.star.patrolmgt.entity.RenYiFei_SCommunity;
import com.zeroone.star.patrolmgt.mapper.CommunityMapper;
import com.zeroone.star.patrolmgt.mapper.InspectionItemMapper;
import com.zeroone.star.patrolmgt.service.ItemService;
import com.zeroone.star.project.j8.patrolmgt.item.dto.AddItemDTO;
import com.zeroone.star.project.j8.patrolmgt.item.dto.ItemDTO;
import com.zeroone.star.project.vo.JsonVO;
import org.springframework.stereotype.Service;
import org.springframework.transaction.annotation.Transactional;

import javax.annotation.Resource;

@Service
public class ItemServiceImpl extends ServiceImpl<InspectionItemMapper, InspectionItem> implements ItemService{
    @Resource
    private InspectionItemMapper inspectionItemMapper;
    @Resource
    private CommunityMapper communityMapper;
    @Override
    @Transactional//开启事务
    public JsonVO<String> saveItem(AddItemDTO addItemDTO) {
        String communityId = addItemDTO.getCommunityId();
        // 判断这个社区id是否在数据库中
        LambdaQueryWrapper<RenYiFei_SCommunity> wrapper = new LambdaQueryWrapper<>();
        wrapper.eq(RenYiFei_SCommunity::getCommunityId, communityId);
        Long communityIdNum = communityMapper.selectCount(wrapper);
        if(communityIdNum != 1){
            return JsonVO.fail("失败");
        }

        InspectionItem inspectionItem = new InspectionItem();
        BeanUtil.copyProperties(addItemDTO,inspectionItem,false);
        int result = inspectionItemMapper.insert(inspectionItem);
        if(result !=1){
            return JsonVO.fail("添加失败");
        }
        return JsonVO.success("添加成功");
    }

    @Override
    @Transactional
    public JsonVO<String> updateItem(ItemDTO itemDTO) {
        String communityId = itemDTO.getCommunityId();
        // 判断这个社区id是否在数据库中
        LambdaQueryWrapper<RenYiFei_SCommunity> wrapper = new LambdaQueryWrapper<>();
        wrapper.eq(RenYiFei_SCommunity::getCommunityId, communityId);
        Long communityIdNum = communityMapper.selectCount(wrapper);
        if(communityIdNum != 1){
            return JsonVO.fail("失败");
        }
        InspectionItem inspectionItem = new InspectionItem();
        BeanUtil.copyProperties(itemDTO,inspectionItem,false);
        int result = inspectionItemMapper.updateById(inspectionItem);
        if(result !=1){
            return JsonVO.fail("更新失败");
        }
        return JsonVO.success("更新成功");
    }

    @Override
    @Transactional
    public JsonVO<String> removeItem(String itemId) {
        int result = inspectionItemMapper.deleteById(itemId);
        if(result !=1){
            return JsonVO.fail("删除失败");
        }
        return JsonVO.success("删除成功");
    }
}
