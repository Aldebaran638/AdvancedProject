package com.zeroone.star.patrolmgt.service.impl;

import com.baomidou.mybatisplus.core.conditions.query.LambdaQueryWrapper;
import com.baomidou.mybatisplus.extension.plugins.pagination.Page;
import com.zeroone.star.patrolmgt.entity.InspectionItem;
import com.zeroone.star.patrolmgt.mapper.InspectionItemMapper;
import com.zeroone.star.patrolmgt.service.IInspectionItemService;
import com.baomidou.mybatisplus.extension.service.impl.ServiceImpl;
import com.zeroone.star.project.dto.PageDTO;
import com.zeroone.star.project.j8.patrolmgt.item.query.ItemQuery;
import com.zeroone.star.project.j8.patrolmgt.item.vo.ItemVO;
import org.springframework.stereotype.Service;
import org.springframework.util.StringUtils;

import javax.annotation.Resource;

/**
 * <p>
 * 服务实现类
 * </p>
 * @author panzhire
 */
@Service
public class InspectionItemServiceImpl extends ServiceImpl<InspectionItemMapper, InspectionItem> implements IInspectionItemService {

    @Resource
    MsInspectionItemMapper ms;

    @Override
    public PageDTO<ItemVO> listItem(String communityId) {
        // 构建分页对象(使用默认分页参数 第1页 每页10条)
        Page<InspectionItem> page = new Page<>(1, 10);

        // 构建查询条件
        LambdaQueryWrapper<InspectionItem> wrapper = new LambdaQueryWrapper<>();
        wrapper.eq(InspectionItem::getCommunityId, communityId) // 根据小区ID查询
                .eq(InspectionItem::getStatusCd, "0")   // 只查询有效数据
                .orderByDesc(InspectionItem::getCreateTime); // 按创建时间降序

        // 查询
        Page<InspectionItem> pageResult = baseMapper.selectPage(page, wrapper);

        // 转为 VO
        return PageDTO.create(pageResult, item -> ms.itemToVo(item));
    }

    @Override
    public PageDTO<ItemVO> queryItemList(ItemQuery query) {
        // 构建分页查询对象
        Page<InspectionItem> page = new Page<>(query.getPageIndex(), query.getPageSize());

        // 构建查询条件
        LambdaQueryWrapper<InspectionItem> wrapper = new LambdaQueryWrapper<>();
        wrapper.eq(InspectionItem::getCommunityId, query.getCommunityId()) // 根据小区ID查询
                .eq(InspectionItem::getStatusCd, "0") // 过滤无效数据
                // 是否根据巡检项目id查询
                .eq(StringUtils.hasText(query.getItemId()), InspectionItem::getItemId, query.getItemId())
                // 是否根据巡检项目名称查询
                .like(StringUtils.hasText(query.getItemName()), InspectionItem::getItemName, query.getItemName())
                // 排序
                .orderByDesc(InspectionItem::getCreateTime);

        // 执行查询
        Page<InspectionItem> pageResult = baseMapper.selectPage(page, wrapper);

        // 转换返回
        return PageDTO.create(pageResult, item -> ms.itemToVo(item));
    }
}
