package com.zeroone.star.communitymanage.mapper.parking;

import com.zeroone.star.communitymanage.entity.parking.ReportOweFee;
import com.baomidou.mybatisplus.core.mapper.BaseMapper;
import org.apache.ibatis.annotations.Mapper;
import org.apache.ibatis.annotations.Select;

/**
 * <p>
 *  Mapper 接口
 * </p>
 *
 * @author hh
 * @since 2025-05-30
 */
@Mapper
public interface ReportOweFeeMapper extends BaseMapper<ReportOweFee> {

    @Select("select * from report_owe_fee where payer_obj_name = '渝a13111-1停车场-16车位'")
    ReportOweFee listfee(String name);
}
