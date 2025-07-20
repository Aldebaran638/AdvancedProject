package com.zeroone.star.patrolmgt.service;

import com.zeroone.star.patrolmgt.entity.InspectionItem;
import com.baomidou.mybatisplus.extension.service.IService;
import com.zeroone.star.project.dto.PageDTO;
import com.zeroone.star.project.j8.patrolmgt.item.query.ItemQuery;
import com.zeroone.star.project.j8.patrolmgt.item.vo.ItemVO;

/**
 * <p>
 *  服务类
 * </p>
 *
 * @author panzhire
 * @since 2025-05-29
 */
public interface IInspectionItemService extends IService<InspectionItem> {
    
    /**
     * 获取巡检项目名称列表
     * @param communityId 查询条件
     * @return  查询结果
     */
    PageDTO<ItemVO> listItem(String communityId);
    
    /**
     * 获取巡检项目列表（条件＋分页）
     * @param query 查询条件
     * @return  查询结果
     */
    PageDTO<ItemVO> queryItemList(ItemQuery query);
}
