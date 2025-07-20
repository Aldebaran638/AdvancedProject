package com.zeroone.star.communitymanage.mapper.property;

import com.baomidou.mybatisplus.core.mapper.BaseMapper;
import com.zeroone.star.project.dto.PageDTO;
import com.zeroone.star.project.dto.j5.community.property.PropertyPageDTO;
import com.zeroone.star.communitymanage.entity.property.QueryCondition;
import org.apache.ibatis.annotations.Mapper;

@Mapper
public interface QueryConditionMapper extends BaseMapper<QueryCondition> {
    PageDTO<PropertyPageDTO> selectPropertyList();
}
