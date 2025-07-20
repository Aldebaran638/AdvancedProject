package com.zeroone.star.communitymanage.service.building;

import com.zeroone.star.communitymanage.entity.building.TDict;
import com.baomidou.mybatisplus.extension.service.IService;
import com.zeroone.star.project.dto.j5.community.building.TDictDTO;

/**
 * <p>
 *  服务类
 * </p>
 *
 * @author langzi
 * @since 2025-05-23
 */
public interface ITDictService extends IService<TDict> {
    TDictDTO getNameByState(String state);
}
