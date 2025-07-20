package com.zeroone.star.project.j2.configmanager;

import com.zeroone.star.project.dto.PageDTO;
import com.zeroone.star.project.dto.j2.configmanager.mappingdomain.AddConfigDTO;
import com.zeroone.star.project.dto.j2.configmanager.mappingdomain.ConfigDTO;
import com.zeroone.star.project.dto.j2.configmanager.mappingdomain.MappingDomainDTO;
import com.zeroone.star.project.dto.j2.configmanager.mappingdomain.MappingDomainNameDTO;
import com.zeroone.star.project.query.j2.configmanager.MappingDomainQuery;
import com.zeroone.star.project.vo.JsonVO;

import java.util.List;

/**
 * 配置项接口
 */
public interface MappingDomainApis {

    /**
     * 根据传入条件分页查询配置项并排序
     * @param query 查询条件
     * @return 查询结果
     */
    JsonVO<PageDTO<MappingDomainDTO>> queryAll(MappingDomainQuery query);

    /**
     * 查询所有的配置项名称
     */
    JsonVO<List<MappingDomainNameDTO>> queryAllName();

    /**
     * 添加配置项
     *
     * @param addConfigDTO 添加配置项数据对象
     * @return 添加结果
     */
    JsonVO<Boolean> addConfig(AddConfigDTO addConfigDTO);

    /**
     * 修改配置项
     *
     * @param configDTO 修改配置项数据对象
     * @return 修改结果
     */
    JsonVO<Boolean> modifyConfig(ConfigDTO configDTO);

    /**
     * 删除配置项
     *
     * @param id 配置项编号
     * @return 删除结果
     */
    JsonVO<Boolean> removeConfig(String id);

}
