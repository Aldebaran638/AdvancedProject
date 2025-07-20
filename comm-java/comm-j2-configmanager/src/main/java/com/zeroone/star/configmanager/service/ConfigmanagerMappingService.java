package com.zeroone.star.configmanager.service;

import com.baomidou.mybatisplus.extension.service.IService;
import com.zeroone.star.project.dto.j2.configmanager.mappingdomain.AddConfigDTO;
import com.zeroone.star.project.dto.j2.configmanager.mappingdomain.ConfigDTO;

public interface ConfigmanagerMappingService extends IService<ConfigDTO> {
    /**
     * 添加配置项
     * @param addConfigDTO
     * @return
     */
    Boolean addConfig(AddConfigDTO addConfigDTO);
}
