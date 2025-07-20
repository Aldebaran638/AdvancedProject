package com.zeroone.star.dashboard.mapper;

import com.zeroone.star.dashboard.entity.SStore;
import com.baomidou.mybatisplus.core.mapper.BaseMapper;
import org.apache.ibatis.annotations.Mapper;

/**
 * <p>
 *  Mapper 接口
 * </p>
 *
 * @author fayff
 * @since 2025-05-21
 */
@Mapper
public interface SStoreMapper extends BaseMapper<SStore> {

    Integer getSStoreCount(long communityId);

}
