package com.zeroone.star.configmanager.mapper;

import com.baomidou.mybatisplus.core.mapper.BaseMapper;
import com.zeroone.star.project.dto.j2.configmanager.mappingdomain.ConfigDTO;
import org.apache.ibatis.annotations.Mapper;

@Mapper
public interface ConfigmanagerMappingMapper extends BaseMapper<ConfigDTO> {
}
