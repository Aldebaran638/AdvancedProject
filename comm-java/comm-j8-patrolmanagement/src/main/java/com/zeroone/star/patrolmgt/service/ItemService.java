package com.zeroone.star.patrolmgt.service;


import com.baomidou.mybatisplus.extension.service.IService;
import com.zeroone.star.patrolmgt.entity.InspectionItem;
import com.zeroone.star.patrolmgt.entity.RenYiFei_InspectionItem;
import com.zeroone.star.project.j8.patrolmgt.item.dto.AddItemDTO;
import com.zeroone.star.project.j8.patrolmgt.item.dto.ItemDTO;
import com.zeroone.star.project.vo.JsonVO;

public interface ItemService extends IService<InspectionItem> {
    JsonVO<String> saveItem(AddItemDTO addItemDTO);
    JsonVO<String> updateItem(ItemDTO itemDTO);
    JsonVO<String> removeItem(String itemId);
}
