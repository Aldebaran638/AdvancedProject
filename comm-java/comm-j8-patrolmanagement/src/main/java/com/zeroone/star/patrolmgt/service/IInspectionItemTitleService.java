package com.zeroone.star.patrolmgt.service;

import com.baomidou.mybatisplus.extension.service.IService;
import com.zeroone.star.project.dto.PageDTO;
import com.zeroone.star.project.j8.patrolmgt.item.query.ItemTitleQuery;
import com.zeroone.star.project.j8.patrolmgt.item.vo.ItemTitleVO;
import com.baomidou.mybatisplus.extension.service.IService;
import com.zeroone.star.patrolmgt.entity.TangSenQuan_InspectionItemTitle;

/**
 * <p>
 *  服务类
 * </p>
 *
 * @author panzhire,tangsenquan
 * @since 2025-05-29
 */
public interface IInspectionItemTitleService extends IService<TangSenQuan_InspectionItemTitle> {

    PageDTO<ItemTitleVO> queryItemTitleList(ItemTitleQuery query);
}
