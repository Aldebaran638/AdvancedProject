package com.zeroone.star.communitymanage.service.renovation.impl;

import com.zeroone.star.communitymanage.entity.renovation.RoomRenovationDetail;
import com.zeroone.star.communitymanage.mapper.renovation.RenovationDetailMapper;
import com.zeroone.star.communitymanage.service.renovation.IRenovationDetailService;
import com.baomidou.mybatisplus.extension.service.impl.ServiceImpl;
import org.springframework.stereotype.Service;

import javax.annotation.Resource;

/**
 * <p>
 *  服务实现类
 * </p>
 *
 * @author tianganwuzao
 * @since 2025-05-24
 */
@Service
public class RenovationDetailServiceImpl extends ServiceImpl<RenovationDetailMapper, RoomRenovationDetail> implements IRenovationDetailService {

    @Resource
    MsRecordDetailMapper  ms;


}
