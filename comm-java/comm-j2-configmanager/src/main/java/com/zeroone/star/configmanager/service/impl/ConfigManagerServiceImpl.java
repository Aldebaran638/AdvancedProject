package com.zeroone.star.configmanager.service.impl;

import com.alibaba.excel.util.StringUtils;
import com.baomidou.mybatisplus.core.conditions.query.LambdaQueryWrapper;
import com.baomidou.mybatisplus.extension.plugins.pagination.Page;
import com.zeroone.star.configmanager.entity.CMappingDO;
import com.zeroone.star.configmanager.mapper.ConfigManagerMapper;
import com.zeroone.star.configmanager.service.ConfigManagerService;
import com.baomidou.mybatisplus.extension.service.impl.ServiceImpl;
import com.zeroone.star.project.dto.PageDTO;
import com.zeroone.star.project.dto.j2.configmanager.config.ConfigAddDTO;
import com.zeroone.star.project.dto.j2.configmanager.config.ConfigDTO;
import com.zeroone.star.project.dto.j2.configmanager.config.ConfigUpdateDTO;
import com.zeroone.star.project.query.j2.configmanager.ConfigQuery;
import org.mapstruct.Mapper;
import org.springframework.stereotype.Service;

import javax.annotation.Resource;

/**
 * <p>
 *  服务实现类
 * </p>
 *
 * @author xq
 * @since 2025-05-24
 */
@Mapper(componentModel = "spring")
interface MsConfigManagerMapper{
    /**
     * DO转DTO
     * @param cMappingDO
     * @return
     */
    ConfigDTO cMappingDOToConfigDTO(CMappingDO cMappingDO);

    /**
     * AddDTO转DO
     * @param configAddDTO
     * @return
     */
    CMappingDO ConfigAddDTOToCMappingDO(ConfigAddDTO configAddDTO);

    /**
     * UpdateDTO转DO
     * @param configUpdateDTO
     * @return
     */
    CMappingDO ConfigUpdateDTOToCMappingDO(ConfigUpdateDTO configUpdateDTO);
}

@Service
public class ConfigManagerServiceImpl extends ServiceImpl<ConfigManagerMapper, CMappingDO> implements ConfigManagerService {

    @Resource
    private MsConfigManagerMapper ms;
    @Resource
    private ConfigManagerMapper configManagerMapper;

    /**
     * 根据查询条件 返回结果
     *
     * @param query
     * @return
     */
    @Override
    public PageDTO<ConfigDTO> listAllConfig(ConfigQuery query) {
        Page<CMappingDO> page = new Page<CMappingDO>(query.getPageIndex(),query.getPageSize());
        LambdaQueryWrapper<CMappingDO> wrapper = new LambdaQueryWrapper<>();
        wrapper.like(StringUtils.isNotBlank(query.getKey()), CMappingDO::getKey,query.getKey())
                .like(StringUtils.isNotBlank(query.getName()), CMappingDO::getName,query.getName());
        Page<CMappingDO> cMappingPage = baseMapper.selectPage(page, wrapper);
        return PageDTO.create(cMappingPage,cMappingDO->{
                    return ms.cMappingDOToConfigDTO(cMappingDO);
        });
    }

    /**
     * 添加配置
     *
     * @param configAddDTO
     * @return
     */
    @Override
    public String saveConfig(ConfigAddDTO configAddDTO) {
        if(nameAndKeyIsRepeat(configAddDTO.getName(),configAddDTO.getKey())){
            return "2";
        }
        boolean save = save(ms.ConfigAddDTOToCMappingDO(configAddDTO));
        if(save==true){
            return "1";
        }
        return "0";
    }

    /**
     * 判断配置名与配置键是否重复
     * @param name
     * @param key
     * @return
     */
    private boolean nameAndKeyIsRepeat(String name, String key) {
        LambdaQueryWrapper<CMappingDO> eq = new LambdaQueryWrapper<CMappingDO>()
                .eq(CMappingDO::getName, name)
                .eq(CMappingDO::getKey, key);
        return count(eq)>0;
    }

    /**
     * 修改配置
     *
     * @param configUpdateDTO
     * @return
     */
    @Override
    public String updateConfig(ConfigUpdateDTO configUpdateDTO) {
        boolean u = updateById(ms.ConfigUpdateDTOToCMappingDO(configUpdateDTO));
        if(u==true){
            return "1";
        }
        return "0";
    }

    /**
     * 删除配置
     *
     * @param id
     * @return
     */
    @Override
    public String deleteConfig(String id) {
        boolean delete = removeById(id);
        if(delete==true){
            return "1";
        }
        return "0";
    }
}
