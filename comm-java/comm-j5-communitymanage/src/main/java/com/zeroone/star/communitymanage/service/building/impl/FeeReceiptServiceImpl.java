package com.zeroone.star.communitymanage.service.building.impl;

import com.zeroone.star.communitymanage.entity.building.FeeReceipt;
import com.zeroone.star.communitymanage.mapper.building.FeeReceiptMapper;
import com.zeroone.star.communitymanage.service.building.IFeeReceiptService;
import com.baomidou.mybatisplus.extension.service.impl.ServiceImpl;
import com.zeroone.star.project.dto.j5.community.building.FeeReceiptDTO;
import org.springframework.stereotype.Service;

import javax.annotation.Resource;

/**
 * <p>
 *  服务实现类
 * </p>
 *
 * @author langzi
 * @since 2025-05-23
 */
@Service
public class FeeReceiptServiceImpl extends ServiceImpl<FeeReceiptMapper, FeeReceipt> implements IFeeReceiptService {

    @Resource
    FeeReceiptMapper feeReceiptMapper;

    @Override
    public FeeReceiptDTO getFeeReceiptByRoomId(String roomId) {
        return feeReceiptMapper.getFeeReceiptByRoomId(roomId);
    }
}
