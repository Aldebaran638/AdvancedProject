package com.zeroone.star.configmanager.service.impl;

import com.baomidou.mybatisplus.extension.service.impl.ServiceImpl;
import com.zeroone.star.configmanager.mapper.ConfigmanagerMappingMapper;
import com.zeroone.star.configmanager.service.ConfigmanagerMappingService;
import com.zeroone.star.project.dto.j2.configmanager.mappingdomain.AddConfigDTO;
import com.zeroone.star.project.dto.j2.configmanager.mappingdomain.ConfigDTO;
import org.springframework.beans.BeanUtils;
import org.springframework.stereotype.Service;

@Service
public class ConfigManagerMappingServiceImpl extends ServiceImpl<ConfigmanagerMappingMapper, ConfigDTO> implements ConfigmanagerMappingService{

    @Override
    public Boolean addConfig(AddConfigDTO addConfigDTO) {
        ConfigDTO configDTO=new ConfigDTO();
        BeanUtils.copyProperties(addConfigDTO,configDTO);
        return save(configDTO);
    }
}
