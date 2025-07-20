package com.zeroone.star.dashboard.mapper;

import com.zeroone.star.dashboard.entity.PayFee;
import com.baomidou.mybatisplus.core.mapper.BaseMapper;
import org.apache.ibatis.annotations.Mapper;
import org.apache.ibatis.annotations.Select;

import java.util.List;
import java.util.Map;

/**
 * <p>
 *  Mapper 接口
 * </p>
 *
 * @author fayff
 * @since 2025-05-21
 */
@Mapper
public interface PayFeeMapper extends BaseMapper<PayFee> {

    /**
     * 优化查询：一次性获取所有小区的缴费统计数据
     * 使用JOIN避免N+1查询问题
     */
    @Select("SELECT " +
            "c.community_id, " +
            "c.name as community_name, " +
            "COUNT(DISTINCT pf.fee_id) as payment_count, " +
            "IFNULL(SUM(pfd.receivable_amount), 0) as payment_amount " +
            "FROM s_community c " +
            "LEFT JOIN pay_fee pf ON c.community_id = pf.community_id AND pf.status_cd = '0' " +
            "LEFT JOIN pay_fee_detail pfd ON pf.fee_id = pfd.fee_id AND pfd.status_cd = '0' " +
            "WHERE c.status_cd = '0' " +
            "GROUP BY c.community_id, c.name")
    List<Map<String, Object>> getCommunityPaymentStatistics();
}
