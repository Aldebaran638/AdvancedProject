package com.zeroone.star.communitymanage.mapper.building;

import com.zeroone.star.communitymanage.entity.building.FeeReceipt;
import com.baomidou.mybatisplus.core.mapper.BaseMapper;
import com.zeroone.star.project.dto.j5.community.building.FeeReceiptDTO;
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
public interface FeeReceiptMapper extends BaseMapper<FeeReceipt> {
    FeeReceiptDTO getFeeReceiptByRoomId(String roomId);
}
