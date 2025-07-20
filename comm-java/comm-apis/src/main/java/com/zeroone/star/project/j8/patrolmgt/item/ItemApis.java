package com.zeroone.star.project.j8.patrolmgt.item;

import com.zeroone.star.project.dto.PageDTO;
import com.zeroone.star.project.j8.patrolmgt.item.dto.AddItemDTO;
import com.zeroone.star.project.j8.patrolmgt.item.dto.ItemDTO;
import com.zeroone.star.project.j8.patrolmgt.item.query.ItemQuery;
import com.zeroone.star.project.j8.patrolmgt.item.vo.ItemVO;
import com.zeroone.star.project.vo.JsonVO;

/**
 * <p>
 *  描述: 巡检项目接口
 * </p>1 - panzhire,2-renyifei
 */
public interface ItemApis {
    /**1
     * 获取巡检项目列表
     * @param communityId 查询数据对象
     * @return 查询结果
     */
    JsonVO<PageDTO<ItemVO>> listItem(String communityId);
    
    /**1
     * 分页查询巡检项目
     * @param query 查询数据对象
     * @return 查询结果
     */
    JsonVO<PageDTO<ItemVO>> queryItemList(ItemQuery query);

    /**2
     * 添加巡检项目
     * @param addItemDTO
     * @return
     */
    JsonVO<String> addItem(AddItemDTO addItemDTO);

    /**2
     * 修改巡检项目
     * @param itemDTO
     * @return
     */
    JsonVO<String> modifyItem(ItemDTO itemDTO);

    /**2
     * 删除巡检项目
     * @param ItemId
     * @return
     */
    JsonVO<String> removeItem(String ItemId);
}
