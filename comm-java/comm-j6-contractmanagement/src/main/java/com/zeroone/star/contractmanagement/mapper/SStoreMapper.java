package com.zeroone.star.contractmanagement.mapper;

import com.baomidou.mybatisplus.core.mapper.BaseMapper;
import com.zeroone.star.contractmanagement.entity.SStore;
import org.apache.ibatis.annotations.Mapper;
import org.apache.ibatis.annotations.Select;

/**
 * <p>
 *  Mapper 接口
 * </p>
 *
 * @author kunge
 * @since 2025-05-28
 */
@Mapper
public interface SStoreMapper extends BaseMapper<SStore> {
    @Select("select * from s_store where user_id=#{userId}")
    SStore selectByUserId(String userId);
}
