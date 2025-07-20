package com.zeroone.star.communitymanage.mapper.property;

import com.baomidou.mybatisplus.core.mapper.BaseMapper;
import com.zeroone.star.project.dto.j5.community.property.PropertyPageDTO;
import com.zeroone.star.communitymanage.entity.property.PropertyRightRegistration;
import org.apache.ibatis.annotations.Mapper;

import java.util.List;
/**
 * <p>
 *     描述:房屋产权列表的mapper接口
 * </p>
 * @author sopoman
 * @version 1.0.0
 */

@Mapper
public interface PropertyRightRegistrationMapper extends BaseMapper<PropertyRightRegistration> {
    List<PropertyPageDTO> selectPropertyPage();

}