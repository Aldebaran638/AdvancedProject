package com.zeroone.star.dashboard.mapper;

import com.zeroone.star.dashboard.entity.Complaint;
import com.baomidou.mybatisplus.core.mapper.BaseMapper;
import org.apache.ibatis.annotations.Mapper;
import org.apache.ibatis.annotations.Select;

import java.util.List;

/**
 * <p>
 *  Mapper 接口
 * </p>
 *
 * @author fayff
 * @since 2025-05-21
 */
@Mapper
public interface ComplaintMapper extends BaseMapper<Complaint> {


    @Select("SELECT complaint_id , state FROM complaint WHERE community_id = #{communityId}")
    List<Complaint> selectAll(String communityId);

}
