package com.zeroone.star.project.j8.patrolmgt.item;

import com.zeroone.star.project.dto.PageDTO;
import com.zeroone.star.project.j8.patrolmgt.item.query.ItemTitleQuery;
import com.zeroone.star.project.j8.patrolmgt.item.vo.ItemTitleVO;
import com.zeroone.star.project.vo.JsonVO;

/**
 * <p>
 *  描述: 查询巡检题目接口
 * </p>
 * @author  panzhire
 * @version 1.0.0
 */
public interface ItemTitleApis {
    /**
     * 获取巡检题目列表（条件＋分页）
     * @param query 查询数据对象
     * @return      查询结果
     */
    JsonVO<PageDTO<ItemTitleVO>> queryItemTitleList(ItemTitleQuery query);
}
