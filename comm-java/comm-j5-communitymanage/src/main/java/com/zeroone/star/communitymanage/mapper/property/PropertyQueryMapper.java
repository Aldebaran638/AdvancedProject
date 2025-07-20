package com.zeroone.star.communitymanage.mapper.property;

import com.baomidou.mybatisplus.core.conditions.query.QueryWrapper;
import com.baomidou.mybatisplus.core.mapper.BaseMapper;
import com.baomidou.mybatisplus.core.metadata.IPage;
import com.baomidou.mybatisplus.core.toolkit.Constants;
import com.baomidou.mybatisplus.extension.plugins.pagination.Page;
import com.zeroone.star.communitymanage.entity.property.PropertyRightRegistration;
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
public interface PropertyQueryMapper extends BaseMapper<PropertyRightRegistration> {
    // 使用 @Select 注解编写关联查询
    @Select("SELECT prr.prr_id,prr.room_id,prr.name,prr.address,prr.link,prr.id_card,prr.state, r.room_num " +
            "FROM property_right_registration prr " +
            "LEFT JOIN building_room r ON prr.room_id = r.room_id " +
            "${ew.customSqlSegment}") // 动态条件
    Page<PropertyRightRegistration> selectWithRoomNum(
            IPage<PropertyRightRegistration> page,
            @Param(Constants.WRAPPER) QueryWrapper<PropertyRightRegistration> wrapper
    );
}
