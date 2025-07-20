package com.zeroone.star.communitymanage.mapper.property;

import com.baomidou.mybatisplus.core.conditions.query.QueryWrapper;
import com.baomidou.mybatisplus.core.mapper.BaseMapper;
import com.baomidou.mybatisplus.core.metadata.IPage;
import com.baomidou.mybatisplus.core.toolkit.Constants;
import com.baomidou.mybatisplus.extension.plugins.pagination.Page;
import com.zeroone.star.communitymanage.entity.property.PropertyRightRegistrationDetail;
import org.apache.ibatis.annotations.Mapper;
import org.apache.ibatis.annotations.Param;
import org.apache.ibatis.annotations.Select;


/**
 * <p>
 * 描述：
 * </p>
 *
 * @author Jungle
 * @version 1.0.0
 */
@Mapper
public interface PropertyDetailQueryMapper extends BaseMapper<PropertyRightRegistrationDetail> {


    // 查询是否存在记录（存在返回1，不存在返回null）
    @Select("SELECT count(*) FROM property_right_registration WHERE prr_id = #{id} LIMIT 1")
    Integer countById(String id);
    //获取相关的bId
    @Select("select b_id from business_property_right_registration" +
            " where prr_id =#{prrId}")
    String selectBidById(String prrId);

    @Select("select p.prrd_id,p.securities,p.is_true,f.file_real_name,p.create_time,p.status_cd from property_right_registration_detail p\n" +
            "INNER JOIN property_right_registration prr ON p.prr_id = prr.prr_id\n" +
            "INNER JOIN business_building_owner b ON prr.link = b.link\n" +
            "INNER JOIN file_rel f ON b.member_id = f.obj_id\n" +
            " ${ew.customSqlSegment}")//动态查询条件
    Page<PropertyRightRegistrationDetail> selectById(IPage<PropertyRightRegistrationDetail> page,
                                               @Param(Constants.WRAPPER) QueryWrapper<PropertyRightRegistrationDetail> wrapper);

}
