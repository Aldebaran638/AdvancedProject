package com.zeroone.star.configmanager.service;

import com.zeroone.star.configmanager.entity.CMappingDO;
import com.baomidou.mybatisplus.extension.service.IService;
import com.zeroone.star.project.dto.PageDTO;
import com.zeroone.star.project.dto.j2.configmanager.config.ConfigAddDTO;
import com.zeroone.star.project.dto.j2.configmanager.config.ConfigDTO;
import com.zeroone.star.project.dto.j2.configmanager.config.ConfigUpdateDTO;
import com.zeroone.star.project.query.j2.configmanager.ConfigQuery;
import com.zeroone.star.project.vo.JsonVO;

/**
 * <p>
 *  服务类
 * </p>
 *
 * @author xq
 * @since 2025-05-24
 */
public interface ConfigManagerService extends IService<CMappingDO> {

    PageDTO<ConfigDTO> listAllConfig(ConfigQuery query);

    String saveConfig(ConfigAddDTO configAddDTO);

    String updateConfig(ConfigUpdateDTO configUpdateDTO);

    String deleteConfig(String id);
}
