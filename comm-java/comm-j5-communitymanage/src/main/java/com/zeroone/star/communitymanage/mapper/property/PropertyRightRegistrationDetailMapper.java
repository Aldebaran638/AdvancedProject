package com.zeroone.star.communitymanage.mapper.property;

import com.baomidou.mybatisplus.core.mapper.BaseMapper;
import com.zeroone.star.project.dto.j5.community.property.PropertyDetailDTO;
import com.zeroone.star.communitymanage.entity.property.PropertyRightRegistrationDetail;
import org.apache.ibatis.annotations.Mapper;

import java.util.List;

@Mapper
public interface PropertyRightRegistrationDetailMapper extends BaseMapper<PropertyRightRegistrationDetail> {
    List<PropertyDetailDTO> selectPropertyDetail();

}
