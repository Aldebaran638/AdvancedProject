package com.zeroone.star.project.j2.configmanager;

import com.zeroone.star.project.dto.PageDTO;
import com.zeroone.star.project.dto.j2.configmanager.config.ConfigAddDTO;
import com.zeroone.star.project.dto.j2.configmanager.config.ConfigDTO;
import com.zeroone.star.project.dto.j2.configmanager.config.ConfigUpdateDTO;
import com.zeroone.star.project.query.j2.configmanager.ConfigQuery;
import com.zeroone.star.project.vo.JsonVO;


/**
 * 配置中心接口
 */
public interface ConfigManagerApis {

    /**
     * 查询配置项
     *
     * @param query 查询参数
     * @return 配置项列表
     */
    JsonVO<PageDTO<ConfigDTO>> queryConfig(ConfigQuery query);

    /**
     * 新增配置项
     *
     * @param configAddDTO 配置项信息
     * @return 添加结果
     */
    JsonVO<String> addConfig(ConfigAddDTO configAddDTO);

    /**
     * 修改配置项
     *
     * @param configUpdateDTO 配置项信息
     * @return 修改结果
     */
    JsonVO<String> updateConfig(ConfigUpdateDTO configUpdateDTO);

    /**
     * 删除配置项
     *
     * @param id 配置项ID
     * @return 删除结果
     */
    JsonVO<String> deleteConfig(String id);
}
