package com.zeroone.star.communitymanage.mapper.building;

import com.zeroone.star.communitymanage.entity.building.TDict;
import com.baomidou.mybatisplus.core.mapper.BaseMapper;
import com.zeroone.star.project.dto.j5.community.building.TDictDTO;
import org.apache.ibatis.annotations.Mapper;

/**
 * <p>
 *  Mapper 接口
 * </p>
 *
 * @author langzi
 * @since 2025-05-23
 */
@Mapper
public interface TDictMapper extends BaseMapper<TDict> {
    /**
     * 根据状态查询状态名称
     * @param state
     * @return
     */
    TDictDTO getNameByState(String state);
}
