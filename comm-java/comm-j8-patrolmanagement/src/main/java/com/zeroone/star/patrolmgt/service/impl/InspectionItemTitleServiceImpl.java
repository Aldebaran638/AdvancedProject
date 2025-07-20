package com.zeroone.star.patrolmgt.service.impl;

import com.baomidou.mybatisplus.extension.service.impl.ServiceImpl;
import com.zeroone.star.patrolmgt.entity.TangSenQuan_InspectionItemTitle;
import com.zeroone.star.patrolmgt.mapper.InspectionItemTitleMapper;
import com.zeroone.star.patrolmgt.service.IInspectionItemTitleService;
import org.springframework.stereotype.Service;
import com.baomidou.mybatisplus.core.conditions.query.LambdaQueryWrapper;
import com.baomidou.mybatisplus.extension.plugins.pagination.Page;

import com.zeroone.star.patrolmgt.mapper.InspectionItemTitleMapper;
import com.zeroone.star.patrolmgt.service.IInspectionItemTitleService;
import com.baomidou.mybatisplus.extension.service.impl.ServiceImpl;
import com.zeroone.star.project.dto.PageDTO;
import com.zeroone.star.project.j8.patrolmgt.item.query.ItemTitleQuery;
import com.zeroone.star.project.j8.patrolmgt.item.vo.ItemTitleVO;
import org.springframework.stereotype.Service;
import org.springframework.util.StringUtils;

import javax.annotation.Resource;

/**
 * <p>
 *  服务实现类
 * </p>
 * @author panzhire
 */
@Service
public class InspectionItemTitleServiceImpl extends ServiceImpl<InspectionItemTitleMapper, TangSenQuan_InspectionItemTitle> implements IInspectionItemTitleService {

    @Resource
    MsInspectionItemTitleMapper ms;

    /**
     * 获取巡检题目列表（条件＋分页）
     *
     * @param query 查询条件
     * @return 查询结果
     */
    @Override
    public PageDTO<ItemTitleVO> queryItemTitleList(ItemTitleQuery query) {
        // 构建分页查询对象
        Page<TangSenQuan_InspectionItemTitle> page = new Page<>(query.getPageIndex(), query.getPageSize());

        // 构建查询条件
        LambdaQueryWrapper<TangSenQuan_InspectionItemTitle> wrapper = new LambdaQueryWrapper<>();

        wrapper.eq(TangSenQuan_InspectionItemTitle::getCommunityId, query.getCommunityId()) // 根据小区ID查询
                .eq(TangSenQuan_InspectionItemTitle::getItemId, query.getItemId())          // 根据巡检项目ID查询
                .eq(TangSenQuan_InspectionItemTitle::getStatusCd, "0")                 // 查询有效数据
                // 根据可选参数查询
                .eq(StringUtils.hasText(query.getTitleId()), TangSenQuan_InspectionItemTitle::getTitleId, query.getTitleId())
                .like(StringUtils.hasText(query.getItemTitle()), TangSenQuan_InspectionItemTitle::getItemTitle, query.getItemTitle())
                .eq(StringUtils.hasText(query.getTitleType()), TangSenQuan_InspectionItemTitle::getTitleType, query.getTitleType())
                .orderByAsc(TangSenQuan_InspectionItemTitle::getSeq)
                .orderByDesc(TangSenQuan_InspectionItemTitle::getCreateTime);

        // 执行查询
        Page<TangSenQuan_InspectionItemTitle> pageResult = baseMapper.selectPage(page, wrapper);

        // 转换返回
        return PageDTO.create(pageResult, itemTitle -> ms.itemTitleToVO(itemTitle));
    }
}
